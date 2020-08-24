#ifndef _STEPPER_H_
#define _STEPPER_H_

#include "util/delay.h"

#include "i2c_master.h"

#define WAIT_READY	5

void stper_init(void);

void stper_delay(uint8_t tunda);

void stper_runConti(uint8_t addr, uint8_t step, uint8_t arah, uint16_t tunda);
void stper_runPulse(uint8_t addr, uint8_t step, uint8_t arah, uint16_t tunda, uint16_t jumlah);

void stper_break(uint8_t addr);
void stper_stop(uint8_t addr);

void stper_testConn(uint8_t addr);
void stper_testConti(uint8_t addr);
void stper_testPulse(uint8_t addr);
void stper_testAll(uint8_t addr);

#endif
