#include <avr/io.h>
#include "m_i2c.h"

int main(void){
	DDRA |= 1<<0;
	PORTA &= ~(1<<0);

	for(uint8_t i=0;i<4;i++){
		_delay_ms(200);
	}

	PORTA |= (1<<0);
	_delay_ms(255);
	PORTA &= ~(1<<0);

	i2c_init();
	i2c_start();
	i2c_s_ack();
	i2c_stop();

	while(1){
		PORTA ^= 1<<0;
		_delay_ms(255);
	}
	return 0;
}
