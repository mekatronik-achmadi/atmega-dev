#include "pwm.h"

void pwm_init(void){
	DDRB |= 1<<3;

	TCCR2|=(0<<CS22)|(1<<CS21)|(0<<CS20);
	TCCR2|=(0<<WGM21)|(1<<WGM20);
	TCCR2|=(1<<COM21)|(0<<COM20);
}
