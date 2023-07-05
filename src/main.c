#include <msp430.h> 
#include <stdbool.h>

#include"power_up_controller.h"
#include "led_controller.h"
#include "button_driver.h"
/**
 * main.c
 */
int main(void)
{
    StartUpSequence();

    while(1)
    {
        if(ButtonEventFlagGet())
        {
            LedControllerChangeFlashRate();
            ButtonEventFlagSet(false);
        }
        __bis_SR_register(LPM3_bits |GIE);           // Enter LPM0 w/ interrupts
        __no_operation();
    }

    return 0;
}


