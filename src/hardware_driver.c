

#ifndef UNIT_TESTING
#include <msp430.h>
#include "hardware_driver.h"
#endif

#define LED_RED     (BIT0)
#define LED_GREEN   (BIT0)

void PortSetup(void)
{
    // Configure GPIO
    P1DIR = LED_RED;
    P4DIR = LED_GREEN;

    // Start LEDs on
    P1OUT = LED_RED;
    P4OUT = LED_GREEN;

    //Button input
    P1SEL0 = BIT6;                                 // TA0.CCI2A input capture pin, second function
    P1REN = BIT6;                                  // enable internal pull-down resistor=*/
}
