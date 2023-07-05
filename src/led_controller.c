#ifndef UNIT_TESTING
#include "led_controller.h"
#include "led_driver.h"
#endif

#define FLASH_FAST          (true)
#define FALSH_SLOW          (false)

static bool flashRate = FLASH_FAST;

void LedControllerInit(void)
{
    LedTimerInit();
}

void LedControllerChangeFlashRate(void)
{
    uint16_t rate = 0U;
    if(flashRate == FLASH_FAST)
    {
        rate = FLASH_RATE_SLOW;
    }
    else
    {
        rate = FLASH_RATE_FAST;
    }
    flashRate = !flashRate;
    LedDriverTimerLoad(rate);
}


