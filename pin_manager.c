/*
    File Name:        :  pin_manager.c
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/


#include <xc.h>
#include "pin_manager.h"
#include "mcc.h"

/**
    void PIN_MANAGER_Initialize(void)
*/
void PIN_MANAGER_Initialize(void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;
    LATC = 0x0000;
    LATD = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    /*set Input for PGD1 and PGC1*/
    TRISBbits.TRISB0 = 1 ; /*set input*/
    TRISBbits.TRISB1 = 1 ; /*set input*/
    /*set Output for LED*/
    TRISBbits.TRISB6 = 0 ; /*LED on board, set output*/
     /*set Output for SPI2*/
    TRISBbits.TRISB3 = 0 ; /*SDO Master set output*/
    TRISBbits.TRISB8 = 0 ; /*SCK Master set output*/
   
    /*set Output for LCD ILI9631*/
    TRISCbits.TRISC3 = 0; /*A0, set output*/
   
        
    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPDA = 0x0000;
    CNPDB = 0x0000;
    CNPDC = 0x0000;
    CNPDD = 0x0000;
    CNPUA = 0x0000;
    CNPUB = 0x0000;
    CNPUC = 0x0000;
    CNPUD = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;
    ODCC = 0x0000;
    ODCD = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    /*set pins for PGD1 and PGC1*/
    ANSELBbits.ANSB0 = 0 ; /*set digital pin for PGD1*/
    ANSELBbits.ANSB1 = 0 ; /*set digital pin for PGC1*/
   
    ANSELBbits.ANSB3 = 0 ; /*set digital out for RB3*/
    ANSELCbits.ANSC5 = 0; /*set digital out for RC5*/
        
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    SYSTEM_RegUnlock();          /*unlock PPS*/
    RPCONbits.IOLOCK = 0;

    //RPINR11bits.SDI2R = 0x0018; /*RA9->SPI2:SDI2;*/ not used
    RPOR2bits.RP9R = 0x8;    /*set RB3 for SPI2:SDO2;*/
    RPOR3bits.RP13R = 0x9;   /*set RB8 for SPI2:SCK2OUT;*/
    //RPOR2bits.RP12R = 0xA;   /*RB7-> SS2OUT*/ not used
    
    RPCONbits.IOLOCK = 1;    /*lock   PPS*/
	
    SYSTEM_RegLock();

}
/*Piny analogowe oznaczone w MCU jako ANx, ustawienie : 0 - cyfrowe / 1 - analogowe
ANSELA
RA0 --> ANSA0
RA1 --> ANSA1
RA2 --> ANSA2
RA3 --> ANSA3
ANSELB
RB0 --> ANSB0
RB1 --> ANSB1
RB2 --> ANSB2
RB3 --> ANSB3
RB4 --> ANSB4
ANSELC
RC0 --> ANSC0
RC1 --> ANSC1
RC5 --> ANSC5
RC8 --> ANSC8
 
 UWAGA !!! nie wszystkie piny analogowe sa ujete w strukturze ANSELxbits.ANSxx
 np.RA6,RB13,RB14,RB15 .W takim przypadku musimy uzyc zapisu bezposrednio do rejestru
 ANSELx = wartosc ;
 Je?li zmieniamy rodzaj obudowy MCU koniecznie zwrocic na to uwage. W datasheet
 z opisem w tabelce funkcjonalnosci pinow odczytamy piny oznaczone ANx i te podlegaja
 uzycia wpisu w rejestr ANSELx aby uzywac je jako cyfrowe.
 */