#include "pwm.h"

volatile unsigned int tick;

void pwm_init(void){
	DDRB |= 1<<0 | 1<<1 | 1<<2;

	TCCR1B|=(0<<CS12)|(1<<CS11)|(0<<CS10);

	TIMSK|=1<<TOIE1;

	tick = 0;

	sei();
}

ISR(TIMER1_OVF_vect){
	tick++;

	if(tick==20){
		PORTB &= ~(1<<0);
	}
	else if(tick==40){
		PORTB &= ~(1<<1);
	}
	else if(tick==60){
		PORTB &= ~(1<<2);
	}
	else if(tick==80){
		PORTB |= 1<<0 | 1<<1 | 1<<2;
		tick=0;
	}
}

