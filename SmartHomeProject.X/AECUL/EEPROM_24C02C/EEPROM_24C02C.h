/* 
 * File:   EEPROM_24C02C.h
 * Author: minas
 *
 * Created on September 30, 2023, 6:14 PM
 */

#ifndef EEPROM_24C02C_H
#define	EEPROM_24C02C_H

#include "../../mcc_generated_files/i2c_master.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

void EEPROM_24C02C_Write_Byte(i2c_address_t EEPROM_Add, i2c_address_t Byte_Add, uint8_t data);
uint8_t EEPROM_24C02C_Read_Byte(i2c_address_t EEPROM_Add, i2c_address_t Byte_Add);

#endif	/* EEPROM_24C02C_H */

