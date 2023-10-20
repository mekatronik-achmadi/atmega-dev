#include <avr/io.h>
#include <util/delay.h>

int main(void){
	DDRC |= 1<<0;
	DDRC &=~(1<<1);


	PORTC |= (1<<0) | (1<<1);

	while(1){
		if(!(PINC & (1<<1))){
			PORTC &=~(1<<0);
		}
		else{
			PORTC ^=1<<0;
		}
		_delay_ms(255);
	}

	return 0;
}
