/*
 * TIMER.h
 *
 *  Created on: Jun 26, 2025
 *      Author: andan
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

void Timer_init();
void delay_1s();
void TIM1_UP_TIM10_IRQHandler();
void delay(int time);

#endif /* INC_TIMER_H_ */
