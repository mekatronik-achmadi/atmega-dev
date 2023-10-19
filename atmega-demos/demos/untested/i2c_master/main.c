#include <avr/io.h>
#include <util/delay.h>

#include "i2c_master.h"
#include "hmc5883.h"

extern int16_t raw_x;
extern int16_t raw_y;
extern int16_t raw_z;
extern float headingDegrees;

int main(void){
    i2c_init();
    hmc_init();

    while(1){
        hmc_getxyz();
        _delay_ms(255);
    }
}
