#include "icp.h"

volatile uint8_t step, ovf, rst;
volatile uint32_t period;

void icp_init(void){

	DDRD &= ~(1<<6);
	PORTD |= (1<<6);

	TCCR1B |= (0<<CS12)|(1<<CS11)|(0<<CS10);
	TCCR1B &= ~(1<<ICES1);
	TIMSK  |= 1<<TOIE1;
	TIMSK  |= 1<<TICIE1;

	sei();
}

ISR(TIMER1_CAPT_vect){

	if(step==0){
		TCNT1 = 0;
		ICR1 = 0;
		step = 1;
		rst = 0;
	}
	else if(step==1){
		period = ICR1 + (ovf*65535);
		step = 0;
		ovf = 0;
		TCNT1=0;
		ICR1=0;
	}
}

ISR(TIMER1_OVF_vect){
	if(step==1)ovf++;

	rst++;
	if(rst>=2){
		period = 0;
		step = 0;
		ovf = 0;
		rst = 0;
	}
}
