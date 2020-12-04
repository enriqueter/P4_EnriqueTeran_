/*
 * Uart_Commands.h
 *
 *  Created on: 29 nov. 2020
 *      Author: Enrique Teran
 */

#ifndef UART_COMMANDS_H_
#define UART_COMMANDS_H_

#include "rtos_uart.h"


#define EnableLowPass 		0
#define DisableLowPass 		1
#define EnableBandPass 		2
#define DisableBandPass 	3
#define EnableHighPass 		4
#define DisableHighPass 	5

typedef uint8_t answerflag;


answerflag GetAnswerValue(void);

#endif /* UART_COMMANDS_H_ */
