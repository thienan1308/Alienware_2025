/*
 * TIMER.c
 *
 *  Created on: Jun 26, 2025
 *      Author: andan
 */
#include <main.h>
#include "base_address.h"
#include "stm32f4xx_hal.h"

void Timer_init(){
	__HAL_RCC_TIM1_CLK_ENABLE();
	//Timer 1 second so prescaler should be 16.000.000 / 16000 = 1000xung/s
	//Prescaler = 16000 and ARR = 1000
	*TIM1_PSC = 16 - 1; //Avoid to divide to 0, so the producer have set that if prescaler value is 0, the RCC is auto divide to 1. If 1, it divide to 2 and the same for others
	*TIM1_ARR = 1000;
	//Enable counter - bit 0 thanh ghi CR1
	*TIM1_CR1 |= (1 << 0);

	*NVIC_ISER0 |= (1 << 25);
	*TIM1_CR1 |= (1 << 0); //count enable
}

void delay_1s(){
	//To alarm that counter have counted 1s - using thanh ghi status to update trang thai SR
	while(((*TIM1_SR >> 0) & 1) == 0); //if == 0, stay still. If == 1, reinitialize by counter have counted reach to ARR value which is 1000
	*TIM1_SR &= ~(1 << 0); //CLear bit
}

int time_cnt = 0;

void TIM1_UP_TIM10_IRQHandler(){
	time_cnt++;
	*TIM1_SR &= ~(1 << 0);
}
void delay(int time){
	time_cnt = 0;
	while(time_cnt < time);
}


