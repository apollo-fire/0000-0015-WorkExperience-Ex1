#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include <stdint.h>
#include <stdbool.h>

#define FLASH_RATE_FAST     (25000U)
#define FLASH_RATE_SLOW     (50000U)

void LedTimerInit(void);
void LedDriverTimerLoad(const uint16_t value);


#endif /* LED_DRIVER_H_ */
