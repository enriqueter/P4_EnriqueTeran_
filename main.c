/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    P4_Final.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK66F18.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
#include "rtos_uart.h"
#include "I2s.h"
#include "Codec_WM8713.h"
#include "FreeRtos_I2C.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "fsl_uart.h"
#include "Filter.h"
#include "Uart_Commands.h"
/* TODO: insert other definitions and declarations here. */
#define DEMO_UART_CLK_FREQ CLOCK_GetFreq(SYS_CLK)
#define DEMO_UART          UART0

/*
 * @brief   Application entry point.
 */

SemaphoreHandle_t i2c_sem;
SemaphoreHandle_t uart_sem;

void Init_codec(void *parameters)
{
	uint8_t g_codec_sucess = freertos_i2c_fail;
	g_codec_sucess = WN8731_init();
	if(freertos_i2c_sucess == g_codec_sucess)
	{
		PRINTF("Codec configured\n\r");
	}
	xSemaphoreGive(i2c_sem);
	vTaskSuspend(NULL);
}


void Init_Filter(void *parameters)
{
	 Filter_Initialization();
}

void Init_Uart(void *parametrers)
{
 	/*UART config*/
	freertos_uart_config_t config;
	config.baudrate = 115200;
	config.rx_pin = 16;
	config.tx_pin = 17;
	config.pin_mux = kPORT_MuxAlt3;
	config.uart_number = freertos_uart0;
	config.port = freertos_uart_portB;
	freertos_uart_init(config);

	vTaskDelay(pdMS_TO_TICKS(100000));

}
void Get_Uart(void *parameters)
{
	uint8_t x;
	x = GetAnswerValue();
	PRINTF("COMMAND : %d \n", x);
	Filter_Process(x);
}
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    xTaskCreate(Init_codec, "Init_codec", 110, NULL, 1, NULL);
    xTaskCreate(Init_Filter, "Init_Filter", 110, NULL, 1, NULL);
    xTaskCreate(Init_Uart, "Init_Uart", 110, NULL, 1, NULL);
    xTaskCreate(Get_Uart, "Get_Uart",110, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1)
    {
    }
    return 0 ;
}
