/*
 * interrupt.c
 *
 *  Created on: Apr 5, 2025
 *      Author: 84903
 */

#include "Interrupt.h"
#include <main.h>
#include <base_address.h>
#include "UART.h"


void EXTI_Init(void(*inputFunction(void))){

	__HAL_RCC_GPIOD_CLK_ENABLE();
	//Rising edge
		*EXTI_RTSR &= ~(0b11 << 0);
		*EXTI_RTSR |=  (0b01 << 0);
		//Falling edge
		*EXTI_FTSR &= ~(0b11 << 0);
		*EXTI_FTSR |=  (0b01 << 0);
		//Set mask
		*EXTI_IMR &= ~(0b11 << 0);
		*EXTI_IMR |=  (0b01 << 0);

		*NVIC_ISER0 |= (1<<6);

		//MOVE VECTOR TABLE TO RAM, RAM ADDRESS 0X20000000
		uint32_t* src = 0x00; //address
		uint32_t* distance = (uint32_t*) 0x20000000;
		for(int i = 0; i < 0x198; i++){
			//distance[i] = src[i];
			*(distance + i) = *(src + i);
		}
		//Inform ARM vector table is already offset to RAM
		//uint32_t* VTOR = (uint32_t*)0xE000ED08;
		*my_VTOR = 0x20000000;
		//
		int* ptr;
		ptr = (int*) 0x20000058;
		*ptr = inputFunction;


}
//EXTI cua hang ST
//void EXTI0_IRQHandler(){
//	if(buttonState())
//		LEDblink(1, LED5_pin);
//	else
//		LEDblink(0, LED5_pin);
//}

//Tao thu vien rieng, khi chay se nhay vo ham nay, ko vo ham cua hang
//void EXTI0_custom_handler(){
//	__asm("nop"); //flag to stop the program here
//	*EXTI_PR |= (1<<0); //Clear interrupt event flag for program can continue
//}
/*void UART1_Transmit(uint8_t data)
{
	uint32_t* DR = (uint32_t*)(UART1_BASE_ADDR + 0x04);
	uint32_t* SR = (uint32_t*)(UART1_BASE_ADDR + 0x00);
	while(((*SR >> 7) & 1) == 0);
	*DR = data;
	while(((*SR >> 6) & 1) == 0);
}*/

//void DMA_init(){
//	// use DMA2, stream 2, channel 4, for uart1 Rx
//	//dia chi nguoi gui, thanh ghi nao
//	uint32_t* DMA_SxM0AR
//	// dia chi ng nhan, thanh ghi nao?
//	uint32_t* DMA SxPAR = (uint32_t*)(DMA2_BASE_ADDR +  0x18 + 0x18 × 2);
//	*DMA_S2PAR = :
//	//kich thuoc goi data - thanh ghi nao?
//	//
//}




