#include <avr/io.h>
#include <util/delay.h>

int main(void){
	DDRC |= 1<<0;

	while(1){
		PORTC ^= 1<<0;
		_delay_ms(100);
	}

	return 0;
}
