#include "pwm.h"

void pwm_init(void){
	DDRB |= 1<<3;

	TCCR0|=(0<<CS02)|(1<<CS01)|(0<<CS00);
	TCCR0|=(0<<WGM01)|(1<<WGM00);
	TCCR0|=(1<<COM01)|(0<<COM00);
}
