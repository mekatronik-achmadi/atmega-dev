#ifndef _I2C_SOFT_H
#define _I2C_SOFT_H

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#define I2C_READ	1
#define I2C_WRITE	0

#define I2C_DELAY	4

#define I2C_DDR		DDRC
#define I2C_PIN		PINC
#define I2C_PORT	PORTC

#define I2C_SDA		1
#define I2C_SCL		0

void i2c_init(void);
void i2c_deinit(void);
uint8_t i2c_readnak(void);
uint8_t i2c_read(uint8_t last);
uint8_t i2c_write(uint8_t data);
uint8_t i2c_start(uint8_t addressRW);
uint8_t i2c_restart(uint8_t addressRW) ;
void i2c_stop(void);

#endif
