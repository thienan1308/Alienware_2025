/*
 * UART.c
 *
 *  Created on: May 25, 2025
 *      Author: andang
 */
#include <main.h>
#include "base_address.h"
#include "stm32f4xx_hal.h"
#include "string.h"
#include "LED.h"



void UART1_Init(){

	/* Config GPIOB
	-set PB6 as UART1_TX and PB7 as UART1_RX table 9_datasheet_p.49
	-PB6 alternate function AF07
	-PB7 alternate function AF07
	*/
	__HAL_RCC_GPIOB_CLK_ENABLE();
	//PB6 set moder6; PB7 moder7
	//Set alternate function mode (set 10)
	*GPIOB_MODER &= ~ (0b1111 << 12); //Clear bit PB6
	*GPIOB_MODER |=   (0b10  << 12) | (0b10 << 14); //Set alter func bit for PB6 and PB7

	//Cuz we use pin 6 and 7, so using alternate function low
	*GPIOB_AFRL &= ~(0xFF << 24); //Clear bit AF7 from bit 24 and 28 for port B6 and B7
	*GPIOB_AFRL |=  (0b0111 << 24) | (0b0111 <<28); //Set bit AF7 for pin b6 and b7


	/* Config UART
	-set baudrate 9600bps (bit/sec)
	-data frame:
			+Data size: 8 bits
			+Parity: even
			+Enable transmitter and receiver
			+Enable UART
			+To compute the baudrate, we use the formula:
		+baudrate = Fck / ((8*(2-OVER8)*USART_DIV) => USART_DIV = ...
		+Fck (default value of clock RCC provide for UART is 16Mhz = 16.000.000 Hz
		+OVER8 = 0
		+Desired Baudrate: 9600
		+=> UART_DIV = 104.16667
		=> DIV_Mantissa = 104
		=> DIV_Fraction = 0.166666667 * 16 = 2.66666667 (lam tron len 3)
		+DIV_Mantissa = 104
		+DIV_Fraction = 0.166666667 * 15 = 2.5 (round to 3)

		*/
	//the note for this part in samsung tablet due to formula reason.
	__HAL_RCC_USART1_CLK_ENABLE();	// the default RCC clock automatically provide 16Mhz
	*UART1_BRR = (104 << 4) | (3 << 0); //baudrate register
	//Set data size - word length that is bit 12 CR1
	*UART1_CR1 |= (1 << 12); //need parity so choose "1", data bits + parity = 9 data bits
	//Set Parity bit 10 (PCE - parity control enable) of CR1
	*UART1_CR1 |= (1 << 10);
	//Enable transmitter
	*UART1_CR1 |= (1 << 3);
	//Enable receiver - CR1 bit 3 TE(Trans enable), bit 2 RE (Receiver enable)
	*UART1_CR1 |= (1 << 2);
	//Enable UART - CR1 bit 13 UE (USART enable)
	*UART1_CR1 |= (1 << 13);

#if 0
	//Enable RXNE interrupt (enable su kien ngat), when RXNE is set, UART1 generate interrupt event send to nvic
	*UART1_CR1 |= (1 << 5);
	//NVIC approve interrupt event, which is send from UART1
	//in vector table, USART1 at position number 37
	uint32_t* NVIC_ISER1 = (uint32_t*)(0xE000E104); //Because the address of ISER0  is 0xE000E100 so ISER1 + theem 4 bit
	*NVIC_ISER1 |= 1 << (37 - 32);
#else
	//when RXNE is set, send signal to DMA2, DMA2 move data to RAM
	uint32_t* DMA_CR3 = (uint32_t*)(0x40011014);
	*DMA_CR3 |= (1 << 6);
#endif
}

//(send 1 byte only)
void UART1_Transmit_1byte(uint8_t data){
	while(((*UART1_SR >> 7) & 1) == 0); //wait DR empty
	*UART1_DR = data;
	while(((*UART1_SR >> 6) & 1) == 0); //wait transmitter of UART1 complete transfer
	*UART1_SR &= ~(1 << 6);

}

//Send string
void UART1_Trans_String(char* msg){
	int msg_len = strlen(msg);
	for(int i = 0; i < msg_len; i++)
	{
		UART1_Transmit_1byte(msg[i]);
	}
}

//To send data from computer to uart
char UART1_Receive_1byte(){
	while(((*UART1_SR >> 5) & 1) == 0); //if bit 5 = 0, still wait; wait REXNE flag to read receive data
	char receive_data = *UART1_DR; //Read the receive data
	return receive_data;
}

//Library of ST
char recei_data[32];
int rx_index = 0;
void USART1_IRQHandler(){
	recei_data[rx_index++] = *UART1_DR; //Khi DR doc du lieu, no se tu clear interrupt flag, no need code for clear flag
	if(strstr(recei_data, "LED ON") != NULL){
		LEDblink(1, LED5_pin);
		//UART1_Trans_String("LED turned ON\r\n");
		rx_index = 0;
		memset(recei_data, 0, sizeof(recei_data));
	}
	else if(strstr(recei_data, "LED OFF") != NULL){
		LEDblink(0, LED5_pin);
		//UART1_Trans_String("LED turned OFF\r\n");
		rx_index = 0;
		memset(recei_data, 0, sizeof(recei_data));
	}

}

char rx_buf[100];
#define DMA2_ADDR 0x40026400
void dma2_UART1_rx_Init(){
	__HAL_RCC_DMA2_CLK_ENABLE();
	//Using DMA2,  stream 2, channel 4 (table 28, ref manual for DMA)
	uint32_t* DMA_S2CR = (uint32_t*)(DMA2_ADDR + 0x10 + 0x18 * 5); //(9.5.5 in ref manual)
	*DMA_S2CR &= ~ (0b111 << 25);
	*DMA_S2CR |= (0b100 << 25); //Select channel 4 for stream 2
	*DMA_S2CR |= (1 << 10); //Enable memory increment mode
	*DMA_S2CR |= (1 << 8);
	*DMA_S2CR |= (1 << 4); //Enable transfer complete interrupt
	*DMA_S2CR |= (1 << 0); //Enable stream 2

	uint32_t* DMA_S2PAR = (uint32_t*)(DMA2_ADDR + 0x18 + 0x18 * 5); //(9.5.5 in ref manual)
	*DMA_S2PAR = 0x40011004;

	uint32_t* DMA_S2NDTR = (uint32_t*)(DMA2_ADDR + 0x14 + 0x18 * 5); //(9.5.5 in ref manual)
	*DMA_S2NDTR = 7;

	uint32_t* DMA_S2M0AR = (uint32_t*)(DMA2_ADDR + 0x1C + 0x18 * 5); //(9.5.5 in ref manual)
	*DMA_S2M0AR = rx_buf;

	uint32_t* NVIC_ISER2 = (uint32_t*)(0xE000E108);
	*NVIC_ISER2 |= 1 << (68-64);

	/* receive: 7 bytes data
	 * from: UART DR
	 * to: receive_data (0x2000
	 */
}

void DMA2_Stream2_IRQHandler(){
	__asm("NOP");
	//clear the interrupt flag -> transfer complete interrupt (different to USART1, need to clear flag)
	uint32_t* DMA_HIFCR = (uint32_t*)(DMA2_ADDR + 0x0C);
	*DMA_HIFCR |= 1 << 11; //bit 11

}




