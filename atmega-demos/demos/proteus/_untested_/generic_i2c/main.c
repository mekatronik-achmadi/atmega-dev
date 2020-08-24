#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

#include "i2c_master.h"

int main(void){
		
		i2c_start(0xe0);
		i2c_write(0x30);
		i2c_write(0x01);
		i2c_write(0x00);
		i2c_write(0x00);
		i2c_write(0x64);
		i2c_stop();

		while(1);
		return 0;
}
