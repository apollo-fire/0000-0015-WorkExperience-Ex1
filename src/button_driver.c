#include <msp430.h>

#include "button_driver.h"

bool buttonEventFlag = false;

bool ButtonEventFlagGet(void)
{
    return buttonEventFlag;
}

void ButtonEventFlagSet(const bool value)
{
    buttonEventFlag = value;
}

void ButtonEventInit(void)
{
    // Timer0_A3 Setup
    // Capture rising edge,
    // Use CCI2A=ACLK,
    // Synchronous capture,
    // Enable capture mode,
    // Enable capture interrupt
    TA0CCTL2 |= CM_1 | CCIS_0 | CCIE | CAP | SCS;

    // Use SMCLK as clock source, clear TA0R
    // Start timer in continuous mode
    TA0CTL |= TASSEL_2 | MC_2 | TACLR;
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A1_VECTOR))) TIMER0_A1_ISR (void)
#else
#error Compiler not supported!
#endif
{

    switch(__even_in_range(TA0IV,TA0IV_TAIFG))
        {
            case TA0IV_NONE:
                break;                                  // No interrupt
            case TA0IV_TACCR1:
                break;                                  // CCR1 not used
            case TA0IV_TACCR2:
                buttonEventFlag = true;
                break;                                  // CCR2 not used
            case TA0IV_3:
                break;                                  // reserved
            case TA0IV_4:
                break;                                  // reserved
            case TA0IV_5:
                break;                                  // reserved
            case TA0IV_6:
                break;                                  // reserved
            case TA0IV_TAIFG:
                break;                                  // overflow
            default:
                break;
        }

    __bic_SR_register_on_exit(LPM3_bits);
}
