#include "exti.h"
#include "i2c_soft.h"

extern unsigned char vI;

void exti_0_init(unsigned char mode){
	PORTD |= 1<<2;

	switch(mode){
		case LOW:  MCUCR|=(0<<ISC01)|(0<<ISC00); break;
		case HIGH: MCUCR|=(0<<ISC01)|(1<<ISC00); break;
		case FALL: MCUCR|=(1<<ISC01)|(0<<ISC00); break;
		case RISE: MCUCR|=(1<<ISC01)|(1<<ISC00); break;
	}

	GICR|=1<<INT0;
	sei();
}

void exti_1_init(unsigned char mode){
	PORTD |= 1<<3;

	switch(mode){
		case LOW:  MCUCR|=(0<<ISC11)|(0<<ISC10); break;
		case HIGH: MCUCR|=(0<<ISC11)|(1<<ISC10); break;
		case FALL: MCUCR|=(1<<ISC11)|(0<<ISC10); break;
		case RISE: MCUCR|=(1<<ISC11)|(1<<ISC10); break;
	}

	GICR|=1<<INT1;
	sei();
}

void exti_2_init(unsigned char mode){
	PORTB |= 1<<2;

	switch(mode){
		case FALL: MCUCSR|=(0<<ISC2); break;
		case RISE: MCUCSR|=(1<<ISC2); break;
	}

	GICR|=1<<INT2;
	sei();
}

//===============================================//

ISR(INT0_vect){
	return;
}

ISR(INT1_vect){
	return;
}

ISR(INT2_vect){
	vI++;
	if(vI==8){
		vI=0;
	}
	
	i2csoft_start(0x40);
	i2csoft_write(vI);
	i2csoft_stop();
	
	return;
}
