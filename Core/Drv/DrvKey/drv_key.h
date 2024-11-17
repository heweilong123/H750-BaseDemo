#ifndef DRV_KEY
#define DRV_KEY

#include "stm32h7xx_hal.h"
#include "main.h"

#define KEY_ON	GPIO_PIN_RESET
#define KEY_OFF	GPIO_PIN_SET

#define KEY_STATUS_POLL HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin)

extern volatile GPIO_PinState key_status;
#define KEY_STATUS_IRQ key_status

#endif