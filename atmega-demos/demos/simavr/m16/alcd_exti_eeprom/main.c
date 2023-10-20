#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>

#include "alcd.h"
#include "exti.h"

extern unsigned char vI;
char text[16];

int main(void){
	alcd_init();
	alcd_clear();

	vI=eeprom_read_byte((uint8_t*)VI_ADDR);

	exti_2_init(FALL);

	while(1){
		sprintf(text,"vI=%4i",vI);
		alcd_printf(0,0,text);
	}
	return 0;
}
