/*
 * ds1307.c
 *
 * Created: 31.10.2022 2:55:29
 *  Author: Dmitrenok D.A.
 */ 

#include "ds1307.h"

extern unsigned char sec, min, hour, day, date, month, year;

unsigned char DEC_to_BCD(unsigned char val)
{
	return ((val / 10) << 4) | (val % 10);
}

unsigned char BCD_to_DEC(unsigned char val)
{
	return ((val >> 4) * 10) + (val & 0x0f);
}

void ds1307_set_all_param(unsigned char sec, unsigned char min, unsigned char hour, unsigned char day, unsigned char date, unsigned char month, unsigned char year)
{
	i2c_StartCondition();
	i2c_send_byte(ADDR_DS1307_W);
	i2c_send_byte(0x00);
	i2c_send_byte(DEC_to_BCD(sec));
	i2c_send_byte(DEC_to_BCD(min));
	i2c_send_byte(DEC_to_BCD(hour));
	i2c_send_byte(DEC_to_BCD(day));
	i2c_send_byte(DEC_to_BCD(date));
	i2c_send_byte(DEC_to_BCD(month));
	i2c_send_byte(DEC_to_BCD(year));
	i2c_StopCondition();
}

void ds1307_read_all_param(void)
{
	i2c_StartCondition();
	i2c_send_byte(ADDR_DS1307_W);
	i2c_send_byte(0x00);
	i2c_StartCondition();
	i2c_send_byte(ADDR_DS1307_R);
	sec = i2c_read_byte();
	min = i2c_read_byte();
	hour = i2c_read_byte();
	day = i2c_read_byte();
	date = i2c_read_byte();
	month = i2c_read_byte();
	year = i2c_read_last_byte();
	i2c_StopCondition();
}