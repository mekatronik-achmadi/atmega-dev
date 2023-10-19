#ifndef HMC5883_H_INCLUDED
#define HMC5883_H_INCLUDED

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

#include "i2c_master.h"

#define HMC5883L_WRITE 0x3C
#define HMC5883L_READ 0x3D

void hmc_init(void);
void hmc_getxyz(void);

#endif // HMC5883_H_INCLUDED
