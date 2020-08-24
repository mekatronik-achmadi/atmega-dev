#include <avr/io.h>
#include <util/delay.h>

#include "i2c_slave.h"

extern volatile uint8_t rxbuffer[0xFF];

int main(void){
    unsigned int vResult;
    i2c_init(0x32);

    while(1){
        vResult = rxbuffer[0];
        _delay_ms(255);
    }
}
