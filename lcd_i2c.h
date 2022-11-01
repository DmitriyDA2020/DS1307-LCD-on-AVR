/*
 * lcd_i2c.h
 *
 * Created: 31.10.2022 18:02:03
 *  Author: Dmitrenok D.A.
 */ 


#ifndef LCD_I2C_H_
#define LCD_I2C_H_

#include "main.h"



#define ADDR_PCF8574_R 0b01001101 // 7-bit address + Read flag
#define ADDR_PCF8574_W 0b01001100 // 7-bit address + Write flag
#define RS 0 // Register Select pin
#define RW 1 // Read\Write pin
#define EN 2 // Enable pin
#define BCK_LIGHT 3 // Back Light pin
#define EN_1 i2c_send_byteByADDR(lcd_byte_state |= (1 << EN), ADDR_PCF8574_W)
#define EN_0 i2c_send_byteByADDR(lcd_byte_state &= ~(1 << EN), ADDR_PCF8574_W)
#define DATA 1
#define INSTRUCTIONS 0
#define RS_1 i2c_send_byteByADDR(lcd_byte_state |= (1 << RS), ADDR_PCF8574_W)
#define RS_0 i2c_send_byteByADDR(lcd_byte_state &= ~(1 << RS), ADDR_PCF8574_W)

void lcd_i2c_init(void);
void lcd_i2c_send_byte(unsigned char byte, unsigned char data_or_instructions);
void lcd_i2c_send_half_byte(unsigned char byte);
void lcd_i2c_send_str(char *str);
void lcd_i2c_set_cursor(unsigned char x, unsigned char y);
void lcd_i2c_clear_display(void);

#endif /* LCD_I2C_H_ */