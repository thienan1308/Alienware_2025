/*
 * I2C.c
 *
 *  Created on: May 25, 2025
 *      Author: andan
 */

#include <main.h>
#include "base_address.h"

void I2C_Init(){
	//PB6
	*GPIOB_MODER &= ~ (0b11 << 12);
	*GPIOB_MODER |= (0b10 << 12); //Set for alternate function as datasheet_table 9 p.49
	//PB9
	*GPIOB_MODER &= ~ (0b11 << 18);
	*GPIOB_MODER |= (0b10 << 18); //Set for alternate function as datasheet_table 9 p.49
	//ALternative function low for PB6
	*GPIOB_AFRL &= ~ (0b1111 << 24);
	*GPIOB_AFRL |= (0b0100 << 24);
	//ALternative function high register for PB9
	*GPIOB_AFRH &= ~ (0b1111 << 4);
	*GPIOB_AFRH |= (0b0100 << 4);

	_HAL_RCC_I2C1_CLK_ENABLE();
	*I2C_CR2 &= ~ (0b1111 << 0);
	*I2C_CR2 |=   (16 << 0);

	*I2C_CRR &= ~ (0xFFFF << 0);
	*I2C_CRR |=	  (160    << 0);
	//Enable I2C
	*I2C_CR1 |=    (1     << 0);
}

void I2C_Write_data(uint8_t slave_reg_addr, uint8_t slave_reg_val){
	//Generate the start bit
	*I2C_CR1 |= (1 << 8);
	//wait SB in SR1
	while(((*I2C_SR1 >> 0 ) &1)== 0);
	//Send 7 slave add + 1 bit write (0b0011001 << 1 | 0)
	*I2C_DR = 0b00110010; //first bit is bit write 0
	while(((*I2C_SR1 >> 1 ) &1)== 0);
	uint32_t* temp = *I2C_SR2;
	//Check ACK
	while(((*I2C_SR1 >> 10 ) &1)== 1);
	//Send data command frame (0x1F)
	*I2C_DR = slave_reg_addr;
	while(((*I2C_SR1 >> 2 ) &1)== 0);
	//check ACK
	while(((*I2C_SR1 >> 10 ) &1)== 1);
	//Send write data (0b11000000)
	*I2C_DR = 0b11000000;
	while(((*I2C_SR1 >> 2 ) &1)== 0);
	//Generate stop bit
	*I2C_CR1 |= (1 << 9);
}

void I2C_Read_data(uint8_t slave_reg_addr){

}
