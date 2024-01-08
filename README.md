CO2_USB_033
===========
<b>What is it?</b><br>
A KiCad PCB project plus firmware for a portable CO2 sensor based on the WCH CH32X033 MCU. This is my first PCB with this chip and so far it's impressing me quite a bit. I was able to buy a small quantity for about 23 cents each. The 033 is part of the CH32X035 family and has a 48Mhz RISC-V core with 20K SRAM, 62K FLASH, USB full speed and many of the typical I/O capabilities of 32-bit MCUs. This project was more of an experiment to see if I could easily add some USB functionality to my battery powered CO2 sensor.<br><br>
<b>What's special about this project?</b><br>
By using a low cost display, MCU and sensor, my aim for this project was to make a practical and low cost way to carry a true CO2 sensor in your pocket. The CH32X033 also allowed me to easily add USB CDC support so that a PC could receive the sensor readings too. I use a clever single pushbutton circuit to control power and input. By using the enable pin of the 3.3v regulator in software control, the device can turn itself off. I use this feature to make sure the battery isn't accidentally left for dead. After 5 minutes of use, it will turn itself off.<br><br>
<b>Building the Project</b><br>
I used KiCad to design the PCB and all of the source files and Gerber zip is in the PCB folder ready to send for production. I assembled the board myself, so I don't have any assembly instructions/files with it. The firmware was built using MounRiver Studio IDE and the CH32X035 EVT provided on the WCH website.<br>

![CO2](/co2_demo.jpg?raw=true "Example use")

If you find this code useful, please consider sending a donation or becoming a Github sponsor.

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=SR4F44J2UR8S4)
