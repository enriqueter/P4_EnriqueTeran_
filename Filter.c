/*
 * Filter.c
 *
 *  Created on: 30 nov. 2020
 *      Author: Enrique Teran
 */


#include "Filter.h"


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


