#include <avr/io.h>
#include <util/delay.h>

#include "alcd.h"
#include "exti.h"

unsigned char vI=1;
char text[16];

int main(void){
	alcd_init();
	alcd_clear();

	exti_2_init(FALL);

	while(1){
		sprintf(text,"vI=%4i",vI);
		alcd_printf(0,0,text);
	}
	return 0;
}
