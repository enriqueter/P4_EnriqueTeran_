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
	uint8_t Answer1;
	uint8_t Answer2;
	uint8_t Answer3;

	uint8_t answerflag;

	 uint8_t buffer[]= "Enter filter Selection \n\r\nActivar Pasa bajas (ELP)\n\rDesactivar Pasa bajas (DLP)\n\rActivar Pasa altas (EHP)\n\rDesactivar Pasa altas (DHP)\n\rActivar Pasa bandas (EBP)\r\nDesactivar Pasa bandas (DBP)\r\n";

	freertos_uart_send(freertos_uart0, &buffer, sizeof(buffer)  -1);
	freertos_uart_receive(freertos_uart0, &Answer1,sizeof(Answer1));
	freertos_uart_send(freertos_uart0, &Answer1,sizeof(Answer1));
	//freertos_uart_receive(freertos_uart0, &Answer2,sizeof(Answer2));
	//freertos_uart_send(freertos_uart0, &Answer2,sizeof(Answer2));
	//freertos_uart_receive(freertos_uart0, &Answer3,sizeof(Answer3));
	//freertos_uart_send(freertos_uart0, &Answer3,sizeof(Answer3));

	if((strcmp(Answer1, "E") == 0))
	{
		freertos_uart_receive(freertos_uart0, &Answer2,sizeof(Answer2));
		freertos_uart_send(freertos_uart0, &Answer2,sizeof(Answer2));
		if((strcmp(Answer2, "L") == 0))
		{

			uint8_t buffer1[] ="LP FILTER  ENABLE";
		    answerflag = EnableLowPass;
		    freertos_uart_send(freertos_uart0, &buffer1, sizeof(buffer1)  -1);

		}
		else if((strcmp(Answer2, "H") == 0))
		{
			uint8_t buffer2[] ="HP FILTER  ENABLE";
			answerflag = EnableHighPass;
			 freertos_uart_send(freertos_uart0, &buffer2, sizeof(buffer2)  -1);
		}
		else if((strcmp(Answer2, "B") == 0))
		{
			uint8_t buffer3[]="BP FILTER  ENABLE";
			answerflag = EnableBandPass;
			freertos_uart_send(freertos_uart0, &buffer3, sizeof(buffer3)  -1);
		}
	}else if((strcmp(Answer1, "D") == 0))
	{
		freertos_uart_receive(freertos_uart0, &Answer2,sizeof(Answer2));
		freertos_uart_send(freertos_uart0, &Answer2,sizeof(Answer2));
		if((strcmp(Answer2, "L") == 0))
		{
			uint8_t buffer4[] ="LP FILTER  DISABLE";
			answerflag = DisableLowPass;
			freertos_uart_send(freertos_uart0, &buffer4, sizeof(buffer4)  -1);
		}
		else if((strcmp(Answer2, "H") == 0))
		{
			uint8_t buffer5[] ="HP FILTER  DISNABLE";
			answerflag = DisableHighPass;
			freertos_uart_send(freertos_uart0, &buffer5, sizeof(buffer5)  -1);
		}
		else if((strcmp(Answer2, "B") == 0))
		{
			uint8_t buffer6[] ="BP FILTER  DISNABLE";
			answerflag = DisableBandPass;
			freertos_uart_send(freertos_uart0, &buffer6, sizeof(buffer6)  -1);
		}
	}


}
