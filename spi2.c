/*
    File Name:        :  spi1.c
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/

#include <xc.h>
#include "spi2.h"

void SPI2_Initialize (void)
{
    uint8_t rData;
    SPI2STAT = 0x0; /*Status clear*/
    SPI2BRG = 0x0; /*SPI2BRG 0 --> set 12.5 MHz speed*/ 
    SPI2CON2 = 0x0; /*Stops and resets the SPI2.*/
    rData=SPI2BUF; /*clears buffer*/
    SPI2CONbits.DISSDI = 1; //SDI is not used
    SPI2CONbits.MSTEN = 1; //Master mode
    SPI2CONbits.ON = 1; //SPI enabled
   
}
/*only send, not used receive data*/
void SPI2_Send( uint8_t data )
{
  
    SPI2BUF = data;  
    
    while(SPI2STATbits.SPIBUSY == 1) /*SPI peripheral is currently busy with some transactions*/
    {
    }
   
}
    
   
