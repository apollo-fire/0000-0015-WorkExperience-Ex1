#include <msp430.h> 
#include <stdbool.h>

/**
 * main.c
 */
int main(void)
{
    while(1)
    {
       
        __bis_SR_register(LPM3_bits |GIE);           // Enter LPM0 w/ interrupts
        __no_operation();
    }

    return 0;
}


