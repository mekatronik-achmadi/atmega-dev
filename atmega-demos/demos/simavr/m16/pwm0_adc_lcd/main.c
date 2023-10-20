#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "alcd.h"
#include "adc.h"
#include "pwm.h"

int main(void){
    char text[16];
#if USE_ADC_8BIT
	unsigned char vADC;
#else
	unsigned int vADC;
#endif

    alcd_init();
    alcd_clear();
    pwm_init();

    while(1){
    	vADC=adc_read(0);
    	OCR0 = vADC;
    	sprintf(text,"adc = %4i",vADC);
	    alcd_printf(0,0,text);
        _delay_ms(255);
    }
    return 0;
}
