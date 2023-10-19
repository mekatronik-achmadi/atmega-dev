#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "pwm.h"

int main(void){
	DDRB |= 1<<4;

	pwm_init();
	OCR1AL = 200;
	OCR1BL = 128;

	while(1){
		PORTB |= 1<<4;
		_delay_ms(255);
	}
	return 0;
}
