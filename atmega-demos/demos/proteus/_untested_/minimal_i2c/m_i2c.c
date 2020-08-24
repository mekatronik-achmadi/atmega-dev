#include "m_i2c.h"

void i2c_init(void){
	TWSR = 0;
	TWBR = TWBR_VAL;
}

void i2c_start(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
}

void i2c_s_ack(void){
	while((TWSR & 0xF8)!= START);
}

void i2c_device(uint8_t addr){
	TWDR = addr;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
}

void i2c_d_ack(void){
	while((TWSR & 0xF8)!= DEV_ACK);
}

void i2c_write(uint8_t data){
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}

void i2c_w_ack(void){
	while((TWSR & 0xF8) != DATA_ACK);
}


void i2c_stop(void){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
