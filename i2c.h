/*
 * i2c.h
 *
 * Created: 30.10.2022 1:43:54
 *  Author: Dmitrenok D.A.
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "main.h"

#define N_LAST_BYTE 1
#define LAST_BYTE 0
#define START 1
#define STOP 0
#define STA_CONDITION TWSTA
#define STO_CONDITION TWSTO

void i2c_init(void);
void i2c_send_byte(unsigned char byte);
void i2c_send_byteByADDR(unsigned char byte, unsigned char address);
unsigned char i2c_read_byte(void);
unsigned char i2c_read_last_byte(void);
void i2c_StartCondition(void);
void i2c_StopCondition(void);

#endif /* I2C_H_ */