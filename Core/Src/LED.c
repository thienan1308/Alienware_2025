/*
 * LED.c
 *
 *  Created on: Mar 30, 2025
 *      Author: 84903
 */
#include "LED.h"

void LEDinit(){
	__HAL_RCC_GPIOD_CLK_ENABLE();
	//LED14
	*GPIOD_MODER &= ~(0b11 << 24); //RESET PD12
	*GPIOD_MODER |=  (0b01 << 24); //Set PD12 as output
	//LED13
	*GPIOD_MODER &= ~(0b11 << 26); //RESET PD13
	*GPIOD_MODER |=  (0b01 << 26); //Set PD13 as output
	//LED15
	*GPIOD_MODER &= ~(0b11 << 28); //RESET PD14
	*GPIOD_MODER |=  (0b01 << 28); //Set PD14 as output
	//LED16
	*GPIOD_MODER &= ~(0b11 << 30); //RESET PD15
	*GPIOD_MODER |=  (0b01 << 30); //Set PD15 as output
}


void LEDblink(int on_off, uint8_t inputLEDpin){
	if (on_off == 1){
		*GPIOD_BSRR = (1 << inputLEDpin);
	} else {
		*GPIOD_BSRR = (1 << (inputLEDpin + 16));
	}
}



