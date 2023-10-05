/* 
 * File:   EEPROM_24C02C.C
 * Author: minas
 *
 * Created on September 30, 2023, 6:14 PM
 */


#include "EEPROM_24C02C.h"



void EEPROM_24C02C_Write_Byte(i2c_address_t EEPROM_Add, i2c_address_t Byte_Add, uint8_t data){
    I2C_Write1ByteRegister(EEPROM_Add,Byte_Add,data);
}


uint8_t EEPROM_24C02C_Read_Byte(i2c_address_t EEPROM_Add, i2c_address_t Byte_Add){
    uint8_t RetVal = 0;
    RetVal=I2C_Read1ByteRegister(EEPROM_Add,Byte_Add);
    return RetVal;
}

