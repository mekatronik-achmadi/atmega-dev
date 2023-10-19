#include "hmc5883.h"

int16_t raw_x = 0;
int16_t raw_y = 0;
int16_t raw_z = 0;
float headingDegrees = 0;

void hmc_init(void){
    i2c_start(HMC5883L_WRITE);
    i2c_write(0x00);
    i2c_write(0x70);
    i2c_stop();

    i2c_start(HMC5883L_WRITE);
    i2c_write(0x01);
    i2c_write(0xA0);
    i2c_stop();

    i2c_start(HMC5883L_WRITE);
    i2c_write(0x02);
    i2c_write(0x00);
    i2c_stop();
}

void hmc_getxyz(void){
    i2c_start(HMC5883L_WRITE);
    i2c_write(0x03);
    i2c_stop();

    i2c_start(HMC5883L_READ);

    raw_x = ((unsigned char) i2c_read_ack())<<8;
    raw_x |= (unsigned char) i2c_read_ack();

    raw_y = ((unsigned char) i2c_read_ack())<<8;
    raw_y |= (unsigned char) i2c_read_ack();

    raw_z = ((unsigned char) i2c_read_ack())<<8;
    raw_z |= (unsigned char) i2c_read_ack();

    i2c_stop();

    headingDegrees = atan2((double)raw_y,(double)raw_x) * 180 / 3.141592654 + 180;
}
