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

uint8_t i2c_eeprom_read_byte(uint8_t deviceAddr, uint16_t readAddress) {
	uint8_t byteRead = 0;

	if (!i2c_start((deviceAddr<<1) | I2C_WRITE)) return false;

	if (readAddress > 255) {
		if (!i2c_write((readAddress >> 8))) return false; // MSB
		if (!i2c_write((readAddress & 0xFF))) return false; // LSB
	}
	else {
		if (!i2c_write(readAddress)) return false; // 8 bit
	}

	if (!i2c_restart((deviceAddr<<1) | I2C_READ)) return false;

	byteRead = i2c_read(1);

	i2c_stop();

	return byteRead;
}

bool i2c_eeprom_read_bytes(uint8_t deviceAddr, uint8_t readAddress, byte *readBuffer, uint8_t bytestoRead) {

	if (!i2c_start((deviceAddr<<1) | I2C_WRITE)) return false;

	if (!i2c_write(readAddress)) return false;

	if (!i2c_restart((deviceAddr<<1) | I2C_READ)) return false;

	for (uint8_t i = 0; i < bytestoRead; i++) {
		readBuffer[i] = i2c_read(i == (bytestoRead-1));
	}

	i2c_stop();

	return true;
}

bool soft_i2c_eeprom_write_byte(uint8_t deviceAddr, uint16_t writeAddress, byte writeByte) {

	if (!i2c_start((deviceAddr<<1) | I2C_WRITE)) return false;

	if ( writeAddress > 255) {
		if (!i2c_write((writeAddress >> 8))) return false; // MSB
		if (!i2c_write((writeAddress & 0xFF))) return false; // LSB
	}
	else {
		if (!i2c_write(writeAddress)) return false; // 8 bit
	}

	if (!i2c_write(writeByte)) return false;

	i2c_stop();

	_delay_ms(10);

	return true;
}
