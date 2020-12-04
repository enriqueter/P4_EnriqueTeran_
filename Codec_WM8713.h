/*
 * Codec_WM8713.h
 *
 *  Created on: 13 nov. 2020
 *      Author: etera
 */

#ifndef CODEC_WM8713_H_
#define CODEC_WM8713_H_


#include "freertos_i2c.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "stdint.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

/*WM8713 CODEC REGISTERS*/
#define WM8731_LEFT_LINE_IN			0x00
#define WM8731_RIGHT_LINE_IN		0x01
#define WM8731_LEFT_HEADPHONE_OUT	0x02
#define WM8731_RIGHT_HEADPHONE_OUT  0x03
#define WM8731_ANALOGUE_AUDIO		0x04
#define WM8731_INTERFACE_FORMAT     0x07
#define WM8731_SAMPLING_CONTROL     0x08
#define WM8731_DIGITAL_PATH
#define WM8731_POWER_DOWN_REGISTER	0x0C
#define WM8731_RESET_REGISTER	    0x0F
#define WM8731_CODEC_ENABLE			0x12

/*WM8713 CODEC DEVICE ADDRESS*/
#define WM8731_SLAVE_ADDRESS		0x1A

/*WM873 CODEC DEFINITIONS SETUP*/
#define _WM8731_LEFT_LINEIN         0X17
#define _WM8731_RIGHT_LINEIN        0X17
#define _WM8731_LEFT_HP             0X79
#define _WM8731_RIGHT_HP            0X79
#define _WM8731_ANALOGAUDIO         0X11
#define _WM8731_DIGITALAUDIO        0X00
#define _WM8731_POWER               0X00
#define _WM8731_DAIF                0X52
#define _WM8731_SAMPLING            0X00
#define _WM8731_ACTIVATE            0X01
#define _WM8731_DEACTIVATE          0X00
#define _WM8731_RESET               0X00



/*WM8713 Initialization function*/
freertos_i2c_flag_t WM8731_init(void);



#endif /* CODEC_WM8713_H_ */
