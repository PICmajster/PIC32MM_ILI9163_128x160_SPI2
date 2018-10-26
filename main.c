/*
    ILI9163 128x160 LCD library for PIC32MM Microchip
    3.3 V
    File Name:        :  main.c
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
 */

#include "mcu_config_files/mcc.h"
#include "xc.h" /* wykrywa rodzaj procka i includuje odpowiedni plik naglowkowy "pic32mm0256gpm048.h"*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> /*deklaracje uint8_t itp*/
#include "delay.h"
#include "ili9163.h"
#include "bitmap.h"

int main(void) {
   
    SYSTEM_Initialize();
    SPI2_Initialize();
    lcdInitialize();
    setRotation(2); /*ROTATION DISPLAY value 0...3*/
    lcdFillScreen(BLACK);  
    // When using interrupts, you need to set the Global Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalDisable();
            
	//lcdFillRect(20, 20, 50, 50, RED);
	//lcdLine(20,50,100,50,LIME);
	//lcdPutCh('A',5,5,LIME,BLACK,2);
     //lcdPutS("ILI9163", 0, 50, ORANGE, BLACK, 3);
    //lcdBitmap(bitmap,93,128,0,0,BLACK,LIME);
    //lcdBitmap(bitmap1,128,30,0,0,BLACK,LIME);
    //lcdBitmap(bitmap3,128,30,0,31,YELLOW,RED);
    //lcdBitmap(bitmap2,128,30,0,62,LIGHT_GOLDENROD_YELLOW,BLUE);
    //lcdBitmap(bitmap4,128,30,0,93,RED,PINK);
    //lcdBitmap(bitmap5,128,30,0,124,WHITE,BLACK);
    //lcdCircle(50,50,30,ORANGE);
    //lcdFastHLine(10, 10, 50, LIME);
    //lcdFastVLine(10, 10, 50, LIME);
    //lcdFillScreen(LIME);
    //lcdFillRoundRect(10, 10, 80, 40, 10, LIME);
    //lcdRoundRect(10, 10, 70, 40, 10, LIME);
    lcdFillCircle(60, 80, 30, CYAN);
    //lcdPixel(20, 20, WHITE) ;
    //lcdPutInteger(561, 5, 5, LIME, BLACK, 2); // dispaly integer
    //lcdPutFloat(516.4, 5, 5, LIME, BLACK, 2); // display float 0.0 , size set 1 normal, > 1 bigger
    
    while (1) {

    }
}


