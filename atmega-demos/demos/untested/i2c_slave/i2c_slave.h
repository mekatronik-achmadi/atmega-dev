#ifndef I2C_SLAVE_H_INCLUDED
#define I2C_SLAVE_H_INCLUDED

#include <util/twi.h>
#include <avr/interrupt.h>

void i2c_init(uint8_t address);
void i2c_stop(void);

#endif // I2C_SLAVE_H_INCLUDED
