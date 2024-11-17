#ifndef DRV_LED
#define DRV_LED

#include "stm32h7xx_hal.h"
#include "main.h"

#define LED_ON				GPIO_PIN_RESET
#define LED_OFF				GPIO_PIN_SET

#define LED_R_ON			HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, LED_ON)
#define LED_R_OFF			HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, LED_OFF)
#define LED_R_TOG			HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin)
#define LED_R_SET(x)	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, x)

#define LED_G_ON			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, LED_ON)
#define LED_G_OFF			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, LED_OFF)
#define LED_G_TOG			HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin)
#define LED_G_SET(x)	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, x)

#define LED_B_ON			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, LED_ON)
#define LED_B_OFF			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, LED_OFF)
#define LED_B_TOG			HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin)
#define LED_B_SET(x)	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, x)

#endif