// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t Open_Sans_Condensed_Bold_24Bitmaps[] PROGMEM = {

	// Bitmap Data:
	0x00, // ' '
	0x77,0x77,0x77,0x77,0x77,0x70,0x07,0xFF,0x70, // '!'
	0xE7,0x63,0x63,0x63,0x63,0x63, // '"'
	0x0E,0x60,0x63,0x03,0x38,0x19,0xC0,0xCC,0x3F,0xFD,0xFF,0xE3,0x98,0x18,0xC0,0xCE,0x3F,0xFD,0xFF,0xE1,0x98,0x1C,0xC0,0xE6,0x06,0x30,0x33,0x80, // '#'
	0x08,0x04,0x0F,0x8F,0xFF,0xF7,0x4B,0xA1,0xD0,0x78,0x1F,0x03,0xC1,0x70,0xBC,0x5F,0xFF,0xFE,0x7E,0x04,0x02,0x00, // '$'
	0x78,0x30,0xFC,0x30,0xEC,0x70,0xCC,0x60,0xCC,0xE0,0xCE,0xC0,0xCC,0xDE,0xCD,0xFE,0xED,0xB7,0xFF,0xB3,0x7B,0x73,0x03,0x73,0x07,0x73,0x06,0x33,0x0E,0x37,0x0C,0x3E,0x1C,0x1C, // '%'
	0x1E,0x01,0xFC,0x1F,0xE0,0xE7,0x07,0x38,0x3D,0xC0,0xFC,0x03,0xC0,0x7E,0x33,0xF3,0xB9,0xDD,0xCF,0xEE,0x3E,0x70,0xF3,0xFF,0x8F,0xFE,0x3E,0x70, // '&'
	0xE6,0x66,0x66, // '''
	0x1C,0xE3,0x9C,0x71,0xCE,0x38,0xE3,0x8E,0x38,0xE3,0x8E,0x1C,0x71,0xC3,0x8E,0x1C, // '('
	0xE1,0xC7,0x0E,0x38,0xE1,0xC7,0x1C,0x71,0xC7,0x1C,0x71,0xCE,0x38,0xE7,0x1C,0xE0, // ')'
	0x1C,0x0E,0x07,0x1F,0x7F,0xF9,0xF8,0xF8,0xEC,0x77,0x11,0x00, // '*'
	0x1C,0x0E,0x07,0x03,0x8F,0xFF,0xFC,0x70,0x38,0x1C,0x0E,0x07,0x00, // '+'
	0x7F,0xEE,0xEC, // ','
	0xFF,0xFF,0xC0, // '-'
	0x7F,0xF7, // '.'
	0x01,0xC0,0xE0,0x38,0x1C,0x07,0x01,0xC0,0xE0,0x38,0x0E,0x07,0x01,0xC0,0xE0,0x38,0x0E,0x07,0x01,0xC0,0xE0,0x00, // '/'
	0x3E,0x3F,0x9F,0xDE,0xFE,0x3F,0x1F,0x8F,0xC7,0xE3,0xF1,0xF8,0xFC,0x7E,0x3F,0xBD,0xFC,0xFE,0x3E,0x00, // '0'
	0x0E,0x3C,0xFB,0xFE,0xED,0xC3,0x87,0x0E,0x1C,0x38,0x70,0xE1,0xC3,0x87,0x0E, // '1'
	0x3C,0x3F,0xBF,0xCC,0xE0,0x78,0x3C,0x1C,0x0E,0x0F,0x07,0x07,0x07,0x07,0x83,0x83,0xFF,0xFF,0xFF,0x80, // '2'
	0x3E,0x7F,0xBF,0xC8,0xF0,0x78,0x38,0x1C,0x7C,0x3E,0x1F,0x81,0xE0,0x70,0x3C,0x3F,0xFD,0xFE,0xFC,0x00, // '3'
	0x07,0x80,0xF0,0x3E,0x07,0xC1,0xF8,0x3F,0x06,0xE1,0xDC,0x33,0x8E,0x71,0x8E,0x7F,0xFF,0xFF,0xFF,0xC0,0xE0,0x1C,0x03,0x80, // '4'
	0x7F,0x3F,0x9F,0xCE,0x06,0x07,0x03,0xF9,0xFE,0x7F,0x83,0xC0,0xE0,0x70,0x3C,0x3F,0xFD,0xFE,0x7C,0x00, // '5'
	0x0F,0x1F,0x9F,0xCE,0x0E,0x07,0x03,0xB9,0xFE,0xFF,0xFB,0xF8,0xFC,0x7E,0x3F,0xBD,0xFC,0xFE,0x3E,0x00, // '6'
	0xFF,0xFF,0xFF,0xE0,0x70,0x70,0x38,0x1C,0x1C,0x0E,0x07,0x07,0x03,0x81,0xC1,0xE0,0xE0,0x70,0x78,0x00, // '7'
	0x3E,0x3F,0xBF,0xFC,0x7E,0x3F,0x1D,0xDC,0xFE,0x3E,0x3F,0xBD,0xFC,0x7E,0x3F,0x1F,0xFE,0xFE,0x3E,0x00, // '8'
	0x3C,0x3F,0xBF,0xDC,0xFE,0x3F,0x1F,0x8F,0xCF,0xFF,0xBF,0xCE,0xE0,0x70,0x70,0x79,0xFC,0xFC,0x78,0x00, // '9'
	0x7F,0xF7,0x00,0x00,0x07,0xFF,0x70, // ':'
	0x7F,0xF7,0x00,0x00,0x00,0x7F,0xEE,0xEC, // ';'
	0x00,0x00,0xC1,0xE1,0xE3,0xC7,0xC3,0x81,0xF0,0x3C,0x07,0x81,0xE0,0x30,0x00, // '<'
	0xFF,0xFF,0xC0,0x00,0x00,0x07,0xFF,0xFE, // '='
	0x00,0x60,0x3C,0x0F,0x01,0xE0,0x7C,0x0E,0x1F,0x1E,0x3C,0x3C,0x18,0x00,0x00, // '>'
	0x3E,0xFF,0x7F,0x47,0x07,0x07,0x07,0x0E,0x1C,0x18,0x18,0x00,0x00,0x38,0x3C,0x3C,0x38, // '?'
	0x07,0xE0,0x3F,0xF0,0xF0,0xF1,0xC0,0xE7,0x3E,0xEC,0xFD,0xFB,0x99,0xE7,0x33,0xCC,0xE7,0x99,0xCF,0x33,0x9E,0x77,0x7C,0xFF,0xDC,0xE7,0x18,0x00,0x38,0x00,0x3C,0x30,0x3F,0xE0,0x3F,0x80, // '@'
	0x0F,0x80,0x7C,0x03,0x60,0x3B,0x81,0xDC,0x0E,0xE0,0x77,0x07,0x1C,0x38,0xE1,0xC7,0x0F,0xF8,0xFF,0xE7,0xFF,0x38,0x39,0xC1,0xDE,0x0F,0xE0,0x38, // 'A'
	0xFF,0x3F,0xEF,0xFF,0x8F,0xE1,0xF8,0x7E,0x3B,0xFE,0xFF,0x3F,0xEE,0x3F,0x87,0xE1,0xF8,0xFF,0xFF,0xFE,0xFF,0x00, // 'B'
	0x0F,0x0F,0xE7,0xF9,0xE2,0xF0,0x3C,0x0E,0x03,0x80,0xE0,0x38,0x0E,0x03,0xC0,0xF0,0x1E,0x27,0xF8,0xFE,0x0F,0x00, // 'C'
	0xFE,0x1F,0xF3,0xFF,0x79,0xEF,0x1F,0xE3,0xFC,0x3F,0x87,0xF0,0xFE,0x1F,0xC3,0xF8,0xFF,0x1F,0xE7,0xBF,0xF7,0xFC,0xFE,0x00, // 'D'
	0xFF,0xFF,0xFF,0xF0,0xF0,0xF0,0xF0,0xFF,0xFF,0xFF,0xF0,0xF0,0xF0,0xF0,0xFF,0xFF,0xFF, // 'E'
	0xFF,0xFF,0xFF,0x0E,0x1C,0x38,0x7F,0xFF,0xFF,0x87,0x0E,0x1C,0x38,0x70,0xE0, // 'F'
	0x0F,0xC3,0xFC,0xFF,0x3C,0x27,0x01,0xE0,0x38,0x07,0x00,0xE3,0xFC,0x7F,0x8F,0xF8,0x7F,0x0E,0xF1,0xDF,0xF9,0xFF,0x0F,0xC0, // 'G'
	0xE1,0xF8,0x7E,0x1F,0x87,0xE1,0xF8,0x7E,0x1F,0xFF,0xFF,0xFF,0xFE,0x1F,0x87,0xE1,0xF8,0x7E,0x1F,0x87,0xE1,0xC0, // 'H'
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // 'I'
	0x1E,0x3C,0x78,0xF1,0xE3,0xC7,0x8F,0x1E,0x3C,0x78,0xF1,0xE3,0xC7,0x8F,0x1E,0x3C,0x77,0xEF,0x9E,0x00, // 'J'
	0xF1,0xFE,0x3B,0xCF,0x79,0xCF,0x79,0xEE,0x3F,0xC7,0xF0,0xFF,0x1F,0xE3,0xDC,0x79,0xCF,0x39,0xE7,0xBC,0x77,0x8E,0xF1,0xE0, // 'K'
	0xE1,0xC3,0x87,0x0E,0x1C,0x38,0x70,0xE1,0xC3,0x87,0x0E,0x1C,0x3F,0xFF,0xFE, // 'L'
	0xF8,0x3F,0xF0,0x7F,0xE0,0xFE,0xC1,0xFD,0x87,0xFB,0x8F,0xF7,0x1F,0xE6,0x37,0xCC,0x6F,0x9D,0xDF,0x3B,0xBE,0x76,0x7C,0x6C,0xF8,0xF9,0xF1,0xF3,0xE3,0xE7,0xC3,0x8E, // 'M'
	0xF0,0x7E,0x0F,0xC1,0xFC,0x3F,0x87,0xB8,0xF7,0x1E,0x73,0xCE,0x79,0xCF,0x1D,0xE3,0xBC,0x3F,0x87,0xF0,0x7E,0x0F,0xC1,0xE0, // 'N'
	0x0F,0x03,0xFC,0x7F,0xE7,0x9E,0xF0,0xFF,0x0F,0xE0,0x7E,0x07,0xE0,0x7E,0x07,0xE0,0x7F,0x0F,0xF0,0xF7,0x9E,0x7F,0xE3,0xFC,0x0F,0x00, // 'O'
	0xFE,0x7F,0xBF,0xFC,0xFE,0x3F,0x1F,0x8F,0xCF,0xFF,0xFF,0xBF,0x1C,0x0E,0x07,0x03,0x81,0xC0,0xE0,0x00, // 'P'
	0x0F,0x03,0xFC,0x7F,0xE7,0x9E,0xF0,0xFF,0x0F,0xE0,0x7E,0x07,0xE0,0x7E,0x07,0xE0,0x7F,0x0F,0xF0,0xF7,0x9E,0x7F,0xE3,0xFC,0x0F,0x80,0x3C,0x01,0xE0,0x0E,0x00,0xF0, // 'Q'
	0xFC,0x3F,0xCF,0xF3,0x9E,0xE3,0xB8,0xEE,0x7B,0x9E,0xFF,0x3F,0x8F,0xE3,0xB8,0xE7,0x39,0xCE,0x7B,0x8E,0xE3,0xC0, // 'R'
	0x3E,0x7F,0xFF,0xF0,0xE0,0xE0,0xF0,0x78,0x3E,0x1F,0x0F,0x07,0x07,0x87,0xFF,0xFE,0x7C, // 'S'
	0xFF,0xFF,0xFF,0xFC,0x78,0x1E,0x07,0x81,0xE0,0x78,0x1E,0x07,0x81,0xE0,0x78,0x1E,0x07,0x81,0xE0,0x78,0x1E,0x00, // 'T'
	0xF1,0xFE,0x3F,0xC7,0xF8,0xFF,0x1F,0xE3,0xFC,0x7F,0x8F,0xF1,0xFE,0x3F,0xC7,0xF8,0xFF,0x1C,0xE3,0x9F,0xF1,0xFC,0x1F,0x00, // 'U'
	0xE0,0x7F,0x0F,0x70,0xE7,0x0E,0x70,0xE7,0x0E,0x39,0xC3,0x9C,0x39,0xC3,0x9C,0x39,0xC1,0xF8,0x1F,0x81,0xF8,0x1F,0x80,0xF0,0x0F,0x00, // 'V'
	0xE0,0xE0,0xFE,0x1C,0x3D,0xC7,0xC7,0x38,0xF8,0xE7,0x1B,0x1C,0xE3,0x63,0x9C,0x6C,0x71,0xDD,0xDC,0x3B,0xBB,0x87,0x77,0x70,0xEE,0xEE,0x1D,0x8D,0xC3,0xB1,0xB8,0x36,0x36,0x07,0xC7,0xC0,0xF8,0xF8,0x1E,0x0F,0x00, // 'W'
	0xF1,0xEE,0x39,0xC7,0x1D,0xC3,0xB8,0x3E,0x07,0xC0,0x78,0x0E,0x03,0xE0,0x7C,0x1D,0xC3,0xB8,0xF7,0x1C,0x73,0x8E,0xE1,0xE0, // 'X'
	0xF1,0xEE,0x39,0xC7,0x38,0xE3,0xB8,0x77,0x0E,0xE0,0xF8,0x1F,0x01,0xC0,0x38,0x07,0x00,0xE0,0x1C,0x03,0x80,0x70,0x0E,0x00, // 'Y'
	0x7F,0x9F,0xE7,0xF8,0x1E,0x07,0x01,0xC0,0xE0,0x38,0x1E,0x07,0x03,0xC0,0xE0,0x78,0x1C,0x07,0xFF,0xFF,0xFF,0xC0, // 'Z'
	0xFF,0xF9,0xCE,0x73,0x9C,0xE7,0x39,0xCE,0x73,0x9C,0xE7,0x39,0xFF,0x80, // '['
	0xE0,0x1C,0x07,0x00,0xE0,0x38,0x0E,0x01,0xC0,0x70,0x1E,0x03,0x80,0xE0,0x1C,0x07,0x01,0xC0,0x38,0x0E,0x01,0xC0, // '\'
	0xFF,0xCE,0x73,0x9C,0xE7,0x39,0xCE,0x73,0x9C,0xE7,0x39,0xCF,0xFF,0x80, // ']'
	0x06,0x00,0x38,0x03,0xC0,0x1F,0x01,0xD8,0x0C,0xE0,0xE3,0x06,0x1C,0x70,0x73,0x03,0xB8,0x0E, // '^'
	0xFF,0xFF, // '_'
	0xF3,0x8E,0x30, // '`'
	0x3E,0x7F,0x9F,0xE8,0xF0,0x39,0xFF,0xFF,0xC7,0xE3,0xF3,0xFF,0xFF,0x77,0x38, // 'a'
	0xE0,0x38,0x0E,0x03,0x80,0xE0,0x39,0xCE,0xFB,0xFE,0xF3,0xFC,0x7E,0x1F,0x87,0xE1,0xFC,0x7F,0x3F,0xFE,0xFF,0xBB,0xC0, // 'b'
	0x3E,0x7E,0x7E,0xF0,0xE0,0xE0,0xE0,0xE0,0xE0,0xF0,0x7E,0x7E,0x3E, // 'c'
	0x01,0xC0,0x70,0x1C,0x07,0x01,0xCE,0x77,0xDF,0xFF,0xF3,0xF8,0xFE,0x3F,0x87,0xE3,0xF8,0xFF,0x3D,0xFF,0x7F,0xCF,0x70, // 'd'
	0x1E,0x3F,0x9F,0xFE,0x7E,0x3F,0xFF,0xFF,0xFF,0xE0,0x78,0x1F,0xEF,0xF1,0xF0, // 'e'
	0x1F,0x3F,0x3E,0x38,0x38,0x7E,0xFE,0xFE,0x38,0x38,0x38,0x38,0x38,0x38,0x38,0x38,0x38,0x38, // 'f'
	0x1F,0xE7,0xFD,0xCE,0x38,0xE7,0x1C,0xE3,0x9C,0xE1,0xFC,0x3E,0x06,0x01,0xFE,0x1F,0xE7,0xFE,0xE1,0xF8,0x3F,0x06,0xF1,0xCF,0xF0,0xFC,0x00, // 'g'
	0xE0,0x38,0x0E,0x03,0x80,0xE0,0x39,0xCE,0xFB,0xFF,0xF3,0xFC,0x7F,0x1F,0x87,0xE1,0xF8,0x7E,0x1F,0x87,0xE1,0xF8,0x70, // 'h'
	0x6F,0x60,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, // 'i'
	0x18,0xF1,0x80,0x00,0xF3,0xCF,0x3C,0xF3,0xCF,0x3C,0xF3,0xCF,0x3C,0xF3,0xCF,0x3F,0xEF,0xBC, // 'j'
	0xE0,0x38,0x0E,0x03,0x80,0xE0,0x38,0xEE,0x7B,0x9C,0xEF,0x3B,0x8E,0xE3,0xF8,0xFE,0x3D,0xCE,0x73,0x8E,0xE3,0xB8,0xE0, // 'k'
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, // 'l'
	0xE7,0x1E,0x77,0xDF,0xBF,0xFF,0xFE,0x7C,0xFF,0x1C,0x3F,0x8E,0x1F,0x87,0x0F,0xC3,0x87,0xE1,0xC3,0xF0,0xE1,0xF8,0x70,0xFC,0x38,0x7E,0x1C,0x38, // 'm'
	0xE7,0x3B,0xEF,0xFF,0xCF,0xF1,0xF8,0x7E,0x1F,0x87,0xE1,0xF8,0x7E,0x1F,0x87,0xE1,0xC0, // 'n'
	0x1E,0x1F,0xE7,0xFB,0xCF,0xE1,0xF8,0x7E,0x1F,0x87,0xE1,0xFC,0xF7,0xF9,0xFE,0x1E,0x00, // 'o'
	0xE7,0x3B,0xEF,0xFB,0xCF,0xF1,0xF8,0x7E,0x1F,0x87,0xF1,0xFC,0xFF,0xFB,0xBE,0xEF,0x38,0x0E,0x03,0x80,0xE0,0x38,0x0E,0x00, // 'p'
	0x39,0xDF,0x77,0xFF,0xCF,0xE3,0xF8,0xFE,0x1F,0x8F,0xE3,0xFC,0xF7,0xFD,0xF7,0x39,0xC0,0x70,0x1C,0x07,0x01,0xC0,0x70,0x1C, // 'q'
	0xEF,0xDF,0xFF,0x8F,0x1C,0x38,0x70,0xE1,0xC3,0x87,0x0E,0x00, // 'r'
	0x3D,0xFF,0xFF,0x0E,0x1F,0x1F,0x0F,0x0F,0x1F,0xFF,0xFF,0x80, // 's'
	0x18,0x70,0xE3,0xFF,0xFF,0xCE,0x1C,0x38,0x70,0xE1,0xC3,0x87,0xCF,0x8F, // 't'
	0xE1,0xF8,0x7E,0x1F,0x87,0xE1,0xF8,0x7E,0x1F,0x8F,0xE3,0xFC,0xFF,0xFD,0xF7,0x39,0xC0, // 'u'
	0xE0,0xFE,0x3D,0xC7,0x38,0xE7,0x1C,0x77,0x8E,0xE1,0xDC,0x3B,0x83,0x60,0x7C,0x0F,0x81,0xF0, // 'v'
	0xE3,0xE3,0xB9,0xF3,0x9C,0xD9,0xCE,0x6C,0xE7,0x36,0x73,0x9B,0x39,0xDD,0xDC,0x7E,0xFC,0x3F,0x7E,0x1F,0x1F,0x0F,0x8F,0x87,0xC7,0xC1,0xE3,0xC0, // 'w'
	0x73,0x9C,0xE3,0xB0,0xFC,0x1E,0x07,0x81,0xE0,0x78,0x3F,0x0F,0xC7,0x39,0xCE,0xF3,0xC0, // 'x'
	0xE0,0xFE,0x3D,0xC7,0x38,0xE7,0x1C,0x77,0x8E,0xE1,0xDC,0x1B,0x83,0xE0,0x7C,0x0F,0x80,0xF0,0x1C,0x03,0x80,0xF0,0xFC,0x1F,0x83,0xC0,0x00, // 'y'
	0x7F,0x3F,0x9F,0xC0,0xE0,0xE0,0xF0,0x70,0x78,0x38,0x38,0x1F,0xFF,0xFF,0xF8, // 'z'
	0x07,0x87,0xC7,0xE3,0x81,0xC0,0xE0,0x70,0x38,0x1C,0x7E,0x3C,0x1F,0x81,0xC0,0xE0,0x70,0x38,0x1C,0x0E,0x03,0xC1,0xF0,0x78, // '{'
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, // '|'
	0xF0,0x7C,0x3F,0x03,0x81,0xC0,0xE0,0x70,0x38,0x1C,0x0F,0xC1,0xE3,0xF1,0xC0,0xE0,0x70,0x38,0x1C,0x0E,0x1F,0x1F,0x0F,0x00 // '}'
};
const GFXglyph Open_Sans_Condensed_Bold_24Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {     0,   1,   1,   7,    0,   -1 }, // ' '
	  {     1,   4,  17,   8,    1,  -17 }, // '!'
	  {    10,   8,   6,  12,    1,  -17 }, // '"'
	  {    16,  13,  17,  14,    0,  -17 }, // '#'
	  {    44,   9,  19,  12,    1,  -18 }, // '$'
	  {    66,  16,  17,  19,    1,  -17 }, // '%'
	  {   100,  13,  17,  15,    1,  -17 }, // '&'
	  {   128,   4,   6,   7,    1,  -17 }, // '''
	  {   131,   6,  21,   9,    1,  -17 }, // '('
	  {   147,   6,  21,   9,    1,  -17 }, // ')'
	  {   163,   9,  10,  12,    1,  -18 }, // '*'
	  {   175,   9,  11,  12,    1,  -14 }, // '+'
	  {   188,   4,   6,   7,    1,   -3 }, // ','
	  {   191,   6,   3,   9,    1,   -8 }, // '-'
	  {   194,   4,   4,   7,    1,   -4 }, // '.'
	  {   196,  10,  17,  11,    0,  -17 }, // '/'
	  {   218,   9,  17,  12,    1,  -17 }, // '0'
	  {   238,   7,  17,  12,    1,  -17 }, // '1'
	  {   253,   9,  17,  12,    1,  -17 }, // '2'
	  {   273,   9,  17,  12,    1,  -17 }, // '3'
	  {   293,  11,  17,  12,    0,  -17 }, // '4'
	  {   317,   9,  17,  12,    1,  -17 }, // '5'
	  {   337,   9,  17,  12,    1,  -17 }, // '6'
	  {   357,   9,  17,  12,    1,  -17 }, // '7'
	  {   377,   9,  17,  12,    1,  -17 }, // '8'
	  {   397,   9,  17,  12,    1,  -17 }, // '9'
	  {   417,   4,  13,   7,    1,  -13 }, // ':'
	  {   424,   4,  16,   7,    1,  -13 }, // ';'
	  {   432,   9,  13,  12,    1,  -15 }, // '<'
	  {   447,   9,   7,  12,    1,  -12 }, // '='
	  {   455,   9,  13,  12,    1,  -15 }, // '>'
	  {   470,   8,  17,  10,    0,  -17 }, // '?'
	  {   487,  15,  19,  18,    1,  -17 }, // '@'
	  {   523,  13,  17,  14,    0,  -17 }, // 'A'
	  {   551,  10,  17,  13,    1,  -17 }, // 'B'
	  {   573,  10,  17,  12,    1,  -17 }, // 'C'
	  {   595,  11,  17,  14,    1,  -17 }, // 'D'
	  {   619,   8,  17,  11,    1,  -17 }, // 'E'
	  {   636,   7,  17,  11,    2,  -17 }, // 'F'
	  {   651,  11,  17,  14,    1,  -17 }, // 'G'
	  {   675,  10,  17,  15,    2,  -17 }, // 'H'
	  {   697,   3,  17,   8,    2,  -17 }, // 'I'
	  {   704,   7,  22,   7,   -2,  -17 }, // 'J'
	  {   724,  11,  17,  13,    1,  -17 }, // 'K'
	  {   748,   7,  17,  11,    2,  -17 }, // 'L'
	  {   763,  15,  17,  20,    2,  -17 }, // 'M'
	  {   795,  11,  17,  16,    2,  -17 }, // 'N'
	  {   819,  12,  17,  15,    1,  -17 }, // 'O'
	  {   845,   9,  17,  13,    2,  -17 }, // 'P'
	  {   865,  12,  21,  15,    1,  -17 }, // 'Q'
	  {   897,  10,  17,  13,    2,  -17 }, // 'R'
	  {   919,   8,  17,  11,    1,  -17 }, // 'S'
	  {   936,  10,  17,  11,    0,  -17 }, // 'T'
	  {   958,  11,  17,  14,    1,  -17 }, // 'U'
	  {   982,  12,  17,  13,    0,  -17 }, // 'V'
	  {  1008,  19,  17,  20,    0,  -17 }, // 'W'
	  {  1049,  11,  17,  12,    0,  -17 }, // 'X'
	  {  1073,  11,  17,  12,    0,  -17 }, // 'Y'
	  {  1097,  10,  17,  11,    0,  -17 }, // 'Z'
	  {  1119,   5,  21,   9,    2,  -17 }, // '['
	  {  1133,  10,  17,  11,    0,  -17 }, // '\'
	  {  1155,   5,  21,   9,    1,  -17 }, // ']'
	  {  1169,  13,  11,  14,    0,  -17 }, // '^'
	  {  1187,   8,   2,   9,    0,    2 }, // '_'
	  {  1189,   5,   4,  14,    4,  -19 }, // '`'
	  {  1192,   9,  13,  12,    1,  -13 }, // 'a'
	  {  1207,  10,  18,  13,    1,  -18 }, // 'b'
	  {  1230,   8,  13,  10,    1,  -13 }, // 'c'
	  {  1243,  10,  18,  13,    1,  -18 }, // 'd'
	  {  1266,   9,  13,  12,    1,  -13 }, // 'e'
	  {  1281,   8,  18,   8,    0,  -18 }, // 'f'
	  {  1299,  11,  19,  12,    0,  -13 }, // 'g'
	  {  1326,  10,  18,  13,    1,  -18 }, // 'h'
	  {  1349,   4,  18,   7,    1,  -18 }, // 'i'
	  {  1358,   6,  24,   7,   -1,  -18 }, // 'j'
	  {  1376,  10,  18,  12,    1,  -18 }, // 'k'
	  {  1399,   4,  18,   7,    1,  -18 }, // 'l'
	  {  1408,  17,  13,  20,    1,  -13 }, // 'm'
	  {  1436,  10,  13,  13,    1,  -13 }, // 'n'
	  {  1453,  10,  13,  13,    1,  -13 }, // 'o'
	  {  1470,  10,  19,  13,    1,  -13 }, // 'p'
	  {  1494,  10,  19,  13,    1,  -13 }, // 'q'
	  {  1518,   7,  13,   9,    1,  -13 }, // 'r'
	  {  1530,   7,  13,  10,    1,  -13 }, // 's'
	  {  1542,   7,  16,   9,    0,  -16 }, // 't'
	  {  1556,  10,  13,  13,    1,  -13 }, // 'u'
	  {  1573,  11,  13,  12,    0,  -13 }, // 'v'
	  {  1591,  17,  13,  18,    0,  -13 }, // 'w'
	  {  1619,  10,  13,  11,    0,  -13 }, // 'x'
	  {  1636,  11,  19,  12,    0,  -13 }, // 'y'
	  {  1663,   9,  13,  10,    0,  -13 }, // 'z'
	  {  1678,   9,  21,  10,    0,  -17 }, // '{'
	  {  1702,   2,  24,  13,    5,  -18 }, // '|'
	  {  1708,   9,  21,  10,    0,  -17 } // '}'
};
const GFXfont Open_Sans_Condensed_Bold_24 PROGMEM = {
(uint8_t  *)Open_Sans_Condensed_Bold_24Bitmaps,(GFXglyph *)Open_Sans_Condensed_Bold_24Glyphs,0x20, 0x7E, 33};

