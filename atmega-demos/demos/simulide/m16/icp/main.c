#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "alcd.h"
#include "icp.h"

extern volatile uint32_t period;

int main(void){
    char text[16];

	alcd_init();
    alcd_clear();

	icp_init();

    while(1){
    	sprintf(text,"T=%10lu",period);
	    alcd_printf(0,0,text);
        _delay_ms(255);
    }
    return 0;
}
