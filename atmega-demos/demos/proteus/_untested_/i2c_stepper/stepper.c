#include "stepper.h"

void stper_init(void){
	i2c_init();
}

void stper_delay(uint8_t tunda){
	for(uint8_t i = 0;i<tunda;i++){
		_delay_ms(200);
	}
}

void stper_runConti(uint8_t addr, uint8_t step, uint8_t arah, uint16_t tunda){
	i2c_start(addr);
	i2c_write(0x30);
	i2c_write(step);
	i2c_write(arah);
	i2c_write(tunda/256);
	i2c_write(tunda%256);
	i2c_stop();
}

void stper_runPulse(uint8_t addr, uint8_t step, uint8_t arah, uint16_t tunda, uint16_t jumlah){
	i2c_start(addr);
	i2c_write(0x31);
	i2c_write(step);
	i2c_write(arah);
	i2c_write(tunda/256);
	i2c_write(tunda%256);
	i2c_write(jumlah/256);
	i2c_write(jumlah%256);
	i2c_stop();
}

void stper_break(uint8_t addr){
	i2c_start(addr);
	i2c_write(0x32);
	i2c_stop();
}

void stper_stop(uint8_t addr){
	i2c_start(addr);
	i2c_write(0x33);
	i2c_stop();
}

void stper_testConn(uint8_t addr){
	uint8_t stt=1;
	while(stt==1){
		stt=i2c_start(0xE0);
		_delay_us(10);
	}
	i2c_stop();
}

void stper_testConti(uint8_t addr){
	i2c_start(addr);
	i2c_write(0x30);
	i2c_write(0x01);
	i2c_write(0x00);
	i2c_write(0x00);
	i2c_write(0x64);
	i2c_stop();
}

void stper_testPulse(uint8_t addr){
	i2c_start(addr);
	i2c_write(0x31);
	i2c_write(0x01);
	i2c_write(0x00);
	i2c_write(0x03);
	i2c_write(0xE8);
	i2c_write(0x00);
	i2c_write(0x14);
	i2c_stop();
}

void stper_testAll(uint8_t addr){
	stper_delay(5);

	stper_runConti(addr,1,0,500);
	stper_delay(20);

	stper_break(addr);
	stper_delay(20);

	stper_runPulse(addr,1,1,250,10);
	stper_delay(20);

	stper_stop(addr);
}
