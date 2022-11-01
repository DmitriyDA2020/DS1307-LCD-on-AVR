/*
 * 19 - DS1307 LCD.c
 *
 * Created: 30.10.2022 1:06:27
 * Author : Dmitrenok D.A.
 */ 

#include "main.h"


unsigned char sec, min, hour, day, date, month, year;

ISR(INT0_vect)
{
	ds1307_read_all_param();
	lcd_i2c_set_cursor(4, 0);
	lcd_i2c_send_byte((hour >> 4) + 0x30, DATA);
	lcd_i2c_send_byte((hour & 0x0f) + 0x30, DATA);
	lcd_i2c_send_byte(':', DATA);
	lcd_i2c_send_byte((min >> 4) + 0x30, DATA);
	lcd_i2c_send_byte((min  & 0x0f) + 0x30, DATA);
	lcd_i2c_send_byte(':', DATA);
	lcd_i2c_send_byte((sec >> 4) + 0x30, DATA);
	lcd_i2c_send_byte((sec & 0x0f) + 0x30, DATA);
	lcd_i2c_set_cursor(0, 1);
	lcd_i2c_send_byte((date >> 4) + 0x30, DATA);
	lcd_i2c_send_byte((date & 0x0f) + 0x30, DATA);
	lcd_i2c_send_byte('.', DATA);
	lcd_i2c_send_byte((month >> 4) + 0x30, DATA);
	lcd_i2c_send_byte((month & 0x0f) + 0x30, DATA);
	lcd_i2c_send_byte('.', DATA);
	lcd_i2c_send_str("20");
	lcd_i2c_send_byte((year >> 4) + 0x30, DATA);
	lcd_i2c_send_byte((year & 0x0f) + 0x30, DATA);
	lcd_i2c_set_cursor(12, 1);
	switch (day)
	{
		case 1:
		lcd_i2c_send_str("Mon");
		break;
		case 2:
		lcd_i2c_send_str("Tue");
		break;
		case 3:
		lcd_i2c_send_str("Wed");
		break;
		case 4:
		lcd_i2c_send_str("Thu");
		break;
		case 5:
		lcd_i2c_send_str("Fri");
		break;
		case 6:
		lcd_i2c_send_str("Sat");
		break;
		case 7:
		lcd_i2c_send_str("Sun");
		break;
	}
}

int main(void)
{
	GPIO_init();
	i2c_init();
	lcd_i2c_init();
	lcd_i2c_send_str("DATA FROM DS1307");
	lcd_i2c_set_cursor(0, 1);
	lcd_i2c_send_str("TO LCD WITH I2C");
	_delay_ms(2000);
	lcd_i2c_clear_display();
	sei();
    while (1);
}

void GPIO_init(void)
{
	MCUCR = 1 << ISC00;
	GICR = 1 << INT0;
}
