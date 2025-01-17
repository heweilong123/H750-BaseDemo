#include "main.h"
#include "drv_include.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

uint8_t rx_len=0;
uint8_t recv_end_flag=0;
uint8_t rx_buffer[200] __attribute__((section(".ARM.__at_0x38000000")));
uint8_t tx_buffer[200] __attribute__((section(".ARM.__at_0x380000E0")));
uint8_t buffer[200];

extern DMA_HandleTypeDef hdma_lpuart1_rx;
extern DMA_HandleTypeDef hdma_lpuart1_tx;
extern UART_HandleTypeDef hlpuart1;

void drv_lpuart1_transmit_dma(uint8_t* data, size_t len)
{
	/* 发送的数据必须放在tx_buffer中 */
	memset(tx_buffer, 0x00, sizeof(tx_buffer));
	memcpy(tx_buffer, data, rx_len);

	BDMA->IFCR |= 0xF0;
	HAL_UART_Transmit_DMA(&hlpuart1, tx_buffer, len);
	
	BDMA_Channel_TypeDef* bdma = hdma_lpuart1_tx.Instance;
	while(bdma->CNDTR != 0);
	USART_TypeDef* usart = hlpuart1.Instance;
	while((usart->ISR & (1<<6)) != (1<<6));
}

void drv_lpuart1_printf(const char *format,  ...)
{
	va_list args;
	va_start(args, format);
	uint8_t buffer[128] = {0};
	uint32_t length = vsnprintf((char  *)buffer, sizeof(buffer), (char  *)format, args);
	va_end(args);

	HAL_UART_Transmit(&hlpuart1, buffer, length, 0xFFFF);
}

void drv_lpuart1_init(void)
{
	/* 开启空闲中断 */
	__HAL_UART_ENABLE_IT(&hlpuart1, UART_IT_IDLE);
	
	/* 开启DMA接收 */
	HAL_UART_Receive_DMA(&hlpuart1,rx_buffer,sizeof(rx_buffer));
	recv_end_flag=0;
	rx_len = 0;
}

void drv_lpuart1_poll(void)
{
	if(recv_end_flag ==1)
	{
		drv_lpuart1_printf("%s \r\n", buffer);
		for(uint8_t i=0;i<rx_len;i++)
		{
			rx_buffer[i]=0;
		}
		rx_len=0;
		recv_end_flag=0;
	}
}

void drv_lpuart1_irq(void)
{
	/* 获取空闲中断状态 */
	uint32_t tmp_flag =__HAL_UART_GET_FLAG(&hlpuart1,UART_FLAG_IDLE);
	
	/* 空闲中断触发 */
	if((tmp_flag != RESET))
	{
		__HAL_UART_CLEAR_IDLEFLAG(&hlpuart1);
		
		/* 获取接收到长度 */
		uint32_t temp = __HAL_DMA_GET_COUNTER(&hdma_lpuart1_rx);
		
		/* DMA停止 */
		HAL_UART_DMAStop(&hlpuart1);
		
		rx_len = 200 - temp;
		memset(buffer, 0x00, sizeof(buffer));
		memcpy(buffer, rx_buffer, rx_len);
		recv_end_flag = 1;
	}

	HAL_UART_Receive_DMA(&hlpuart1, rx_buffer, 200);
}