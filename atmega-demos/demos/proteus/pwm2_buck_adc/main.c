#include <avr/io.h>
#include <util/delay.h>

#include "pwm.h"
#include "adc.h"

int main(void){

	pwm_init();

	while(1){
		OCR2 = adc_read(0);
		_delay_ms(250);
	}
	return 0;
}
