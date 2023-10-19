#include "i2c_soft.h"

void i2csoft_init(void) {
	I2C_DDR |= (1<<SDA_PIN);
	I2C_PORT|= (1<<SDA_PIN);
	I2C_DDR |= (1<<SCL_PIN);
	I2C_PORT|= (1<<SCL_PIN);
}

void i2csoft_deinit(void) {
	I2C_PORT&= ~(1<<SDA_PIN);
	I2C_DDR &= ~(1<<SDA_PIN);
	I2C_PORT&= ~(1<<SCL_PIN);
	I2C_DDR &= ~(1<<SCL_PIN);
}

unsigned char i2csoft_read(unsigned char last) {
	unsigned char b = 0;
	
	I2C_PORT|= (1<<SDA_PIN);
	I2C_DDR &= ~(1<<SDA_PIN);

	for (unsigned char i = 0; i < 8; i++) {

		b <<= 1;
		i2csoft_delay(I2C_DELAY);
		I2C_PORT|= (1<<SCL_PIN);
		if (I2C_PIN & (1<<SDA_PIN)) b |= 1;
		I2C_PORT&= ~(1<<SCL_PIN);
	}

	I2C_DDR |= (1<<SDA_PIN);
	if (last) { 
		I2C_PORT|= (1<<SDA_PIN); 
	}
	else { 
		I2C_PORT&= ~(1<<SDA_PIN);
	} 
	 
	I2C_PORT|= (1<<SCL_PIN);
	i2csoft_delay(I2C_DELAY);
	I2C_PORT&= ~(1<<SCL_PIN);
	I2C_PORT&= ~(1<<SDA_PIN);
	
	return b;
}

unsigned char i2csoft_write(unsigned char data) {
	unsigned char rtn;
	for (unsigned char m = 0x80; m != 0; m >>= 1) {

		if (m & data) { 
			I2C_PORT|= (1<<SDA_PIN); 
		}
		else { 
			I2C_PORT&= ~(1<<SDA_PIN); 
		}
		I2C_PORT|= (1<<SCL_PIN);
		i2csoft_delay(I2C_DELAY);
		I2C_PORT&= ~(1<<SCL_PIN);
	}

	I2C_DDR &= ~(1<<SDA_PIN);

	I2C_PORT|= (1<<SDA_PIN);
	I2C_PORT|= (1<<SCL_PIN);
	if(I2C_PIN & (1<<SDA_PIN)) rtn=1;
	I2C_PORT&= ~(1<<SCL_PIN);
	I2C_DDR |= (1<<SDA_PIN);
	I2C_PORT&= ~(1<<SDA_PIN);
	
	return rtn == 0;
}

unsigned char i2csoft_start(unsigned char addressRW) {
	I2C_PORT&= ~(1<<SDA_PIN);
	i2csoft_delay(I2C_DELAY);
	I2C_PORT&= ~(1<<SCL_PIN);
	
	return i2csoft_write(addressRW);
}

unsigned char i2csoft_restart(unsigned char addressRW) {
	I2C_PORT|= (1<<SDA_PIN);
	I2C_PORT|= (1<<SCL_PIN);
	i2csoft_delay(I2C_DELAY);
	return i2csoft_start(addressRW);
}

void i2csoft_run(void) {
	I2C_PORT&= ~(1<<SDA_PIN);
	i2csoft_delay(I2C_DELAY);
	I2C_PORT&= ~(1<<SCL_PIN);
}

void i2csoft_stop(void) {
	I2C_PORT&= ~(1<<SDA_PIN);
	i2csoft_delay(I2C_DELAY);
	I2C_PORT|= (1<<SCL_PIN);
	i2csoft_delay(I2C_DELAY);
	I2C_PORT|= (1<<SDA_PIN);
	i2csoft_delay(I2C_DELAY);
}
