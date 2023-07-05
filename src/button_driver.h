#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#include <stdint.h>
#include <stdbool.h>

void ButtonEventInit(void);
bool ButtonEventFlagGet(void);
void ButtonEventFlagSet(const bool value);



#endif /* BUTTON_DRIVER_H_ */
