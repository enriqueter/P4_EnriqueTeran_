/*
 * Uart_Commands.h
 *
 *  Created on: 29 nov. 2020
 *      Author: Enrique Teran
 */

#ifndef UART_COMMANDS_H_
#define UART_COMMANDS_H_

#include "rtos_uart.h"


#define EnableLowPass 		1
#define DisableLowPass 		2
#define EnableBandPass 		3
#define DisableBandPass 	4
#define EnableHighPass 		5
#define DisableHighPass 	6

typedef uint8_t answerflag;


answerflag GetAnswerValue(void);

#endif /* UART_COMMANDS_H_ */
