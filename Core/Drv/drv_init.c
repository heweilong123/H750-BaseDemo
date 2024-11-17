#include "drv_include.h"

#include <stdio.h>

void drv_init(void)
{
	/* 调试串口初始化 */
	drv_lpuart1_init();

	printf("base drv version: %s\r\n", BASE_DRV_VERSION);
}