#ifndef UNIT_TESTING
#include "led_controller.h"
#include "led_driver.h"
#endif

#define FLASH_ONE       (0U)
#define FLASH_TWO       (1U)
#define FLASH_THREE     (2U)

static uint8_t flashRate = FLASH_ONE;

void LedControllerInit(void)
{
    LedTimerInit();
}

void LedControllerChangeFlashRate(void)
{
    uint16_t rate = 0U;
    if(flashRate == FLASH_ONE)
    {
        rate = FLASH_RATE_TWO;
        flashRate = FLASH_TWO;
    }
    else if (flashRate == FLASH_TWO)
    {
        rate = FLASH_RATE_THREE;
        flashRate = FLASH_THREE;
    }
    else
    {
        rate = FLASH_RATE_ONE;
        flashRate = FLASH_ONE;
    }
    LedDriverTimerLoad(rate);
}


