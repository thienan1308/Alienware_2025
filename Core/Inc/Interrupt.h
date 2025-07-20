/*
 * interrupt.h
 *
 *  Created on: Apr 5, 2025
 *      Author: 84903
 */

#ifndef INC_INTERRUPT_H_
#define INC_INTERRUPT_H_
#include"base_address.h"
#include"stm32f4xx.h"
#include "Button.h"
#include "LED.h"


void EXTI_Init(void(*inputFunction(void)));
//void UART1_Transmit(uint8_t data);
void EXTI0_IRQHandler();
void EXTI0_custom_handler();


#endif /* INC_INTERRUPT_H_ */
