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
	char buffer;

	uint8_t answerflag;

	buffer = 'Enter filter Selection';

	freertos_uart_send(freertos_uart0, &buffer, sizeof(buffer));
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
