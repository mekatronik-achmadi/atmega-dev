#include "i2c_slave.h"

volatile uint8_t buffer_address;
volatile uint8_t txbuffer[0xFF];
volatile uint8_t rxbuffer[0xFF];

void i2c_init(uint8_t address){
    TWAR = address;
    TWCR = (1<<TWIE) | (1<<TWEA) | (1<<TWINT) | (1<<TWEN);

    sei();
}

void i2c_stop(void){
	TWCR &= ~( (1<<TWEA) | (1<<TWEN) );
}

ISR(TWI_vect){
    uint8_t data;

    if( (TWSR & 0xF8) == TW_SR_SLA_ACK ){
		buffer_address = 0xFF;
		TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	}
	else if( (TWSR & 0xF8) == TW_SR_DATA_ACK ){
        data = TWDR;

        if(buffer_address == 0xFF){
			buffer_address = data;
			TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
		}
		else{
            rxbuffer[buffer_address] = data;
            buffer_address++;

            if(buffer_address < 0xFF){
				TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
			}
			else{
				TWCR |= (1<<TWIE) | (1<<TWINT) | (0<<TWEA) | (1<<TWEN);
			}
		}
	}
	else if( (TWSR & 0xF8) == TW_ST_DATA_ACK ){
        data = TWDR;

        if( buffer_address == 0xFF ){
			buffer_address = data;
		}
		TWDR = txbuffer[buffer_address];
		buffer_address++;

		if(buffer_address < 0xFF){
			TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
		}
		else{
			TWCR |= (1<<TWIE) | (1<<TWINT) | (0<<TWEA) | (1<<TWEN);
		}
	}
	else{
        TWCR |= (1<<TWIE) | (1<<TWEA) | (1<<TWEN);
	}
}
