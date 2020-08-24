#include "spi_pcd8544.h"

int main(void){
    Pcd8544Init();

    ClearScreen();

    SetTextPosition(0, 3);
    DrawString("Test LCD");
    DrawLine(20,20,40,40);
    DrawLine(30,20,50,40);
    DrawLine(40,20,60,40);
    DrawLine(50,20,70,40);
    DrawLine(60,20,80,40);
    UpdateScreen();

    while(1) {
        _delay_ms(2000);
    }
    return 0;
}
