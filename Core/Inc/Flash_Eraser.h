/*
 * Flash_Eraser.h
 *
 *  Created on: May 18, 2025
 *      Author: andan
 */

#ifndef INC_FLASH_ERASER_H_
#define INC_FLASH_ERASER_H_

void Flash_eraser_sector(int sec_num);
void Flash_programming(uint8_t* addr, uint8_t* value);


#endif /* INC_FLASH_ERASER_H_ */
