/*
 * Button.c
 *
 *  Created on: Mar 30, 2025
 *      Author: 84903
 */
#include"Button.h"
#include"LED.h"


void buttoninit(){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	*GPIOA_MODER &= ~(0b11 << 0);
}


/*
 * Make a function can give/return you 1 for button pressed, 0 for button unpresse
 */
char buttonState(){
	if(*GPIOA_IDR & (1 << 0) == 1){
		return 1;
	}
	else {
		return 0;
	}
}


