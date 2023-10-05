/* 
 * File:   TC74_Dri.h
 * Author: minas
 *
 * Created on October 3, 2023, 1:09 PM
 */

#ifndef TC74_DRI_H
#define	TC74_DRI_H

#include "../../mcc_generated_files/i2c_master.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t Temp_Sensor_TC74_ReadValue(i2c_address_t TC74_Add);

#endif	/* TC74_DRI_H */

