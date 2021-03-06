#include "i2c.h"

void i2c_init(void){
  TWSR = 0;
  TWBR = ((F_CPU/SCL_CLOCK)-16)/2;
}

uint8_t i2c_start(uint8_t address)
{
    uint8_t   twst;

	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)));

	twst = TW_STATUS & 0xF8;
	if ( (twst != TW_START) && (twst != TW_REP_START)) return 1;

	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)));

	twst = TW_STATUS & 0xF8;
	if ( (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK) ) return 1;

	return 0;
}

void i2c_start_wait(uint8_t address){
    uint8_t   twst;


    while ( 1 )
    {
	    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

    	while(!(TWCR & (1<<TWINT)));

    	twst = TW_STATUS & 0xF8;
    	if ( (twst != TW_START) && (twst != TW_REP_START)) continue;

    	TWDR = address;
    	TWCR = (1<<TWINT) | (1<<TWEN);

    	while(!(TWCR & (1<<TWINT)));

    	twst = TW_STATUS & 0xF8;
    	if ( (twst == TW_MT_SLA_NACK )||(twst ==TW_MR_DATA_NACK) )
    	{
	        TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);

	        while(TWCR & (1<<TWSTO));

    	    continue;
    	}

    	break;
     }
}

void i2c_stop(void){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while(TWCR & (1<<TWSTO));
}

uint8_t i2c_write( uint8_t data ){
    uint8_t   twst;

	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)));

	twst = TW_STATUS & 0xF8;
	if( twst != TW_MT_DATA_ACK) return 1;
	return 0;
}

uint8_t i2c_readack(void){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(!(TWCR & (1<<TWINT)));

    return TWDR;
}

uint8_t i2c_readnak(void){
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));

    return TWDR;
}
