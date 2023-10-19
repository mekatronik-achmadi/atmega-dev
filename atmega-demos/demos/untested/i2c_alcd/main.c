#include <avr/io.h>

#include "i2c_lcd.h"

int main(void){

    lcd_init();
    lcd_clrscr();

    while(1){
        lcd_puts_P("Test LCD");
    }
    return 0;
}
