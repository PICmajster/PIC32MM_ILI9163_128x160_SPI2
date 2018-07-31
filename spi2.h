/*
    File Name:        :  spi1.h
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef _SPI1_H
#define _SPI1_H


void SPI2_Initialize (void);
void SPI2_Send( uint8_t data);


#endif
