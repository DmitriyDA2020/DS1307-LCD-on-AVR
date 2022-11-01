/*
 * main.h
 *
 * Created: 30.10.2022 1:07:32
 *  Author: Dmitrenok D.A.
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include "i2c.h"
#include "lcd_i2c.h"
#include "ds1307.h"

void GPIO_init(void);

#endif /* MAIN_H_ */