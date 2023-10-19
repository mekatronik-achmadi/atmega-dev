#include "i2c_soft.h"

void i2c_init(void){
	I2C_DDR |= (1<<I2C_SDA);
	I2C_PORT |= (1<<I2C_SDA);
	I2C_DDR |= (1<<I2C_SCL);
	I2C_PORT |= (1<<I2C_SCL);
}

void i2c_deinit(void) {
	I2C_PORT &= ~(1<<I2C_SDA);
	I2C_DDR &= ~(1<<I2C_SDA);
	I2C_PORT &= ~(1<<I2C_SCL);
	I2C_DDR &= ~(1<<I2C_SCL);
}

uint8_t i2c_read(uint8_t last) {
	uint8_t b = 0;

	I2C_PORT |= (1<<I2C_SDA);
	I2C_DDR &= ~(1<<I2C_SDA);

	for (uint8_t i = 0; i < 8; i++) {
		b <<= 1;
		_delay_us(I2C_DELAY);
		I2C_PORT |= (1<<I2C_SCL);
		if (I2C_PIN & (1<<I2C_SDA)) b |= 1;
		I2C_PORT &= ~(1<<I2C_SCL);
	}

	I2C_DDR |= (1<<I2C_SDA);
	if (last) {
		I2C_PORT |= (1<<I2C_SDA);
	}
	else {
		I2C_PORT &= ~(1<<I2C_SDA);
	}
	I2C_PORT |= (1<<I2C_SCL);
	_delay_us(I2C_DELAY);
	I2C_PORT &= ~(1<<I2C_SCL);
	I2C_PORT &= ~(1<<I2C_SDA);
	return b;
}

uint8_t i2c_readnak(void){
	uint8_t b = 0;

	I2C_PORT |= (1<<I2C_SDA);
	I2C_DDR &= ~(1<<I2C_SDA);

	for (uint8_t i = 0; i < 8; i++) {
		b <<= 1;
		_delay_us(I2C_DELAY);
		I2C_PORT |= (1<<I2C_SCL);
		if (I2C_PIN & (1<<I2C_SDA)) b |= 1;
		I2C_PORT &= ~(1<<I2C_SCL);
	}

	I2C_DDR |= (1<<I2C_SDA);
	I2C_PORT |= (1<<I2C_SCL);
	_delay_us(I2C_DELAY);
	I2C_PORT &= ~(1<<I2C_SCL);
	I2C_PORT &= ~(1<<I2C_SDA);
	return b;
}

uint8_t i2c_write(uint8_t data) {

	for (uint8_t m = 0x80; m != 0; m >>= 1) {

		if (m & data) {
			I2C_PORT |= (1<<I2C_SDA);
		}
		else {
			I2C_PORT &= ~(1<<I2C_SDA);
		}
		I2C_PORT |= (1<<I2C_SCL);
		_delay_us(I2C_DELAY);
		I2C_PORT &= ~(1<<I2C_SCL);
	}

	I2C_DDR &= ~(1<<I2C_SDA);

	I2C_PORT |= (1<<I2C_SDA);
	I2C_PORT |= (1<<I2C_SCL);
	uint8_t rtn = I2C_PIN & (1<<I2C_SDA);
	I2C_PORT &= ~(1<<I2C_SCL);
	I2C_DDR |= (1<<I2C_SDA);
	I2C_PORT &= ~(1<<I2C_SDA);
	return rtn == 0;
}

uint8_t i2c_start(uint8_t addressRW) {
	I2C_PORT &= ~(1<<I2C_SDA);
	_delay_us(I2C_DELAY);
	I2C_PORT &= ~(1<<I2C_SCL);
	return i2c_write(addressRW);
}

uint8_t i2c_restart(uint8_t addressRW) {
	I2C_PORT |= (1<<I2C_SDA);
	I2C_PORT |= (1<<I2C_SCL);
	_delay_us(I2C_DELAY);
	return i2c_start(addressRW);
}

void i2c_stop(void) {
	I2C_PORT &= ~(1<<I2C_SDA);
	_delay_us(I2C_DELAY);
	I2C_PORT |= (1<<I2C_SCL);
	_delay_us(I2C_DELAY);
	I2C_PORT |= (1<<I2C_SDA);
	_delay_us(I2C_DELAY);
}
