#include <avr/io.h>
#include <util/delay.h>

#include "i2c_master.h"
#include "stepper.h"

int main(void){

	DDRA |= 1<<0;
	PORTA &= ~(1<<0);

	for(uint8_t i=0;i<4;i++){
		_delay_ms(200);
	}

	PORTA |= (1<<0);
	_delay_ms(255);
	PORTA &= ~(1<<0);

	stper_init();
	//stper_testConn(0xE0);
	stper_testConti(0xE0);

	while(1){
		PORTA ^= 1<<0;
		_delay_ms(255);
	}
}
