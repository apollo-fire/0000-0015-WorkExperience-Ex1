#include <msp430.h>

#include "power_up_controller.h"
#include "hardware_driver.h"
#include "led_controller.h"
#include "button_driver.h"

void StartUpSequence(void)
{
    // Stop WDT
    WDTCTL = WDTPW | WDTHOLD;
    PortSetup();
    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    LedControllerInit();
    ButtonEventInit();
}

