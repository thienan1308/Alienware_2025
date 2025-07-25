/*
 * ADC_temp.c
 *
 *  Created on: Jul 21, 2025
 *      Author: andan
 */

#include <main.h>
#include "base_address.h"
#include "stm32f4xx_hal.h"
#include "string.h"
#include <stdint.h>
#include <math.h>
#include "ADC_temp.h"

void ADC1_Init(){
	__HAL_RCC_ADC1_CLK_ENABLE();
	*ADC1_JSQR = (16 << 15);
	*ADC1_CCR |= (1 << 23);
	*ADC1_SMPR1 |= (0b111 << 18);
	*ADC1_CR2 |= (1 << 0);
}
, ADC1_temp_meas_sens(){
	*ADC1_CR2 |= (1 << 22);
	while(((*ADC1_SR >> 2) &1) == 0);
	*ADC1_SR &= ~(1 << 2);
	uint16_t adc_raw = *ADC1_JDR1;
	float vin = (adc_raw * 3.0)/4095;
	float temperature = ((vin - 0.76) / 0.0025) + 25;
	return temperature;
}
