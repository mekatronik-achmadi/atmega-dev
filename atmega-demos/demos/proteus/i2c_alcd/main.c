#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

#include "lcdpcf8574.h"

int main(void){
		char text[16];
		unsigned int vI=0;

		DDRA |= 1<<0;

		lcd_init(LCD_DISP_ON);
		lcd_led(0);
		lcd_clrscr();
		lcd_home();
		

		lcd_gotoxy(0,0);
   		lcd_puts("test I2C LCD");

		while(1){
			PORTA ^= 1<<0;

			vI++;

			if(vI==8) vI=0;

			sprintf(text,"I =%2i",vI);
			lcd_gotoxy(0,1);
			lcd_puts(text);

			_delay_ms(255);
		}

		return 0;
}
