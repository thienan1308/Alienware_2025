/*
 * Flash_Eraser.c
 *
 *  Created on: May 18, 2025
 *      Author: andan
 */

#include <main.h>

void Flash_eraser_sector (int sec_num){
	uint32_t* FLASH_SR = (uint32_t*)(0x40023C00 + 0x0C); //based address of Flash memory and offet to SR and CR
	uint32_t* FLASH_CR = (uint32_t*)(0x40023C00 + 0x10);
	if (((*FLASH_SR >> 16) & 1) == 1){ //Flash memory operation ongoing
		uint32_t* FLASH_KEYR = (uint32_t*)(0x40023C00 + 0x04);
		*FLASH_KEYR = 0x45670123;
		*FLASH_KEYR = 0xCDEF89AB;
	}
	*FLASH_CR |= (0b01 << 1); //Activate the erase sector
	*FLASH_CR |= (sec_num << 3); //Flash module organize _ sector 3 selection
	*FLASH_CR |= (0b01 << 16); // This bit triggers an erase operation when set. It is set only by software and cleared when the BSY bit is cleared.
	while(((*FLASH_SR >> 16) & 1) == 0);
}
void Flash_programming(uint8_t* addr, uint8_t* value){
	uint32_t* FLASH_SR = (uint32_t*)(0x40023C00 + 0x0C); //based address of Flash memory and offet to SR and CR
	uint32_t* FLASH_CR = (uint32_t*)(0x40023C00 + 0x10);
	if (((*FLASH_SR >> 16) & 1) == 0){ //Flash memory operation ongoing
		if(((*FLASH_CR >> 31) & 1) == 0){
			uint32_t* FLASH_KEYR = (uint32_t*)(0x40023C00 + 0x04);
			*FLASH_KEYR = 0x45670123;
			*FLASH_KEYR = 0xCDEF89AB;
		}
		*FLASH_CR |= (0b01 << 0); //Flash program activated
		*FLASH_CR |= (0b00 << 9); //Program size - program x8
		*addr = value;
		while(((*FLASH_SR >> 16) & 1) == 0);
	}
}
