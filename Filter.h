/*
 * Filter.h
 *
 *  Created on: 30 nov. 2020
 *      Author: Enrique Terán
 */

#ifndef FILTER_H_
#define FILTER_H_

#include "arm_math.h"
/*Filter Definitions*/
#define NUM_COEF 41
#define DATA_SIZE 1024
#define MAX_DATA 4*1024


static float32_t FilterState[3][DATA_SIZE + NUM_COEF -1];
static float32_t FilterOutput[MAX_DATA];


/*Filter Initialization Functions*/
void LP_Filter();
void BP_Filter();
void HP_Filter();
/*Filters Initialization and data buffer creation*/
void Filter_Initialization();
/*Processing of Data passed through the selected filter */
void Filter_Process(uint8_t filter_type);
#endif /* FILTER_H_ */
