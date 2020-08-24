#include <avr/io.h>	
#include <util/delay.h>	
#include "ff.h"

#define MMC_STR_LONG 32

FATFS FatFs;
FIL Fil;
UINT bw;

char mmc_str[MMC_STR_LONG];

void create_file(void);
void append_file(uint8_t vI);

int main (void){
	DDRB |=1<<4;
	
	
	
	create_file();
	for(uint8_t i=0;i<10;i++){
		append_file(i);
		_delay_ms(100);
	}

	while(1){
		PORTB ^= 1<<4;
		_delay_ms(100);
	}
	return 0;
}

void create_file(void){
	
	f_mount(&FatFs, "", 0);
	
	sprintf(mmc_str,"record of vI\r\n");

	if (f_open(&Fil, "newfile.txt", FA_WRITE | FA_CREATE_ALWAYS) == FR_OK){
		
		f_write(&Fil, mmc_str, strlen(mmc_str), &bw);
		f_close(&Fil);
		
		if (bw == MMC_STR_LONG) {
			DDRB |= 0x10; PORTB |= 0x10;
		}
	}
	
	f_mount(0, "", 0); 
}

void append_file(uint8_t vI){
	
	f_mount(&FatFs, "", 0);
	
	sprintf(mmc_str,"vI = %4i\r\n",vI);
	
	if (f_open(&Fil, "newfile.txt", FA_WRITE | FA_OPEN_ALWAYS | FA_READ) == FR_OK){
		
		f_lseek(&Fil, f_size(&Fil));
		f_write(&Fil, mmc_str, strlen(mmc_str), &bw);
		f_close(&Fil);
		
		if (bw == MMC_STR_LONG) {
			DDRB |= 0x10; PORTB |= 0x10;
		}
	}
	
	f_mount(0, "", 0); 
}
