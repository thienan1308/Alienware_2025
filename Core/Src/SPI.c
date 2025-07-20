/*
 * SPI.c
 *
 *  Created on: Jun 1, 2025
 *      Author: andan
 */

#include <main.h>
#include "base_address.h"
#include "stm32f4xx_hal.h"

void SPI_Init(){
	/*
	 * Config PA5 -> SPI1_SCLK
		PA7-> SPI1_MOSI
		PA6-> sPI1_MISO
		PE3-> output by GPIO for CS(chip select)
		}
		-stm32 works as master mode
		-using software Slave management. (Use GPIO for CS pin)
		-Config clock for SCLK
		-enable SPI
		-Gyroscope works as Slave mode

	 */

	//Set GPIO pin for PA5 as SCLK
	__HAL_RCC_GPIOA_CLK_ENABLE();
	*GPIOA_MODER &=  ~(0b11 << 10);
	*GPIOA_MODER |=   (0b10 << 10); //alternate func mode
	//Set GPIO pin for PA6 as MISO
	*GPIOA_MODER &=  ~(0b11 << 12);
	*GPIOA_MODER |=   (0b10 << 12); //alternate func mode
	//Set GPIO pin for PA7 as MOSI
	*GPIOA_MODER &=  ~(0b11 << 14);
	*GPIOA_MODER |=   (0b10 << 14); //alternate func mode
	__HAL_RCC_GPIOE_CLK_ENABLE();
	//Set GPIO pin for CS as output for PE3
	*GPIOE_MODER &=  ~(0b11 << 6);
	*GPIOE_MODER |=   (0b01 << 6); //alternate func mode

	//Alternative function for PA5 - table 9 pp.49 datasheet
	*GPIOA_AFRL &= ~ (0b1111 << 20);
	*GPIOA_AFRL |=   (0b0101 << 20); //AF5: 0101; for PA5 start from bit 20
	//Alternative function for PA6 - table 9 pp.49 datasheet
	*GPIOA_AFRL &= ~ (0b1111 << 24);
	*GPIOA_AFRL |=   (0b0101 << 24);
	//Alternative function for PA7 - table 9 pp.49 datasheet
	*GPIOA_AFRL &= ~ (0b1111 << 28);
	*GPIOA_AFRL |=   (0b0101 << 28);

	//enable SPI
	__HAL_RCC_SPI1_CLK_ENABLE();
	//Master config for STM32
	*SPI1_CR1 |=  (1 << 2);
	//Software slave management and internal slave selection
	*SPI1_CR1 |=  (1 << 9) | (1 << 8);
	//Config clock for SCLk - baudrate control - bit5:3
	*SPI1_CR1 |=   (0b011 << 3);
	//Enable SPI
	*SPI1_CR1 |= (1 << 6);
}

char SPI_Read(char reg_addr){
	/*-set PE3 (CS) to low -> active slave
		-send register address of slave (write register address to DR)
		-Read DR ->clear garbage data (
		-Send dumy data (to generate clock for slave in order to send data to from slave to master)
		-Read DR
		-Set PE3 to high - inactive slave*/
	*GPIOE_ODR &= ~(1 << 3); //set PE3 to LOW to active SLAVE
	//check SPI is busy or not
	while(((*SPI1_SR >> 7) & 1) == 1); // if == 1, SPI busy and stuck in while loop, no move on to next

	/* In I3G4250D document, 5.2.1 SPI read for gyroscope
		-figure 13, SDI waveform, the 7th bit from right to left which is RW bit (read and write bit)
		- Value for bit 7 is 1 to set to READ status
		- so dia chi thanh ghi o bit 7 phai = 1 (1<<7) to set to READ status
	*/
	*SPI1_DR = reg_addr | (1 << 7);  //ghi du lieu vao DR, send data to gyro
	//check tx buffer (transmitter) empty or not
	while(((*SPI1_SR >> 1) & 1) == 0); //at bit 1, 0 for tx buffer not empty, stuck in while loop.
	while(((*SPI1_SR >> 7) & 1) == 1);

	/*check rx buffer (receiver) empty or not
	bit 0 to check rx buffer is empty or not
	1 is condition true
	0 is rx buffer is empty
	  + so if the rx buffer is empty which is true condition
	-> next line, read the value of thanh ghi DR
	*/
	while(((*SPI1_SR >> 0) & 1) == 0);
	char data = *SPI1_DR; //receive data

	// send dummy data 0xff
	while(((*SPI1_SR >> 7) & 1) == 1);
	*SPI1_DR = 0xff; //send dummy data to gyro
	while(((*SPI1_SR >> 1) & 1) == 0);
	while(((*SPI1_SR >> 7) & 1) == 1);

	while(((*SPI1_SR >> 0) & 1) == 0);
	data = *SPI1_DR; //receive data

	return data;
}
void SPI_Write(char reg_addr, char reg_val){
	*GPIOE_ODR &= ~(1 << 3); //set PE3 to LOW to active SLAVE

	while(((*SPI1_SR >> 7) & 1) == 1); // if == 1, SPI busy and stuck in while loop, no move on to next
	*SPI1_DR = reg_addr;  //ghi du lieu vao DR, send data to gyro
	//check tx buffer (transmitter) empty or not
	while(((*SPI1_SR >> 1) & 1) == 0); //at bit 1, 0 for tx buffer not empty, stuck in while loop.
	while(((*SPI1_SR >> 7) & 1) == 1);

	while(((*SPI1_SR >> 0) & 1) == 0);
	char data = *SPI1_DR; //receive data

	// send dummy data 0xff
	while(((*SPI1_SR >> 7) & 1) == 1);
	*SPI1_DR = reg_val; //send dummy data to gyro
	while(((*SPI1_SR >> 1) & 1) == 0);
	while(((*SPI1_SR >> 7) & 1) == 1);

	//Read DR memory data
	while(((*SPI1_SR >> 0) & 1) == 0);
	data = *SPI1_DR; //receive data

	*GPIOE_ODR |= (1 << 3); //set PE3 to high to inactive SLAVE

}
