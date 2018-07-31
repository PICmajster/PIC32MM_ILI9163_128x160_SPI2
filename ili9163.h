/*
    File Name:        :  ili9163.h

    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
 */

#ifndef ILI9163_H_
#define ILI9163_H_

/*
     Signal LCD ---> MCU PIC32MM
   
     CS   (Chip Select)     --> Ground
     RESET                  --> on turn MCU, RC (10uF+10k)
     A0   (Command / Data)  --> RC3
     SDA  (Serial Data)     --> RB3
     SCK  (Serial Clock)    --> RB8
     
*/

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 160

#define DC_ON		PORTCbits.RC3 = 0;
#define DC_OFF		PORTCbits.RC3 = 1; 

 
/*
  Colour definition
  for more colours * Colour Table
  http://www.rapidtables.com/web/color/RGB_Color.htm
 */

// RGB565 Format converter
#define RGB565(r,g,b) (((uint16_t)r & 0x00F8) << 8) | (((uint16_t)g & 0x00FC) << 3) | (((uint16_t)b & 0x00F8) >> 3)  

//==== STANDARD HTML/CSS/RGB COLOR NAMES BELOW =====
// Reds
#define INDIAN_RED              RGB565(205,  92,  92)
#define LIGHT_CORAL             RGB565(240, 128, 128)
#define SALMON                  RGB565(250, 128, 114)
#define DARK_SALMON             RGB565(233, 150, 122)
#define LIGHT_SALMON            RGB565(255, 160, 122)
#define CRIMSON                 RGB565(220,  20,  60)
#define RED                     RGB565(255,   0,   0)
#define FIRE_BRICK              RGB565(178,  34,  34)
#define DARK_RED                RGB565(139,   0,   0)
#define MAROON                  RGB565(128,   0,   0)

// Pinks
#define PINK                    RGB565(255, 192, 203)
#define LIGHT_PINK              RGB565(255, 182, 193)
#define HOT_PINK                RGB565(255, 105, 180)
#define DEEP_PINK               RGB565(255, 201, 147)
#define MEDIUM_VIOLET_RED       RGB565(199, 211, 133)
#define PALE_VIOLET_RED         RGB565(219, 112, 147)

// Oranges
#define LIGHT_SALMON            RGB565(255, 160, 122)
#define CORAL                   RGB565(255, 127,  80)
#define TOMATO                  RGB565(255,  99,  71)
#define ORANGE_RED              RGB565(255,  69,   0)
#define DARK_ORANGE             RGB565(255, 140,   0)
#define ORANGE                  RGB565(255, 165,   0)

// Yellows
#define GOLD                    RGB565(255, 215,   0)
#define YELLOW                  RGB565(255, 255,   0)
#define LIGHT_YELLOW            RGB565(255, 255, 244)
#define LEMON_CHIFFON           RGB565(255, 250, 205)
#define LIGHT_GOLDENROD_YELLOW 	RGB565(250, 250, 210)
#define PAPAYA_WHIP             RGB565(255, 239, 213)
#define MOCCASIN                RGB565(255, 228, 181)
#define PEACH_PUFF              RGB565(255, 218, 185)
#define PALE_GOLDENROD          RGB565(238, 232, 170)

// Greens
#define GREEN_YELLOW            RGB565(173, 255,  47)
#define CHARTREUSE              RGB565(127, 255,    )
#define LAWN_GREEN              RGB565(124, 255,   0)
#define LIME                    RGB565(  0, 255,   0)
#define LIME_GREEN              RGB565( 50, 205,  50)
#define PALE_GREEN              RGB565(152, 251, 152)
#define LIGHT_GREEN             RGB565(144, 238, 144)
#define MEDIUM_SPRING_GREEN 	RGB565(  0, 250, 154)
#define SPRING_GREEN            RGB565(  0, 255, 127)
#define MEDIUM_SEA_GREEN        RGB565( 60, 179, 113)
#define SEA_GREEN               RGB565( 46, 139,  87)
#define FOREST_GREEN            RGB565( 34, 139,  34)
#define GREEN                   RGB565(  0, 128,   0)
#define DARK_GREEN              RGB565(  0, 100,   0)
#define YELLOW_GREEN            RGB565(154, 205,  50)
#define OLIVE_DRAB              RGB565(107, 142,  35)
#define OLIVE                   RGB565(128, 128,   0)
#define DARK_OLIVE_GREEN        RGB565( 85, 107,  47)
#define MEDIUM_AQUAMARINE       RGB565(102, 205, 170)
#define DARK_SEA_GREEN          RGB565(143, 188, 143)
#define LIGHT_SEA_GREEN         RGB565( 32, 178, 170)

// Blues/Cyans
#define AQUA                    RGB565(  0, 255, 255)
#define CYAN                    RGB565(  0, 255, 255)
#define LIGHT_CYAN              RGB565(224, 255, 255)
#define DARK_CYAN               RGB565(  0, 139, 139)
#define TEAL                    RGB565(  0, 128, 128)
#define PALE_TURQUOISE          RGB565(175, 238, 238)
#define AQUAMARINE              RGB565(127, 255, 212)
#define TURQUOISE               RGB565( 64, 224, 208)
#define MEDIUM_TURQUOISE        RGB565( 72, 209, 204)
#define DARK_TURQUOISE          RGB565(  0, 206, 209)
#define CADET_BLUE              RGB565( 95, 158, 160)
#define STEEL_BLUE              RGB565( 70, 130, 180)
#define LIGHT_STEEL_BLUE        RGB565(176, 196, 222)
#define POWDER_BLUE             RGB565(176, 224, 230)
#define LIGHT_BLUE              RGB565(173, 216, 230)
#define SKY_BLUE                RGB565(135, 206, 235)
#define LIGHT_SKY_BLUE          RGB565(135, 206, 250)
#define DEEP_SKY_BLUE           RGB565(  0, 191, 255)
#define DODGER_BLUE             RGB565( 30, 144, 255)
#define CORNFLOWER_BLUE         RGB565(100, 149, 237)
#define MEDIUM_SLATE_BLUE       RGB565(123, 104, 238)
#define ROYAL_BLUE              RGB565( 65, 105, 225)
#define BLUE                    RGB565(  0,   0, 255)
#define MEDIUM_BLUE             RGB565(  0,   0, 205)
#define DARK_BLUE               RGB565(  0,   0, 139)
#define NAVY                    RGB565(  0,   0, 128)
#define MIDNIGHT_BLUE           RGB565( 25,  25, 112)

// Purples
#define LAVENDER                RGB565(230, 230, 250
#define THISTLE                 RGB565(216, 191, 216)
#define PLUM                    RGB565(221, 160, 221)
#define VIOLET                  RGB565(238, 130, 238)
#define ORCHID                  RGB565(218, 112, 214)
#define FUCHSIA                 RGB565(255,   0, 255)
#define MAGENTA                 RGB565(255,   0, 255)
#define MEDIUM_ORCHID           RGB565(186,  85, 211)
#define MEDIUM_PURPLE           RGB565(147, 112, 219)
#define AMETHYST                RGB565(153, 102, 204)
#define BLUE_VIOLET             RGB565(138,  43, 226)
#define DARK_VIOLET             RGB565(148,   0, 211)
#define DARK_ORCHID             RGB565(153,  50, 204)
#define DARK_MAGENTA            RGB565(139,   0, 139)
#define PURPLE                  RGB565(128,   0, 128)
#define INDIGO                  RGB565( 75,   0, 130)
#define SLATE_BLUE              RGB565(106,  90, 205)
#define DARK_SLATE_BLUE         RGB565( 72,  61, 139)
#define MEDIUM_SLATE_BLUE       RGB565(123, 104, 238)

// Browns
#define KHAKI                   RGB565(240, 230, 140)
#define DARK_KHAKI              RGB565(189, 183, 107)
#define CORNSILK                RGB565(255, 248, 220)
#define BLANCHED_ALMOND         RGB565(255, 235, 205)
#define BISQUE                  RGB565(255, 228, 196)
#define NAVAJO_WHITE            RGB565(255, 222, 173)
#define WHEAT                   RGB565(245, 222, 179)
#define BURLY_WOOD              RGB565(222, 184, 135)
#define TAN                     RGB565(210, 180, 140)
#define ROSY_BROWN              RGB565(188, 143, 143)
#define SANDY_BROWN             RGB565(244, 164,  96)
#define GOLDENROD               RGB565(218, 165,  32)
#define DARK_GOLDENROD          RGB565(184, 134,  11)
#define PERU                    RGB565(205, 133,  63)
#define CHOCOLATE               RGB565(210, 105,  30)
#define SADDLE_BROWN            RGB565(139,  69,  19)
#define SIENNA                  RGB565(160,  82,  45)
#define BROWN                   RGB565(165,  42,  42)

// Whites
#define WHITE                   RGB565(255, 255, 255)
#define SNOW                    RGB565(255, 250, 250)
#define HONEYDEW                RGB565(240, 255, 240)
#define MINT_CREAM              RGB565(245, 255, 250)
#define AZURE                   RGB565(240, 255, 255)
#define ALICE_BLUE              RGB565(240, 248, 255)
#define GHOST_WHITE             RGB565(248, 248, 255)
#define WHITE_SMOKE             RGB565(245, 245, 245)
#define SEASHELL                RGB565(255, 245, 238)
#define BEIGE                   RGB565(245, 245, 220)
#define OLD_LACE                RGB565(253, 245, 230)
#define FLORAL_WHITE            RGB565(255, 250, 240)
#define IVORY                   RGB565(255, 255, 240)
#define ANTIQUE_WHITE           RGB565(250, 235, 215)
#define LINEN                   RGB565(250, 240, 230)
#define LAVENDER_BLUSH          RGB565(255, 240, 245)
#define MISTY_ROSE              RGB565(255, 228, 225)

// Grays and Black
#define WHISPER                 RGB565(239, 230, 230)
#define GAINSBORO               RGB565(220, 220, 220)
#define LIGHT_GRAY              RGB565(211, 211, 211)
#define VERY_LIGHT_GRAY      	RGB565(205, 205, 205)
#define SILVER                  RGB565(192, 192, 192)
#define DARK_GRAY               RGB565(169, 169, 169)
#define NOBEL                   RGB565(169, 157, 157)
#define GRAY                    RGB565(128, 128, 128)
#define DIM_GRAY                RGB565(105, 105, 105)
#define ZAMBEZI                 RGB565( 96,  96,  96)
#define LIGHT_SLATE_GRAY        RGB565(119, 136, 153)
#define SLATE_GRAY              RGB565(112, 128, 144)
#define DARK_SLATE_GRAY         RGB565( 47,  79,  79)
#define ECLIPSE                 RGB565( 64,  64,  64)
#define NERO                    RGB565( 32,  32,  32)
#define BLACK                   RGB565(  0,   0,   0)

/*Command defines only useful for this display controller chip*/
#define NOP 					0x00
#define SOFT_RESET 				0x01
#define GET_RED_CHANNEL 		0x06
#define GET_GREEN_CHANNEL 		0x07
#define GET_BLUE_CHANNEL 		0x08
#define GET_PIXEL_FORMAT 		0x0C
#define GET_POWER_MODE 			0x0A
#define GET_ADDRESS_MODE 		0x0B
#define GET_DISPLAY_MODE 		0x0D
#define GET_SIGNAL_MODE 		0x0E
#define GET_DIAGNOSTIC_RESULT 	0x0F
#define ENTER_SLEEP_MODE 		0x10
#define EXIT_SLEEP_MODE 		0x11
#define ENTER_PARTIAL_MODE 		0x12
#define ENTER_NORMAL_MODE 		0x13
#define EXIT_INVERT_MODE 		0x20
#define ENTER_INVERT_MODE 		0x21
#define SET_GAMMA_CURVE 		0x26
#define SET_DISPLAY_OFF			0x28
#define SET_DISPLAY_ON 			0x29
#define SET_COLUMN_ADDRESS 		0x2A
#define SET_PAGE_ADDRESS 		0x2B
#define WRITE_MEMORY_START 		0x2C
#define WRITE_LUT 				0x2D
#define READ_MEMORY_START 		0x2E
#define SET_PARTIAL_AREA 		0x30
#define SET_SCROLL_AREA 		0x33
#define SET_TEAR_OFF 			0x34
#define SET_TEAR_ON 			0x35
#define SET_ADDRESS_MODE 		0x36
#define SET_SCROLL_START 		0X37
#define EXIT_IDLE_MODE 			0x38
#define ENTER_IDLE_MODE 		0x39
#define SET_PIXEL_FORMAT 		0x3A
#define WRITE_MEMORY_CONTINUE 	0x3C
#define READ_MEMORY_CONTINUE 	0x3E
#define SET_TEAR_SCANLINE 		0x44
#define GET_SCANLINE 			0x45
#define READ_ID1				0xDA
#define READ_ID2				0xDB
#define READ_ID3				0xDC
#define FRAME_RATE_CONTROL1		0xB1
#define FRAME_RATE_CONTROL2		0xB2
#define FRAME_RATE_CONTROL3		0xB3
#define DISPLAY_INVERSION		0xB4
#define SOURCE_DRIVER_DIRECTION	0xB7
#define GATE_DRIVER_DIRECTION	0xB8
#define POWER_CONTROL1			0xC0
#define POWER_CONTROL2			0xC1
#define POWER_CONTROL3			0xC2
#define POWER_CONTROL4			0xC3
#define POWER_CONTROL5			0xC4
#define VCOM_CONTROL1			0xC5
#define VCOM_CONTROL2			0xC6
#define VCOM_OFFSET_CONTROL		0xC7
#define WRITE_ID4_VALUE			0xD3
#define NV_MEMORY_FUNCTION1		0xD7
#define NV_MEMORY_FUNCTION2		0xDE
#define POSITIVE_GAMMA_CORRECT	0xE0
#define NEGATIVE_GAMMA_CORRECT	0xE1
#define GAM_R_SEL               0xF2

#define MADCTL_MY  0x80
#define MADCTL_MX  0x40
#define MADCTL_MV  0x20
#define MADCTL_ML  0x10
#define MADCTL_RGB 0x00
#define MADCTL_BGR 0x08
#define MADCTL_MH  0x04

// Macros and in-lines:

// This routine takes a row number from 0 to 20 and
// returns the x coordinate on the screen (0-127) to make
// it easy to place text
inline uint8_t lcdTextX(uint8_t x) { return x*6; }

// This routine takes a column number from 0 to 20 and
// returns the y coordinate on the screen (0-159) to make
// it easy to place text
inline uint8_t lcdTextY(uint8_t y) { return y*8; }

//	LCD function prototypes
//void writeSD(uint8_t byteOut);
void writeSPI(uint8_t byteOut);
void lcdReset(void);
void lcdWriteCommand_bis(uint8_t cmdOut);
void lcdWriteParameter_bis(uint8_t data);
void lcdWriteData_bis(uint8_t dataByte1, uint8_t dataByte2);
void lcdInitialize(void);//void lcdInitialise(uint8_t orientation);

void lcdLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t colour);
void lcdFastVLine(int16_t x, int16_t y, int16_t h, uint16_t colour);
void lcdFastHLine(int16_t x, int16_t y, int16_t w, uint16_t colour) ;
void lcdRectangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t colour);
void lcdFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t colour);
void lcdCircle(int16_t xCentre, int16_t yCentre, int16_t radius, uint16_t colour);

void lcdPutS(char *c, int16_t x, int16_t y, uint16_t colour, uint16_t bg, uint8_t size);
void lcdPutCh(unsigned char character, uint8_t x, uint8_t y, uint16_t fgColour, uint16_t bgColour, uint8_t size);
void lcdBitmap(const unsigned char *data, uint8_t width, uint8_t heigth, uint8_t x, uint8_t y, uint16_t fgColour, uint16_t bgColour);

void setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
void lcdPixel(int16_t x, int16_t y, uint16_t colour) ;
void lcdFillScreen(uint16_t colour);

void lcdRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t colour) ;
void lcdFillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h,int16_t r, uint16_t colour) ;
void lcdFillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,int16_t delta, uint16_t colour) ;
void lcdCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t colour) ;
void lcdFillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t colour) ;
void lcdTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t colour);
void lcdXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t colour);

void lcdPutInteger(uint16_t val, int16_t x, int16_t y, uint16_t colour, uint16_t bg, uint8_t size);
void lcdPutFloat(float val, int16_t x, int16_t y, uint16_t colour, uint16_t bg, uint8_t size);
void setRotation(uint8_t m);


#endif /* ILI9163_H_ */