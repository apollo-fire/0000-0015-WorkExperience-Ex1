#ifndef DUMMY_MSP430_H_
#define DUMMY_MSP430_H_

#include <stdint.h>

/************************************************************
* STANDARD BITS
************************************************************/

#define BIT0                   (0x0001)
#define BIT1                   (0x0002)
#define BIT2                   (0x0004)
#define BIT3                   (0x0008)
#define BIT4                   (0x0010)
#define BIT5                   (0x0020)
#define BIT6                   (0x0040)
#define BIT7                   (0x0080)
#define BIT8                   (0x0100)
#define BIT9                   (0x0200)
#define BITA                   (0x0400)
#define BITB                   (0x0800)
#define BITC                   (0x1000)
#define BITD                   (0x2000)
#define BITE                   (0x4000)
#define BITF                   (0x8000)


/************************************************************
* TIMER A1
************************************************************/
#define TASSEL__SMCLK   (2*0x100u)     /* Timer A clock source select: 2 - SMCLK */
#define MC__UP          (1*0x10u)      /* Timer A mode control: 1 - Up to CCR0 */
#define ID__8           (3*0x40u)      /* Timer A input divider: 3 - /8 */
#define CCIE            (0x0010)       /* Capture/compare interrupt enable */
#define TAIE            (0x0002)       /* Timer A counter interrupt enable */
#define MC__UP          (1*0x10u)      /* Timer A mode control: 1 - Up to CCR0 */
#define MC_3            (3*0x10u)      /* Timer A mode control: 3 - Up/Down */

extern uint16_t TA1CTL;
extern uint16_t TA1CCR0;
extern uint16_t TA1CCTL0;
extern uint16_t TA1R;




/* DUMMY_MSP430_H_ */
#endif
