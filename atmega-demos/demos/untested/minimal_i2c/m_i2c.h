#ifndef _M_I2C_H_
#define _M_I2C_H_

#include <avr/io.h>
#include <util/twi.h>

#define I2C_READ    1
#define I2C_WRITE   0

/* I2C clock in Hz */
#define TWBR_VAL	(((8000000UL/40000UL)-16)/2)

#define START		0x08
#define DEV_ACK		0x18
#define DEV_NACK	0x20
#define DATA_ACK	0x28
#define DATA_NACK	0x30

void i2c_init(void);
void i2c_start(void);
void i2c_s_ack(void);
void i2c_device(uint8_t addr);
void i2c_d_ack(void);
void i2c_write(uint8_t data);
void i2c_w_ack(void);
void i2c_stop(void);

#endif
