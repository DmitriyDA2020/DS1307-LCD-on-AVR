/*
 * ds1307.h
 *
 * Created: 31.10.2022 2:55:45
 *  Author: Dmitrenok D.A.
 */ 


#ifndef DS1307_H_
#define DS1307_H_

#include "main.h"

#define ADDR_DS1307_R 0b11010001
#define ADDR_DS1307_W 0b11010000
#define SEC_REG 0x00
#define MIN_REG 0x01
#define HOUR_REG 0x02
#define DAY_REG 0x03
#define DATE_REG 0x04
#define MONTH_REG 0x05
#define YEAR_REG 0x06
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

unsigned char DEC_to_BCD(unsigned char val);
unsigned char BCD_to_DEC(unsigned char val);
void ds1307_set_all_param(unsigned char sec, unsigned char min, unsigned char hour, unsigned char day, unsigned char date, unsigned char month, unsigned char year);
void ds1307_read_all_param(void);

#endif /* DS1307_H_ */