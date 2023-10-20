#include "pwm.h"

volatile unsigned int tickA,tickB;

void pwm_init(void){
	DDRB |= 1<<0 | 1<<1 | 1<<2 | 1<<3;

	TCCR1B|=(0<<CS12)|(1<<CS11)|(0<<CS10);
	TCCR1B|=(1<<WGM12);

	TIMSK|=1<<OCIE1A;
	TIMSK|=1<<OCIE1B;

	OCR1A = 0x00FF;
	OCR1B = 0x00FF;

	tickA = 0;
	tickB = 0;

	sei();
}

ISR(TIMER1_COMPA_vect){
	tickA++;

	if(tickA==20){
		PORTB &= ~(1<<0);
	}
	else if(tickA==40){
		PORTB &= ~(1<<1);
	}
	else if(tickA==80){
		PORTB |= 1<<0 | 1<<1 | 1<<2;
		tickA=0;
	}
}

ISR(TIMER1_COMPB_vect){
	tickB++;

	if(tickB==30){
		PORTB &= ~(1<<2);
	}
	else if(tickB==60){
		PORTB &= ~(1<<3);
	}
	else if(tickB==90){
		PORTB |= 1<<2 | 1<<3;
		tickB=0;
	}
}

