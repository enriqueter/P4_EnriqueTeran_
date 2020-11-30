/*
 * Uart_Commands.c
 *
 *  Created on: 29 nov. 2020
 *      Author: Enrique Teran
 */

#include <string.h>
#include "Uart_Commands.h"
#include "fsl_port.h"
#include "rtos_uart.h"

answerflag GetAnswerValue(void)
{
	char Answer;
	uint8_t answerflag;
 	/*UART config*/
	freertos_uart_config_t config;
	config.baudrate = 115200;
	config.rx_pin = 16;
	config.tx_pin = 17;
	config.pin_mux = kPORT_MuxAlt3;
	config.uart_number = freertos_uart0;
	config.port = freertos_uart_portB;
	freertos_uart_init(config);

	vTaskDelay(pdMS_TO_TICKS(1000));// Delay task until  1s

	freertos_uart_receive(freertos_uart0, &Answer,sizeof(Answer));

	if((strcmp(Answer, "ELP") == 0))
	{
		answerflag = EnableLowPass;
	}
	else if((strcmp(Answer, "DLP") == 0))
	{
		answerflag = DisableLowPass;
	}
	else if ((strcmp(Answer, "EBP") == 0))
	{
		answerflag = EnableBandPass;
	}
	else if ((strcmp(Answer, "DBP") == 0))
	{
		answerflag = DisableBandPass;
	}
	else if ((strcmp(Answer, "EHP") == 0))
	{
		answerflag = EnableHighPass;
	}
	else if ((strcmp(Answer, "DHP") == 0))
	{
		answerflag = DisableHighPass;
	}



}
