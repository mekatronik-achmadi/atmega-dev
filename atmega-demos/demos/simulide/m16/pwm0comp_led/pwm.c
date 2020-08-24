#include "pwm.h"

volatile unsigned int tick;

void pwm_init(void){
	DDRB |= 1<<0 | 1<<1 | 1<<2 | 1<<3;

	TCCR0|=(0<<CS02)|(0<<CS01)| (1<<CS00);
	TCCR0|=(0<<WGM01)|(1<<WGM00);
	TCCR0|=(1<<COM01)|(0<<COM00);

	TIMSK|=1<<OCIE0;
	OCR0=128;

	tick = 0;
	sei();
}

ISR(TIMER0_COMP_vect){
	tick++;

	if(tick==200){
		PORTB &= ~(1<<0);
	}
	else if(tick==250){
		PORTB &= ~(1<<1);
	}
	else if(tick==300){
		PORTB &= ~(1<<2);
	}
	else if(tick==400){
		PORTB |= 1<<0 | 1<<1 | 1<<2;
		tick=0;
	}
}

