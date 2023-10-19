#ifndef I2C_H_INCLUDED
#define I2C_H_INCLUDED

#include <avr/io.h>
#include <util/twi.h>

#define I2C_READ    1
#define I2C_WRITE   0

/* I2C clock in Hz */
#define SCL_CLOCK	50000L
#define PRESCALER	1

void i2c_init(void);
uint8_t i2c_start(uint8_t address);
void i2c_start_wait(uint8_t address);
uint8_t i2c_rep_start(uint8_t address);
void i2c_stop(void);
uint8_t i2c_write( uint8_t data );
uint8_t i2c_readAck(void);
uint8_t i2c_readNak(void);

#endif
