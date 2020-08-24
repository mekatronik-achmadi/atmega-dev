#include <avr/io.h>
#include "i2clib.h"

int main(void){
	uint8_t txbuf[5];

	DDRA |= 1<<0;
	PORTA &= ~(1<<0);

	for(uint8_t i=0;i<4;i++){
		_delay_ms(200);
	}

	PORTA |= (1<<0);
	_delay_ms(255);
	PORTA &= ~(1<<0);

	txbuf[0]=0x27;
	txbuf[1]=0x30;
	txbuf[2]=0x64;

	i2c_init();
	i2c_start();
	i2c_transmit(0xE0, txbuf, 3);
	i2c_stop();

	while(1){
		PORTA ^= 1<<0;
		_delay_ms(255);
	}
	return 0;
}
