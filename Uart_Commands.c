/*
 * Uart_Commands.c
 *
 *  Created on: 29 nov. 2020
 *      Author: Enrique Teran
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK66F18.h"
#include "fsl_debug_console.h"
#include <string.h>
#include "Uart_Commands.h"
#include "fsl_port.h"
#include "rtos_uart.h"

answerflag GetAnswerValue(void)
{
	char Answer;
	char buffer;

	uint8_t answerflag;

	buffer = 'Enter filter Selection';

	freertos_uart_send(freertos_uart0, &buffer, sizeof(buffer));
	freertos_uart_receive(freertos_uart0, &Answer,sizeof(Answer));

	if((strcmp(Answer, "ELP") == 0))
	{
		answerflag = EnableLowPass;
		PRINTF("LP FILTER  ENABLE");
	}
	else if((strcmp(Answer, "DLP") == 0))
	{
		answerflag = DisableLowPass;
		PRINTF("LP FILTER  DISABLE");
	}
	else if ((strcmp(Answer, "EBP") == 0))
	{
		answerflag = EnableBandPass;
		PRINTF("BP FILTER  ENABLE");
	}
	else if ((strcmp(Answer, "DBP") == 0))
	{
		answerflag = DisableBandPass;
		PRINTF("BP FILTER  DISABLE");
	}
	else if ((strcmp(Answer, "EHP") == 0))
	{
		answerflag = EnableHighPass;
		PRINTF("HP FILTER  ENABLE");
	}
	else if ((strcmp(Answer, "DHP") == 0))
	{
		answerflag = DisableHighPass;
		PRINTF("HP FILTER  DISABLE");
	}



}
