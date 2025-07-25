#include<stdio.h>
#include<stdint.h>
#include"LED.h"
#include"Button.h"
#include"Interrupt.h"
#include"UART.h"
#include"SPI.h"
#include"Flash_Eraser.h"
#include"string.h"

#include"ADC_temp.h"
int cnt = 1000;


//void EXTI0_IRQHandler(){
//	if(buttonState() == 1){
//		LEDblink(1, LED5_pin);
//	} else{
//		LEDblink(0, LED5_pin);
//	}
//	*EXTI_PR |= (1<<0);
//}

void function(){
	if(buttonState() == 1){
			LEDblink(1, LED6_pin);
		} else{
			LEDblink(0, LED6_pin);
		}
	*EXTI_PR |= (1<<0);
}

//FLASH_ERASER
//char storeData[100];
//int idx;
//void USART1_IRQhandler(){
//	storeData[idx++] = UART_Receiver();
//	if (strstr(storeData, "blue led on\n"))
//	{
//		LEDblink(1, LED6_pin);
//		UART_Print_Log("--> ON LED OK\n");
//	}
//	else if(strstr(storeData, "blue led off"))
//	{
//		LEDblink(0, LED6_pin);
//		UART_Print_Log("--> OFF LED OK\n");
//	}
//	else if(strstr(storeData, "red led on"))
//	{
//		LEDblink(1, LED5_pin);
//		UART_Print_Log("--> OFF LED OK\n");
//	}
//	else if(strstr(storeData, "red led off"))
//	{
//		LEDblink(0, LED5_pin);
//		UART_Print_Log("--> OFF LED OK\n");
//	}
//	else
//	{
//		UART_Print_Log("--> COMMAND NOT FOUND\n");
//	}
//	memset(storeData, 0,  sizeof(storeData));
//	idx = 0;
//}

//ADC_temp
float temp;
int main(){
	LEDinit();
	HAL_Init();
	buttoninit();
	EXTI_Init(function);
	UART1_Init();
	SPI_Init();
	Timer_init();
	dma2_UART1_rx_Init();
	ADC1_Init();

	//ADC1_temp
	while(1){
		LEDblink(1, LED4_pin);
		HAL_Delay(500);
		LEDblink(0, LED4_pin);
		HAL_Delay(500);
		temp = ADC1_temp_meas_sens();
		UART_trans_float(temp);
		UART1_Trans_String("\r\n");
	}
	return 0;

/*
	//Timer
	while(1){
		LEDblink(1, LED3_pin);
		delay_1s();
		LEDblink(0, LED3_pin);
		delay_1s();
	}
	return 0;
	*/
	//flash_eraser
/*	char hello_msg[] = "hello";
	Flash_eraser_sector(1);
	for(int i = 0; i < sizeof(hello_msg); i++)
	{
		Flash_programming(0x08000000 + i, hello_msg[i]);
	}
	*/

	//UART1

//	while(1){
//		if(UART1_Receive_1byte() == 'a')
//			LEDblink(1, LED3_pin);
//		else if (UART1_Receive_1byte() == 'b')
//			LEDblink(0, LED3_pin);  //cau 1

//
//		LEDblink(1, LED4_pin);
//		HAL_Delay(1000);
//		LEDblink(0, LED4_pin);
//		HAL_Delay(1000);

		//UART1_Trans_String("hello word\r\n");
//		LEDblink(1, LED3_pin);
//		HAL_Delay(cnt);
		//LEDblink(0, LED3_pin);
		//HAL_Delay(1000);
//
//	}
//	return 0;

/*
	//SPI
	char id = SPI_Read(0x0f); //read to check the addr of WHO_AM_I
	id = SPI_Read(0x20);

	SPI_Write(0x20, 0x0f);
	id = SPI_Read(0x20);

	while(1){
		//SPI_Read (0x0f);
	}
	return 0;
*/
	//	while(1){
	//		LEDblink(1, LED3_pin);
	//		HAL_Delay(200);
	//		LEDblink(0, LED3_pin);
	//		HAL_Delay(200);
	//
	//		LEDblink(1, LED4_pin);
	//		HAL_Delay(200);
	//		LEDblink(0, LED4_pin);
	//		HAL_Delay(200);
	//

	/*while(1){
		UART1_Transmit('a');
		LEDblink(1, LED3_pin);
		HAL_Delay(cnt);
		LEDblink(0, LED3_pin);
		HAL_Delay(100);
//		if(buttonState()  == 0){
//			LEDblink(0, LED3_pin);
//		} else{
//			LEDblink(1, LED3_pin);
	}*/
}





