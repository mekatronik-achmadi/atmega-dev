#include <avr/io.h>
#include <util/delay.h>

#include "alcd.h"
#include "exti.h"
#include "i2c_soft.h"

unsigned char vI=1;
char text[16];

int main(void){
	
	i2csoft_init();
	
	i2csoft_start(0x40);
	i2csoft_write(vI);
	i2csoft_stop();
	
	alcd_init();
	alcd_clear();

	exti_2_init(FALL);

	while(1){
		sprintf(text,"vI=%4i",vI);
		alcd_printf(0,0,text);
	}
	return 0;
}
