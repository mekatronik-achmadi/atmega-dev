#ifndef I2CS_H_INCLUDED
#define I2CS_H_INCLUDED

#include <avr/io.h>
#include <util/delay.h>

#define I2C_DELAY		255
#define i2csoft_delay	_delay_us

#define I2C_PORT	PORTC
#define I2C_PIN		PINC
#define I2C_DDR		DDRC

#define SDA_PIN		1
#define SCL_PIN		0

void i2csoft_init(void);
void i2csoft_deinit(void);
unsigned char i2csoft_read(unsigned char last);
unsigned char i2csoft_write(unsigned char data);
unsigned char i2csoft_start(unsigned char addressRW);
unsigned char i2csoft_restart(unsigned char addressRW);
void i2csoft_run(void);
void i2csoft_stop(void);

#endif // I2CS_H_INCLUDED

