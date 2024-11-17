#ifndef DRV_LPUART1
#define DRV_LPUART1

#include "main.h"

void drv_lpuart1_printf(const char *format,  ...);
void drv_lpuart1_transmit_dma(uint8_t* data, size_t len);

void drv_lpuart1_init(void);
void drv_lpuart1_poll(void);
void drv_lpuart1_irq(void);

#endif