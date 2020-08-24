#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "uart.h"

volatile unsigned int stt;

int main(void){
	uart_init();
	printf("system run \n\r");

	while(1){
        _delay_ms(200);
    }
    return 0;
}
