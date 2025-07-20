/*
 * Gyro_address.h
 *
 *  Created on: Apr 8, 2025
 *      Author: 84903
 */

#ifndef INC_GYRO_ADDRESS_H_
#define INC_GYRO_ADDRESS_H_

#define CTRL_REG1 		0x20  //Powered Gyro, activate axes, streaming angular velocity data
#define CTRL_REG2 		0x21  //High-pass filter, when need to filter slow drift
#define CTRL_REG3 		0x22  //Interrupt settings, use data-ready or FIFO INTs
#define CTRL_REG4 		0x23  //Full scale selection, self test, to set range from +-245/500/2000dps)
#define CTRL_REG5		0x24  //Reboot, FIFO(1st in - 1st out), high-pass filter enable, when enabling FIFO or filter logic

#define DATA_CAPTURE	0x25	//capture the angular velocity data for X,Y,Z axes for both high and low byte
#define OUT_TEMP		0x26	//temperature sensor value, thermal compensation
#define STATUS_REG		0x27	//data availability and axis-specific updates

//X, Y, Z axes for low and high byte
#define OUT_X_L			0x28
#define OUT_X_H			0x29
#define OUT_Y_L			0x2A
#define OUT_Y_H			0x2B
#define OUT_Z_L			0x2C
#define OUT_Z_H			0x2D

#define FIFO_CTRL_REG	0x2E
#define FIFO_SRC_REG 	0x2F

#define INT1_CFG		0x30
#define INT1_SRC		0x31
#define INT1_THS_XH		0x32
#define INT1_THS_XL		0x33
#define INT1_THS_YH		0x34
#define INT1_THS_YL		0x35
#define INT1_THS_ZH		0x36
#define INT1_THS_ZL		0x37
#define INT1_DURATION	0X38

#endif /* INC_GYRO_ADDRESS_H_ */
