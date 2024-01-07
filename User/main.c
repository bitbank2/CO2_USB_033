//
// Pocket CO2 Sensor
// by Larry Bank (bitbank@pobox.com)
//
// Uses the CH32X033 TSSOP20 MCU
// Project started January 6, 2024
// Copyright (c) 2024 BitBank Software, Inc.
//
#include "debug.h"

#define CH32X035
#define BITBANG
#include "../../libraries/ch32v_hal.inl"
#include "../../libraries/spi_lcd.inl"
#include "../../libraries/scd41.inl"
#include "Roboto_Black_40.h"
#include "battery.h"

#define LED_PIN 0xb7
#define POWER_PIN 0xb1
#define LCD_BL 0xa6
#define CS_PIN 0xa4
#define RST_PIN 0xa3
#define DC_PIN 0xa2
#define BATTBUTT_PIN 0xa1
#define VBUS_PIN 0xa9
#define SDA_PIN 0xab
#define SCL_PIN 0xaa

uint16_t usBG, usFG;
int iBattery, iBrightness;

void SetBrightness(uint8_t u8ccp)
{
    TIM_OCInitTypeDef TIM_OCInitStructure={0};

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = u8ccp;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init( TIM3, &TIM_OCInitStructure );
} /* SetBrightness() */

void TIM3_PWMOut_Init(u16 arr, u16 psc, u16 ccp)
{
    uint8_t u8Pin;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure={0};

    RCC->APB2PCENR |= RCC_APB2Periph_GPIOA;
    RCC->APB1PCENR |= RCC_APB1Periph_TIM3;

    u8Pin = (LCD_BL & 0xf); // needed for backlight brightness
    GPIOA->CFGLR &= ~(0xf<<(4*u8Pin));
    GPIOA->CFGLR |= (GPIO_Speed_50MHz | GPIO_Mode_AF_PP)<<(4*u8Pin);

    TIM_TimeBaseInitStructure.TIM_Period = arr;
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit( TIM3, &TIM_TimeBaseInitStructure);

    SetBrightness(ccp);
    TIM_CtrlPWMOutputs(TIM3, ENABLE );
    TIM_OC1PreloadConfig( TIM3, TIM_OCPreload_Disable );
    TIM_ARRPreloadConfig( TIM3, ENABLE );
    TIM_Cmd( TIM3, ENABLE );
} /* TIM3_PWMOut_Init() */

// Convert a number into a zero-terminated string
int i2str(char *pDest, int iVal)
{
        char *d = pDest;
        int i, iPlaceVal = 10000;
        int iDigits = 0;

        if (iVal < 0) {
                iDigits++;
                *d++ = '-';
                iVal = -iVal;
        }
        while (iPlaceVal) {
                if (iVal >= iPlaceVal) {
                        i = iVal / iPlaceVal;
                        *d++ = '0' + (char)i;
                        iVal -= (i*iPlaceVal);
                        iDigits++;
                } else if (iDigits != 0) {
                        *d++ = '0'; // non-zeros were already displayed
                }
                iPlaceVal /= 10;
        }
        if (d == pDest) // must be zero
                *d++ = '0';
        *d++ = 0; // terminator
        return (int)(d - pDest - 1); // string length
} /* i2str() */

void ShowLogo(void)
{
    lcdWriteString(26,0,"CO2 ", COLOR_GREEN, COLOR_BLACK, FONT_12x16);
    lcdWriteString(-1,-1,"Micro", COLOR_WHITE, COLOR_BLACK, FONT_12x16);
    lcdWriteString(8,24,"Portable CO2", COLOR_CYAN, COLOR_BLACK, FONT_12x16);
    lcdWriteString(44,40,"Sensor", COLOR_CYAN, COLOR_BLACK, FONT_12x16);
    lcdWriteString(28,64,"Starting...", COLOR_YELLOW, COLOR_BLACK, FONT_8x8);
} /* ShowLogo() */

void PowerDown(void)
{
	lcdFill(0);
	lcdWriteString(8,0,"Powering Off", COLOR_RED, 0, FONT_12x16);
	lcdWriteString(14,32,"Release the", 0xfe40, 0, FONT_12x16);
	lcdWriteString(14,48,"button when", 0xfe40, 0, FONT_12x16);
	lcdWriteString(32,64,"ready...", 0xfe40, 0, FONT_12x16);
	digitalWrite(POWER_PIN, 0); // shut off power to LDO
	while (1) {};
} /* PowerDown() */

void ShowCO2(void)
{
	int i, x, iColor;
	char szTemp[32];
	uint8_t *s;
	uint32_t rem;
	static int iOldLen = 0;
    const uint16_t usColors[7] = {0x7e0, 0x67e0, 0xffe0, 0xfe40, 0xfbc0, 0xf800, 0xffff};

    i = i2str(szTemp, (int)_iCO2);
    if (i != iOldLen) { // if the number of digits of CO2 changes, repaint everything
        lcdFill(usBG);
        iOldLen = i;
    }
    i = _iCO2 - 500;
    if (i < 0) i = 0;
    iColor = udivmod32(i, 250, NULL);
    if (iColor > 5) iColor = 5; // show with a color
    lcdWriteStringCustom(&Roboto_Black_40, 0, 32, szTemp, usColors[iColor], usBG, 1);
    x = lcdGetCursorX();
    lcdWriteString(x, 2, "CO2", usColors[iColor], usBG, FONT_8x8);
    lcdWriteString(x, 10, "ppm", usColors[iColor], usBG, FONT_8x8);

    lcdWriteString(0, 36, "Temp ", usFG, usBG, FONT_12x16);
    i = _iTemperature/10;
    rem = _iTemperature % 10;
    i2str(szTemp, i); // whole part
    szTemp[2] = '.';
    szTemp[3] = '0' + rem; // fraction
    szTemp[4] = 'C';
    szTemp[5] = 0;
    lcdWriteString(100, 36, szTemp, usFG, usBG, FONT_12x16);
    lcdWriteString(0, 52, "Humidity ", usFG, usBG, FONT_12x16);
    i2str(szTemp, _iHumidity/10); // throw away fraction since it's not accurate
    lcdWriteString(100, 52, szTemp, usFG, usBG, FONT_12x16);
    lcdWriteString(124, 52, "%", usFG, usBG, FONT_12x16);
    // show battery level
	if (digitalRead(VBUS_PIN) == 1|| (iBattery > 3000 && iBattery <4096)) { // valid values, otherwise no battery measurement
		   if (digitalRead(VBUS_PIN) == 1) {
			   s = (uint8_t *)battchg_32x16; // charging
			   iColor = 6; // white
		   } else if (iBattery <= 3220) {
				s = (uint8_t *)batt0_32x16; // <= 3.4v
				iColor = 5; // red
			} else if (iBattery <= 3407) {
				s = (uint8_t *)batt0_32x16; // <= 3.6v
				iColor = 4;
			} else if (iBattery < 3609) {
				s = (uint8_t *)batt25_32x16; // <= 3.8v
				iColor = 3;
			} else if (iBattery < 3711) {
				s = (uint8_t *)batt50_32x16; // <= 3.9v
				iColor = 2;
			} else if (iBattery < 3795) {
				s = (uint8_t *)batt75_32x16; // <= 4.0v
				iColor = 1;
			} else {
				s = (uint8_t *)batt100_32x16;
				iColor = 0;
			}
			lcdDrawPattern(s, 4, 128, 0, 32, 16, 0, usColors[iColor]);
	}
} /* ShowCO2() */

void ShowCountdown(int iSecs)
{
uint32_t i, rem;
char szTemp[8];

    szTemp[0] = '0';
    i = udivmod32(iSecs, 60, &rem);
    szTemp[1] = i +'0';
    szTemp[2] = ':';
    szTemp[3] = udivmod32(rem, 10, &rem) + '0';
    szTemp[4] = rem + '0';
    szTemp[5] = 0;
    lcdWriteStringCustom(&Roboto_Black_40, 10, 56, szTemp, usFG, usBG, 1);
} /* ShowCountdown() */

void RunCalibrate(void)
{
int i;

    lcdFill(usBG);
    lcdWriteString(2,2,"Calibrating..", usFG, usBG, FONT_12x16);
//    while (GetButtons() != 0) {};
//   scd41_start(SCD_POWERMODE_NORMAL);
   // allow 3 minutes of normal collection
   for (i=210; i>=0; i--) {
      ShowCountdown(i);
//      j = GetButtons();
//      if (j == 3) { // user quit
//              scd41_stop();
//              return;
//      }
      Delay_Ms(1000);
   }
   scd41_stop(); // stop periodic measurement
   i = scd41_recalibrate(423); // force recalibration
   lcdWriteString(2,32, (i == SCD_SUCCESS) ? "Success!":"Failed", (i == SCD_SUCCESS) ? COLOR_GREEN:COLOR_RED, usBG, FONT_12x16);
   lcdWriteString(0,72, "Press button to exit", usFG, usBG, FONT_8x8);
   i = 0;
   while (digitalRead(BATTBUTT_PIN) == 0 && i < 3000) {
         Delay_Ms(20);
         i++;
   }
   if (i >= 3000) { // user left it sitting there, turn off
	   PowerDown();
   }
   scd41_start(SCD_POWERMODE_NORMAL); // restart the sensor
   lcdFill(usBG);
} /* RunCalibrate() */

void RunLowPower(void)
{
	int iTick, iHold, iShutdown;

	scd41_stop();
	scd41_start(SCD_POWERMODE_LOW); // switch to low pwoer mode
	SetBrightness(254); // turn off backlight
	iTick = iHold = 0;
	iShutdown = 120*60*8; // auto shutdown after 2 hours
	while (1) {
		if (digitalRead(BATTBUTT_PIN)) { // user pressed the button
			iHold++;
			if (iHold >= 8) { // exit mode
				SetBrightness(iBrightness);
				scd41_stop();
				scd41_start(SCD_POWERMODE_NORMAL);
				return;
			}
		} else if (iHold) { // press+release, show stats
			iHold = 0;
    		scd41_getSample();
    		SetBrightness(iBrightness);
    		ShowCO2(); // display the current conditions on the OLED
    		Delay_Ms(1500);
    		SetBrightness(254);
		}
		iTick++;
		iShutdown--;
		if (iShutdown == 0) {
			PowerDown(); // automatically shut off after 2 hours
		}
	} // while !bDone
} /* RunLowPower() */
void ADCInit(void)
{
    ADC_InitTypeDef  ADC_InitStructure = {0};
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    //RCC_ADCCLKConfig(RCC_PCLK2_Div8);
    ADC_CLKConfig(ADC1, ADC_CLK_Div8);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; // A1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    ADC_DeInit(ADC1);
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigInjecConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    //ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADC1, &ADC_InitStructure);

//    ADC_InjectedChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_241Cycles);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_11Cycles);
 //   ADC_Calibration_Vol(ADC1, ADC_CALVOL_75PERCENT);
//    ADC_ITConfig(ADC1, ADC_IT_AWD, ENABLE);
//    ADC_AutoInjectedConvCmd(ADC1, ENABLE);
    ADC_Cmd(ADC1, ENABLE);

//    ADC_ResetCalibration(ADC1);
//    while(ADC_GetResetCalibrationStatus(ADC1));
 //   ADC_StartCalibration(ADC1);
 //   while(ADC_GetCalibrationStatus(ADC1));

} /* ADCInit() */

uint16_t ADCGetValue(void)
{
    uint16_t val;

    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
//    Delay_Ms(100);
//    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));

    val = ADC_GetConversionValue(ADC1);
    //val = ADC_GetInjectedConversionValue(ADC1, ADC_InjectedChannel_1);
    return val;
} /* ADCGetValue() */

void RunMenu(void)
{
	int iItem = 0, bDone = 0;
	int iTick, iTimeout;
	const char *szMenuItem[] = {"Calibrate", "Low Power", "Power Off", "Exit Menu"};

menu_start:
	lcdFill(0);
	lcdWriteString(14,0,"Option Menu", COLOR_CYAN, 0, FONT_12x16);
	lcdWriteString(20,64,"Press to change", COLOR_YELLOW, 0, FONT_8x8);
	lcdWriteString(0,72,"Press+hold to select", COLOR_YELLOW, 0, FONT_8x8);
	iTick = iTimeout = 0;
	lcdWriteString(26,32,szMenuItem[iItem], COLOR_WHITE, 0, FONT_12x16);
	while (!bDone) {
		if (digitalRead(BATTBUTT_PIN)) {
			lcdWriteString(26,32,szMenuItem[iItem], COLOR_WHITE, 0, FONT_12x16); // flash menu item when changing
			iTick++;
			iTimeout = 0;
			if (iTick >= 8) {
				for (iTick = 0; iTick < 3; iTick++) {
					lcdWriteString(26,32,szMenuItem[iItem], COLOR_WHITE, 0, FONT_12x16); // flash menu item when changing
					Delay_Ms(250);
					lcdWriteString(26,32,szMenuItem[iItem], COLOR_WHITE, COLOR_BLUE, FONT_12x16);
					Delay_Ms(250);
				}
				switch (iItem) {
				case 0: // calibrate
					RunCalibrate();
				    scd41_start(SCD_POWERMODE_NORMAL); // start in normal mode again
				    goto menu_start;
					break;
				case 1: // low power
					RunLowPower();
					goto menu_start;
					break;
				case 2: // Power Off
					PowerDown();
					break;
				case 3: // exit
					bDone = 1;
					lcdFill(0);
		    		while (digitalRead(BATTBUTT_PIN) == 1) {}; // wait for user to release button from menu selection
					ShowCO2();
					break;
				} // switch
			} // long press
		} else { // button release
			if (iTick) { // button was pressed and released
				iTick = 0;
				iItem++;
				if (iItem >= 4) iItem = 0;
				lcdWriteString(26,32,szMenuItem[iItem], COLOR_WHITE, 0, FONT_12x16); // show new item
			}
		}
		iTimeout++;
        if (iTimeout > 8*60) {
        	// The user forgot about us for > 1 minute, turn ourselves off
        	digitalWrite(POWER_PIN, 0);
        }
		Delay_Ms(156);
	} // while !bDone
} /* RunMenu() */

int main(void)
{
    int i, iHold, iShutdown, iTick;
    int iOrientation = 0;
    uint8_t ucTemp[32];

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    SetClock(48000000); // DEBUG
    Delay_Init();
    ADCInit();
    iBattery = 0;
    iTick = 0;
    while (iBattery < 800 && iTick < 100) { // wait for a valid read
    	iBattery = ADCGetValue(); // get battery voltage at startup
    	iTick++;
    	Delay_Ms(1); // it takes a few ms for the value to rise to it's true amount
    }
	ADC_DeInit(ADC1);
    pinMode(BATTBUTT_PIN, INPUT);

    pinMode(LED_PIN, OUTPUT);
    pinMode(POWER_PIN, OUTPUT);
    pinMode(VBUS_PIN, INPUT_PULLDOWN);
    digitalWrite(POWER_PIN, 1);
    I2CInit(SDA_PIN, SCL_PIN, 100000);
    iBrightness = 230;
    TIM3_PWMOut_Init( 255, 512, iBrightness ); // start a 20% duty cycle PWM output on D4 of about 512hz

//    pinMode(LCD_BL, OUTPUT);
//	digitalWrite(LCD_BL, 1);
    lcdInit(LCD_ST7735S_80x160, 24000000, CS_PIN, DC_PIN, RST_PIN, 0/*BL_PIN*/, 0, 0);
    lcdWriteCMD(0x21); // inverted
    lcdWriteCMD(0x36);
    ucTemp[0] = 0x68; // swap r/b
    lcdWriteDATA(ucTemp, 1);
    usBG = 0; usFG = 0xffff;
//    lcdOrientation(iOrientation);
    lcdFill(usBG);
//    pinMode(VBUS_PIN, INPUT_PULLDOWN);
//    while (1) {
//    	ucTemp[0] = '0' + digitalRead(VBUS_PIN);
//    	ucTemp[1] = 0;
//    	lcdWriteString(0,0,ucTemp, COLOR_WHITE, COLOR_BLACK, FONT_12x16);
//    	Delay_Ms(250);
//    }
    ShowLogo();
 //   if (I2CTest(0x62)) {
 //   	lcdWriteString(0,0,"Found SCD41!", COLOR_GREEN, COLOR_BLACK, FONT_12x16);
 //   } else {
 //   	lcdWriteString(0,0,"SCD41 not found", COLOR_RED, COLOR_BLACK, FONT_12x16);
//    }
//    Delay_Ms(10000);
    scd41_setAutoCalibration(0); // make sure auto calibration is turned off
    scd41_start(SCD_POWERMODE_NORMAL);
    iTick = iHold = 0;
    iShutdown = 5*60*8; // auto shutdown after 5 minutes
    while(1)
    {
    	Delay_Ms(156);
    	iTick++;
    	if ((iTick & 31) == 0) { // show new sample every 5 seconds
            scd41_getSample();
            ShowCO2();
    	}
    	iShutdown--;
    	if (iShutdown == 0) {
    		if (digitalRead(VBUS_PIN) == 1) {
    			// we're plugged in, no need to shut down
    			iShutdown = 5*60*8; // reset the shutdown timer to 5 minutes
    			continue;
    		}
    		PowerDown(); // time ran out, turn off the power
    	}
    	if (digitalRead(BATTBUTT_PIN) == 1) {
    		iHold++; // hold for 1.25 seconds to shut down
    		if (iHold >= 8) {
    			PowerDown();
    		}
    	} else if (iHold) {
    		iHold = 0; // reset hold timer
    		RunMenu();
    	}
    } // while (1)
} /* main() */
