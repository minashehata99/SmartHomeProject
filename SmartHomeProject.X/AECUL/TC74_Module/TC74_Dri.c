
#include "TC74_Dri.h"

uint8_t Temp_Sensor_TC74_ReadValue(i2c_address_t TC74_Add){
    
    uint8_t TempVAl = 0;
    TempVAl=I2C_Read1ByteRegister(TC74_Add,0x00);
    return TempVAl;
    
}