#ifndef DRV_LPUART1
#define DRV_LPUART1

#include "main.h"

extern uint8_t rx_len;
extern uint8_t recv_end_flag;
extern uint8_t rx_buffer[200];
extern uint8_t tx_buffer[200];
extern DMA_HandleTypeDef hdma_lpuart1_tx;

void drv_lpuart1_init(void);
void drv_lpuart1_poll(void);
void drv_lpuart1_irq(void);

#endif