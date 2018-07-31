/************************************************************************
	ili9163.c
    ILI9163 128x160 LCD library for PIC32MM Microchip
    3.3 V
    strefapic.blogspot.com
 ***********************************************************************/

#include "mcu_config_files/mcc.h"
#include "delay.h"
#include <string.h>
#include "ili9163.h"
#include "font6x8.h"


uint8_t width ;
uint8_t height ;



/********************************************
 * 
 * Low-level LCD driving functions
 * 
 **********************************************/

void lcdWriteCommand_bis(uint8_t cmdOut)
{ // Write a command to Display
   DC_ON; 		/*DC on = command set A0 low, select Command mode DisplayD_C = 0 for this byte*/
   SPI2_Send(cmdOut) ;  // Clock out command bits
   DC_OFF;
   }

void lcdWriteParameter_bis(uint8_t data)
{
	SPI2_Send(data) ;  
}

void lcdWriteData_bis(uint8_t dataByte1, uint8_t dataByte2)
{
	DC_OFF;
    SPI2_Send(dataByte1);
	SPI2_Send(dataByte2);
}


// Initialise the display with the require screen orientation
void lcdInitialize(void)//void lcdInitialise(uint8_t orientation)
{   
	// Hardware reset the LCD on turn MCU
    
  	delayMs(150);
	
    lcdWriteCommand_bis(EXIT_SLEEP_MODE);
    delayMs(50); // Wait for the screen to wake up
    
    lcdWriteCommand_bis(SET_PIXEL_FORMAT);
    lcdWriteParameter_bis(0x05); // 16 bits per pixel
   
    lcdWriteCommand_bis(SET_GAMMA_CURVE);
    lcdWriteParameter_bis(0x04); // Select gamma curve 3
	
    lcdWriteCommand_bis(GAM_R_SEL);
    lcdWriteParameter_bis(0x01); // Gamma adjustment enabled
    
    lcdWriteCommand_bis(POSITIVE_GAMMA_CORRECT);
    lcdWriteParameter_bis(0x3f); // 1st Parameter
    lcdWriteParameter_bis(0x25); // 2nd Parameter
    lcdWriteParameter_bis(0x1c); // 3rd Parameter
    lcdWriteParameter_bis(0x1e); // 4th Parameter
    lcdWriteParameter_bis(0x20); // 5th Parameter
    lcdWriteParameter_bis(0x12); // 6th Parameter
    lcdWriteParameter_bis(0x2a); // 7th Parameter
    lcdWriteParameter_bis(0x90); // 8th Parameter
    lcdWriteParameter_bis(0x24); // 9th Parameter
    lcdWriteParameter_bis(0x11); // 10th Parameter
    lcdWriteParameter_bis(0x00); // 11th Parameter
    lcdWriteParameter_bis(0x00); // 12th Parameter
    lcdWriteParameter_bis(0x00); // 13th Parameter
    lcdWriteParameter_bis(0x00); // 14th Parameter
    lcdWriteParameter_bis(0x00); // 15th Parameter
     
    lcdWriteCommand_bis(NEGATIVE_GAMMA_CORRECT);
    lcdWriteParameter_bis(0x20); // 1st Parameter
    lcdWriteParameter_bis(0x20); // 2nd Parameter
    lcdWriteParameter_bis(0x20); // 3rd Parameter
    lcdWriteParameter_bis(0x20); // 4th Parameter
    lcdWriteParameter_bis(0x05); // 5th Parameter
    lcdWriteParameter_bis(0x00); // 6th Parameter
    lcdWriteParameter_bis(0x15); // 7th Parameter
    lcdWriteParameter_bis(0xa7); // 8th Parameter
    lcdWriteParameter_bis(0x3d); // 9th Parameter
    lcdWriteParameter_bis(0x18); // 10th Parameter
    lcdWriteParameter_bis(0x25); // 11th Parameter
    lcdWriteParameter_bis(0x2a); // 12th Parameter
    lcdWriteParameter_bis(0x2b); // 13th Parameter
    lcdWriteParameter_bis(0x2b); // 14th Parameter
    lcdWriteParameter_bis(0x3a); // 15th Parameter
    
    lcdWriteCommand_bis(FRAME_RATE_CONTROL1);
    lcdWriteParameter_bis(0x0E); // DIVA = 14
    lcdWriteParameter_bis(0x14); // VPA = 20
    
    lcdWriteCommand_bis(DISPLAY_INVERSION);
    lcdWriteParameter_bis(0x07); // NLA = 1, NLB = 1, NLC = 1 (all on Frame Inversion)
   
    lcdWriteCommand_bis(POWER_CONTROL1);
    lcdWriteParameter_bis(0x1F); // VRH = 31:  GVDD = 3,00V
          
    lcdWriteCommand_bis(POWER_CONTROL2);
    lcdWriteParameter_bis(0x00); // BT = 0: AVDD = 2xVCI1, VCL = -1xVCI1, VGH = 4xVCI1, VGL = -3xVCI1

    lcdWriteCommand_bis(VCOM_CONTROL1);
    lcdWriteParameter_bis(0x24); // VMH = 36: VCOMH voltage = 3.4
    lcdWriteParameter_bis(0x64); // VML = 100: VCOML voltage = 0
	
    lcdWriteCommand_bis(VCOM_OFFSET_CONTROL);
    lcdWriteParameter_bis(0x40); // nVM = 0, VMF = 64: VCOMH output = VMH, VCOML output = VML	
       	        
	// Set the display to on
    lcdWriteCommand_bis(SET_DISPLAY_ON);
        
}

/*LCD graphics functions*/

// Draw a line from x0, y0 to x1, y1
// Note:	This is a version of Bresenham's line drawing algorithm
//			It only draws lines from left to right!
/* |-----X------>
 * |
 * Y
 * |
 * V
 * 
 **/
void lcdLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t colour)
{
	int16_t dy = y1 - y0;
	int16_t dx = x1 - x0;
	int16_t stepx, stepy;

	if (dy < 0)
	{
		dy = -dy; stepy = -1; 
	}
	else stepy = 1; 

 	if (dx < 0)
	{
		dx = -dx; stepx = -1; 
	}
	else stepx = 1; 

	dy <<= 1; 							// dy is now 2*dy
	dx <<= 1; 							// dx is now 2*dx
 
	lcdPixel(x0, y0, colour);

	if (dx > dy) {
		int fraction = dy - (dx >> 1);	// same as 2*dy - dx
		while (x0 != x1)
		{
			if (fraction >= 0)
			{
				y0 += stepy;
				fraction -= dx; 		// same as fraction -= 2*dx
			}

   			x0 += stepx;
   			fraction += dy; 				// same as fraction -= 2*dy
   			lcdPixel(x0, y0, colour);
		}
	}
	else
	{
		int fraction = dx - (dy >> 1);
		while (y0 != y1)
		{
			if (fraction >= 0)
			{
				x0 += stepx;
				fraction -= dy;
			}

			y0 += stepy;
			fraction += dx;
			lcdPixel(x0, y0, colour);
		}
	}
}


void lcdFastVLine(int16_t x, int16_t y, int16_t h, uint16_t colour) 
{
  // Rudimentary clipping
  if((x >= width) || (y >= height)) return;
  
  if((y+h-1) >= height) {
    h = height-y;
  }
  
  setAddrWindow(x, y, x, y+h-1);
    
  while (h--) {
    lcdWriteData_bis(colour >> 8, colour);
  }
}


void lcdFastHLine(int16_t x, int16_t y, int16_t w, uint16_t colour) 
{
  // Rudimentary clipping
  if((x >= width) || (y >= height)) return;
  if((x+w-1) >= width)  {
    w = width-x;
  }
  
  setAddrWindow(x, y, x+w-1, y);
    
  while (w--) {
   lcdWriteData_bis(colour >> 8, colour);
  }
}


/*Draw a rectangle between x0, y0 and x1, y1*/
void lcdRectangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t colour)
{
	lcdLine(x0, y0, x0, y1, colour);
	lcdLine(x0, y1, x1, y1, colour);
	lcdLine(x1, y0, x1, y1, colour);
	lcdLine(x0, y0, x1, y0, colour);
}

/* Draw a filled rectangle
   Note:	y1 must be greater than y0  and x1 must be greater than x0
 			for this to work*/
void lcdFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t colour) 
{
  if((x >= width) || (y >= height)) return;
  if((x + w - 1) >= width)  {
    w = width  - x;
  }
  if((y + h - 1) >= height) {
    h = height - y;
  }
  
  setAddrWindow(x, y, x+w-1, y+h-1);
  
  for(y=h; y>0; y--) {
    for(x=w; x>0; x--) {
        lcdWriteData_bis(colour >> 8, colour);

    }
  } 
}

/* Draw a circle
 Note:	This is another version of Bresenham's line drawing algorithm.
			There's plenty of documentation on the web if you are curious
			how this works.*/
void lcdCircle(int16_t xCentre, int16_t yCentre, int16_t radius, uint16_t colour)
{
	int16_t x = 0, y = radius;
	int16_t d = 3 - (2 * radius);
 
    while(x <= y)
	{
		lcdPixel(xCentre + x, yCentre + y, colour);
		lcdPixel(xCentre + y, yCentre + x, colour);
		lcdPixel(xCentre - x, yCentre + y, colour);
		lcdPixel(xCentre + y, yCentre - x, colour);
		lcdPixel(xCentre - x, yCentre - y, colour);
		lcdPixel(xCentre - y, yCentre - x, colour);
		lcdPixel(xCentre + x, yCentre - y, colour);
		lcdPixel(xCentre - y, yCentre + x, colour);

		if (d < 0) d += (4 * x) + 6;
		else
		{
			d += (4 * (x - y)) + 10;
			y -= 1;
		}

		x++;
	}
}

void lcdFillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t colour) 
{
  lcdFastVLine(x0, y0-r, 2*r+1, colour);
  lcdFillCircleHelper(x0, y0, r, 3, 0, colour);
}

// Plot a Bitmap at the specified x, y co-ordinates (top left hand corner of Bitmap)
/*
 * Bitmap is drawn from left to right and from top to bottom 
 *
 * Convert bitmap with: http://www.riuson.com/lcd-image-converter
 *  
 */
void lcdBitmap(const unsigned char *data, uint8_t width, uint8_t height, uint8_t x, uint8_t y, uint16_t fgColour, uint16_t bgColour)
{
	uint8_t row, column, line;
	uint16_t pic;
	
	/* To speed up plotting we define a x window of 6 pixels and then
	 write out one row at a time.  This means the LCD will correctly
	 update the memory pointer saving us a good few bytes*/
	
	lcdWriteCommand_bis(SET_COLUMN_ADDRESS); // Horizontal Address Start Position
	lcdWriteParameter_bis(0x00);
	lcdWriteParameter_bis(x);
	lcdWriteParameter_bis(0x00);
	lcdWriteParameter_bis(x+(width-1));
  
	
	/*Plot the bitmap data*/
	for(line = 0; line < height/8; line++) //Write horizontal line
	{
		lcdWriteCommand_bis(SET_PAGE_ADDRESS); // Vertical Address end Position
		lcdWriteParameter_bis(0x00);
		lcdWriteParameter_bis(y);				
		lcdWriteParameter_bis(0x00);
		lcdWriteParameter_bis(0x9f); //9f = 160px
		
		lcdWriteCommand_bis(WRITE_MEMORY_START);
				
		for (row = 0; row < 8; row++)		//Write bit by bit
		{
			pic=0+(line*width);
			for (column = 0; column < width; column++)	
			{
			
				if (data[pic] & (1 << row))
					 lcdWriteData_bis(fgColour >> 8, fgColour);
				else lcdWriteData_bis(bgColour >> 8, bgColour);
				pic++;
			}
		}
	y += 8;	//increase vertical Address and Position	
	
	}//end of for line
		
}//end of lcdBitmap

/*LCD text manipulation functions*/

/* Plot a character at the specified x, y co-ordinates (top left hand corner of character)*/
void lcdPutCh(unsigned char character, uint8_t x, uint8_t y, uint16_t fgColour, uint16_t bgColour, uint8_t size)
{
	uint8_t row, column;
	
	// To speed up plotting we define a x window of 6 pixels and then
	// write out one row at a time.  This means the LCD will correctly
	// update the memory pointer saving us a good few bytes
	
	lcdWriteCommand_bis(SET_COLUMN_ADDRESS); // Horizontal Address Start Position
	lcdWriteParameter_bis(0x00);
	lcdWriteParameter_bis(x);
	lcdWriteParameter_bis(0x00);
	lcdWriteParameter_bis(x+5);
  
	lcdWriteCommand_bis(SET_PAGE_ADDRESS); // Vertical Address end Position
	lcdWriteParameter_bis(0x00);
	lcdWriteParameter_bis(y);
	lcdWriteParameter_bis(0x00);
	lcdWriteParameter_bis(0x9f); //9f = 160px
		
	lcdWriteCommand_bis(WRITE_MEMORY_START);
	
	/*Plot the font data*/
	for (row = 0; row < 8; row++)
	{
		for (column = 0; column < 6; column++)
		{
		if(size == 1){
            if ((font6x8[character][column]) & (1 << row))
            
				 lcdWriteData_bis(fgColour >> 8, fgColour);
            else lcdWriteData_bis(bgColour >> 8, bgColour);
                     }
        
        if(size >1){
            if ((font6x8[character][column]) & (1 << row))
            
				 lcdFillRect(x+(column*size), y+(row*size), size, size, fgColour);
            else lcdFillRect(x+(column*size), y+(row*size), size, size, bgColour);
                     }
        
        
        }  
                 
		
	}
}

/*Plot a string of characters to the LCD*/
void lcdPutS(char *c, int16_t x, int16_t y, uint16_t colour, uint16_t bg, uint8_t size) {
  
  while(*c) {
    if (*c == '\n') {
      y += size*8;
      x  = 0;
    } else if (*c == '\r') {
      // Skip
    } else {
     lcdPutCh(*c, x, y, colour, bg, size);
      x += size*6;
      if (0x00 && (x > (width - size*6))) {
        y += size*8;
        x = 0;
      }
    }
    c++;
  }
}

/*************************
 * 
 * LCD special functions 
 * 
 *************************/


void setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) 
{
  lcdWriteCommand_bis(SET_COLUMN_ADDRESS);
  lcdWriteParameter_bis(0x00); 
  lcdWriteParameter_bis(x0);  
  lcdWriteParameter_bis(0x00); 
  lcdWriteParameter_bis(x1);  

  lcdWriteCommand_bis(SET_PAGE_ADDRESS); 
  lcdWriteParameter_bis(0x00); 
  lcdWriteParameter_bis(y0);
  lcdWriteParameter_bis(0x00); 
  lcdWriteParameter_bis(y1); 

  lcdWriteCommand_bis(WRITE_MEMORY_START); 
}

void lcdPixel(int16_t x, int16_t y, uint16_t colour) 
{
  if((x < 0) ||(x >= width) || (y < 0) || (y >= height)) return;

  setAddrWindow(x,y,x+1,y+1);
  lcdWriteData_bis(colour >> 8, colour);
}

void lcdFillScreen(uint16_t colour) 
{
  lcdFillRect(0, 0,  width, height, colour);
}

void lcdCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t colour) 
{
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;
    if (cornername & 0x4) {
      lcdPixel(x0 + x, y0 + y, colour);
      lcdPixel(x0 + y, y0 + x, colour);
    } 
    if (cornername & 0x2) {
      lcdPixel(x0 + x, y0 - y, colour);
      lcdPixel(x0 + y, y0 - x, colour);
    }
    if (cornername & 0x8) {
      lcdPixel(x0 - y, y0 + x, colour);
      lcdPixel(x0 - x, y0 + y, colour);
    }
    if (cornername & 0x1) {
      lcdPixel(x0 - y, y0 - x, colour);
      lcdPixel(x0 - x, y0 - y, colour);
    }
  }
}

void lcdFillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, 
      int16_t delta, uint16_t colour) 
{

  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;

    if (cornername & 0x1) {
      lcdFastVLine(x0+x, y0-y, 2*y+1+delta, colour);
      lcdFastVLine(x0+y, y0-x, 2*x+1+delta, colour);
    }
    if (cornername & 0x2) {
      lcdFastVLine(x0-x, y0-y, 2*y+1+delta, colour);
      lcdFastVLine(x0-y, y0-x, 2*x+1+delta, colour);
    }
  }
}

void lcdRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t colour) 
{
  lcdFastHLine(x+r  , y    , w-2*r, colour); 
  lcdFastHLine(x+r  , y+h-1, w-2*r, colour);
  lcdFastVLine(x    , y+r  , h-2*r, colour);
  lcdFastVLine(x+w-1, y+r  , h-2*r, colour);
  lcdCircleHelper(x+r    , y+r    , r, 1, colour);
  lcdCircleHelper(x+w-r-1, y+r    , r, 2, colour);
  lcdCircleHelper(x+w-r-1, y+h-r-1, r, 4, colour);
  lcdCircleHelper(x+r    , y+h-r-1, r, 8, colour);
}

void lcdFillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, 
        int16_t r, uint16_t colour) 
{
  lcdFillRect(x+r, y, w-2*r, h, colour);
  lcdFillCircleHelper(x+w-r-1, y+r, r, 1, h-2*r-1, colour);
  lcdFillCircleHelper(x+r    , y+r, r, 2, h-2*r-1, colour);
}


void lcdTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
        int16_t x2, int16_t y2, uint16_t colour) 
{
  lcdLine(x0, y0, x1, y1, colour);
  lcdLine(x1, y1, x2, y2, colour);
  lcdLine(x2, y2, x0, y0, colour);
}

/* Draw XBitMap Files (*.xbm), exported from GIMP,
 * Usage: Export from GIMP to *.xbm, rename *.xbm to *.c and open in editor.
 * C Array can be directly used with this function */
void lcdXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t colour) 
{
  int16_t i, j, byteWidth = (w + 7) / 8;
  
  for(j=0; j<h; j++) {
    for(i=0; i<w; i++ ) {
      if(*(bitmap + j * byteWidth + i / 8) & (1 << (i % 8))) {
        lcdPixel(x+i, y+j, colour);
      }
    }
  }
}
/*convert integer to string and view on LCD*/
    void lcdPutInteger(uint16_t val, int16_t x, int16_t y, uint16_t colour, uint16_t bg, uint8_t size)
    {
    char bufor[10];
    sprintf(bufor,"%i",val); /*konwersja val na string i zapis wyniku do bufora*/
    lcdPutS(bufor, x, y, colour, bg, size);
    }
    
  /*convert float to string and view on LCD*/
    void lcdPutFloat(float val, int16_t x, int16_t y, uint16_t colour, uint16_t bg, uint8_t size)
    {
    char bufor[10];
    sprintf(bufor,"%2.1f",val); /*konwersja val na string i zapis wyniku do bufora, jedno miejsce po przecinku je?li chcesz dwa miejsca to 1f zamie? na 2f*/
    lcdPutS(bufor, x, y, colour, bg, size);
    }
   
    /*ROTATION DISPLAY value 0...3*/
     void setRotation(uint8_t m) 
{
  lcdWriteCommand_bis(SET_ADDRESS_MODE);
   int8_t rotation;
  rotation = m % 4; // can't be higher than 3
  switch (rotation) {
   case 0:
     lcdWriteParameter_bis(MADCTL_MX | MADCTL_MY | MADCTL_BGR);
     width  = SCREEN_WIDTH;
     height = SCREEN_HEIGHT;
     break;
   case 1:
     lcdWriteParameter_bis(MADCTL_MY | MADCTL_MV | MADCTL_BGR);
     width  = SCREEN_HEIGHT;
     height = SCREEN_WIDTH;
     break;
  case 2:
     lcdWriteParameter_bis(MADCTL_BGR);
     width  = SCREEN_WIDTH;
     height = SCREEN_HEIGHT;
    break;
   case 3:
     lcdWriteParameter_bis(MADCTL_MX | MADCTL_MV | MADCTL_BGR);
     width  = SCREEN_HEIGHT;
     height = SCREEN_WIDTH;
     break;
  }
}