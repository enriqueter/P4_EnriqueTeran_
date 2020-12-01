/*
 * Filter.c
 *
 *  Created on: 30 nov. 2020
 *      Author: Enrique Teran
 */


#include "Filter.h"

/*Global variables to manage buffers and filters*/
float32_t *inputData, *outputData;

void LP_Filter()
{
	arm_fir_init_f32(&F[0], NUM_COEF, (float32_t*)&Filter_LP_coefficients[0], &FilterState[0][0], DATA_SIZE);
}

void BP_Filter()
{
	arm_fir_init_f32(&F[1], NUM_COEF, (float32_t*)&Filter_BP_coefficients[0], &FilterState[1][0], DATA_SIZE);
}

void HP_Filter()
{
	arm_fir_init_f32(&F[2], NUM_COEF, (float32_t*)&Filter_HP_coefficients[0], &FilterState[2][0], DATA_SIZE);
}



void Filter_Initialization(uint32_t *InputData)
{
	/*Input Data to be filtered*/
	inputData = (float32_t*)InputData;
	/*Output filtered Data*/
	outputData = FilterOutput;

	/*Filter Initialization */
	LP_Filter();
	BP_Filter();
	HP_Filter();
}
void Filter_Process(uint8_t filter_type)
{

	/* Filter Selection */
	switch(filter_type){
	case 0:

		/* LP_FILTER */
		arm_fir_f32(&F[0], inputData + (4 * DATA_SIZE), outputData + (4 * DATA_SIZE), DATA_SIZE);

		break;
	case 1:

		/* HP_FILTER */
		arm_fir_f32(&F[1], inputData + (4 * DATA_SIZE), outputData + (4 * DATA_SIZE), DATA_SIZE);

		break;
	case 2:

		/* BP_FILTER */
		arm_fir_f32(&F[2], inputData + (4 * DATA_SIZE), outputData + (4 * DATA_SIZE), DATA_SIZE);

		break;
	default:

		break;
	}
}
