/**
  System Interrupts Generated Driver File 

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.h

  @Summary:
    This is the generated driver implementation file for setting up the
    interrupts using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description:
    This source file provides implementations for PIC24 / dsPIC33 / PIC32MM MCUs interrupts.
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - pic24-dspic-pic32mm : 1.55
        Device            :  PIC32MM0064GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.05
        MPLAB             :  MPLAB X v4.15
*/

#include <xc.h>

/**
    void INTERRUPT_Initialize (void)
*/
void INTERRUPT_Initialize (void)
{
    // Enable Multi Vector Configuration
    INTCONbits.MVEC = 1;
    
    //    INT2I: External 2
    //    Priority: 1
        IPC1bits.INT2IP = 1;
    //    Sub Priority: 0
        IPC1bits.INT2IS = 0;
        
    //    TI: Timer 1
    //    Priority: 2
        IPC4bits.T1IP = 2;
    //    Sub Priority: 1
        IPC4bits.T1IS = 1;
}
