/*
 * lcd_i2c.c
 *
 * Created: 31.10.2022 18:01:47
 *  Author: Dmitrenok D.A.
 */ 

#include "lcd_i2c.h"

unsigned char lcd_byte_state = (1 << BCK_LIGHT);

void lcd_i2c_init(void)
{
	_delay_ms(15);
	lcd_i2c_send_half_byte(0b00110000);
	_delay_ms(5);
	lcd_i2c_send_half_byte(0b00110000);
	_delay_us(100);
	lcd_i2c_send_half_byte(0b00110000);
	_delay_ms(1);
	lcd_i2c_send_half_byte(0b00100000);
	_delay_ms(1);
	lcd_i2c_send_byte(0b00101000, INSTRUCTIONS);	// Function set
	_delay_ms(1);
	lcd_i2c_send_byte(0b00001100, INSTRUCTIONS);  // Display on/off control
	_delay_ms(1);
	lcd_i2c_send_byte(0b00000001, INSTRUCTIONS);	// Clear display
	_delay_ms(1);
	lcd_i2c_send_byte(0b00000110, INSTRUCTIONS); // Entry mode set
	_delay_ms(1);
}

void lcd_i2c_send_byte(unsigned char byte, unsigned char data_or_instructions)
{
	if (data_or_instructions == DATA)
	{
		RS_1;
	}
	else
	{
		RS_0;
	}
	lcd_i2c_send_half_byte(byte & 0xf0);
	lcd_byte_state &= 0x0f;
	lcd_i2c_send_half_byte(byte << 4);
	lcd_byte_state &= 0x0f;
}

void lcd_i2c_send_half_byte(unsigned char byte)
{
	_delay_us(50);
	EN_1;
	_delay_us(50);
	lcd_byte_state &= 0x0f;
	i2c_send_byteByADDR(lcd_byte_state |= byte, ADDR_PCF8574_W);
	EN_0;
}

void lcd_i2c_send_str(char *str)
{
	for (wchar_t i = 0; str[i] != '\0'; i++)
	{
		lcd_i2c_send_byte(str[i], DATA);
		_delay_us(50);
	}
}

void lcd_i2c_set_cursor(unsigned char x, unsigned char y)
{
	unsigned char address = (0x40 * y + x) | 0b10000000;
	lcd_i2c_send_byte(address, INSTRUCTIONS);
}

void lcd_i2c_clear_display(void)
{
	lcd_i2c_send_byte(0x01, INSTRUCTIONS);
}