/*
 * i2c.c
 *
 * Created: 30.10.2022 1:43:28
 *  Author: Dmitrenok D.A.
 */ 

#include "i2c.h"

void i2c_init()
{
	TWBR = 0x20;
}

void i2c_StartCondition(void)
{
	TWCR = (1 << TWSTA) | (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void i2c_StopCondition(void)
{
	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
}

void i2c_send_byte(unsigned char byte)
{
	TWDR = byte;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void i2c_send_byteByADDR(unsigned char byte, unsigned char address)
{
	i2c_StartCondition();
	i2c_send_byte(address);
	i2c_send_byte(byte);
	i2c_StopCondition();
}

unsigned char i2c_read_byte(void)
{
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}

unsigned char i2c_read_last_byte(void)
{
	TWCR = (1 << TWEN) | (1 << TWINT);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}