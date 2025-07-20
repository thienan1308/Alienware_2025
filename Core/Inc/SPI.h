/*
 * SPI.h
 *
 *  Created on: Jun 14, 2025
 *      Author: andan
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

void SPI_Init();
char SPI_Read(char reg_addr);
void SPI_Write(char reg_addr, char reg_val);

#endif /* INC_SPI_H_ */
