#ifndef DRV_LED
#define DRV_LED

#include "stm32h7xx_hal.h"
#include "main.h"

#define LED_R_ON	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, RESET)
#define LED_R_OFF	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, SET)
#define LED_R_TOG	HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin)

#define LED_G_ON	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET)
#define LED_G_OFF	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, SET)
#define LED_G_TOG	HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin)

#define LED_B_ON	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET)
#define LED_B_OFF	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, SET)
#define LED_B_TOG	HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin)

#endif