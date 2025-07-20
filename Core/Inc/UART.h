/*
 * UART.h
 *
 *  Created on: May 25, 2025
 *      Author: andan
 */

#ifndef INC_UART_H_
#define INC_UART_H_

void UART1_Init();
void UART1_Transmit_1byte(uint8_t data);
void UART1_Trans_String(char* msg);
char UART1_Receive_1byte();
void USART1_IRQHandler();
//void UART1_rx_handler();
void dma2_UART1_rx_Init();
void DMA2_Stream2_IRQHandler();

#endif /* INC_UART_H_ */
