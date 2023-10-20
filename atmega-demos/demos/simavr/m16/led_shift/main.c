#include <avr/io.h>
#include <util/delay.h>

int main(void){
	unsigned char led=0x01;

	DDRC=0xff;

	while(1){
		led=led<<1|led>>7;
		PORTC=led;
		_delay_ms(255);
	}

	return 0;
}
