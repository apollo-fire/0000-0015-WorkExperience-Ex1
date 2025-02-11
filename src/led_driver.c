

#ifndef UNIT_TESTING
#include <msp430.h>

#include "led_driver.h"
#endif

#define LED_RED             (BIT0)
#define LED_GREEN           (BIT0)
#define TOGGLE_BOUNDARY     (1U)

static uint8_t toggleCount = 0U;


void LedTimerInit(void)
{
    TA1CTL = TASSEL__SMCLK | MC__UP | ID__8;     // SMCLK, up mode
    TA1CCR0 = FLASH_RATE_ONE;
    TA1CCTL0 |= CCIE;                    // TACCR1 interrupt enabled
    TA1CTL |= TAIE;
}

void LedDriverTimerLoad(const uint16_t value)
{
    TA1CTL &- ~ MC_3;
    TA1R = 0U;
    TA1CCR0 = value;
    TA1CTL |= MC__UP;
}

// Timer A0 interrupt service routine
#ifndef UNIT_TESTING
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = TIMER1_A0_VECTOR
__interrupt void LedControllerISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif /*defined(__GNUC__)*/
#else
void LedControllerISR (void)
#endif /*#ifndef UNIT_TESTING*/
{
    switch(__even_in_range(TA1IV,TA0IV_TAIFG))
    {
        case TA1IV_NONE:
            __no_operation();
            break;                                  // No interrupt
        case TA1IV_TAIFG:
            if(toggleCount >= TOGGLE_BOUNDARY)
            {
                P4OUT ^= LED_RED;
                P1OUT ^= LED_GREEN;
                toggleCount = 0U;
            }
            else
            {
                toggleCount++;
            }
            break;                                  // overflow
        default:
            break;
    }

    __bic_SR_register_on_exit(LPM3_bits);

}
