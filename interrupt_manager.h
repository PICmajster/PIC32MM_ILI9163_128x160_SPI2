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


#ifndef _INTERRUPT_MANAGER_H
#define _INTERRUPT_MANAGER_H

/**
  @Summary
    Initializes the interrupt priorities of the PIC32MM0064GPM048

  @Description
    This routine sets the interrupt priorities of the modules that have been configured
    for the PIC32MM0064GPM048

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        INTERRUPT_Initialize ();
    }
    </code>

*/
void INTERRUPT_Initialize(void);

/**
  @Summary
    Enables global interrupts of the PIC32MM0064GPM048

  @Description
    This routine enables the global interrupt bit for the PIC32MM0064GPM048

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        INTERRUPT_GlobalEnable ();
    }
    </code>

*/
inline static void INTERRUPT_GlobalEnable(void)
{
    __builtin_enable_interrupts();
}

/**
  @Summary
    Disables global interrupts of the PIC32MM0064GPM048

  @Description
    This routine disables the global interrupt bit for the PIC32MM0064GPM048

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        INTERRUPT_GlobalDisable ();
    }
    </code>

*/
inline static void INTERRUPT_GlobalDisable(void)
{
    __builtin_disable_interrupts();
}

#endif