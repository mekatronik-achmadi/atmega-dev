#ifndef _I2C_H
#define _I2C_H

#include <avr/io.h>
#include <inttypes.h>
#include <compat/twi.h>

#define SCL_CLOCK  10000L

#define I2C_READ	1
#define I2C_WRITE	0

void i2c_init(void);
uint8_t i2c_start(uint8_t address);
void i2c_start_wait(uint8_t address);
void i2c_stop(void);
uint8_t i2c_write( uint8_t data );
uint8_t i2c_readack(void);
uint8_t i2c_readnak(void);

#endif
