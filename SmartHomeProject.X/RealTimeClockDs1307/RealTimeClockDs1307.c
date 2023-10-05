/* 
 * File:   RealTimeClockDs1307.c
 * Author: minas
 *
 * Created on September 30, 2023, 11:11 AM
 */


#include "RealTimeClockDs1307.h"
#include "../mcc_generated_files/examples/i2c_master_example.h"
#include "../mcc_generated_files/eusart.h"


static uint8_t Date_pack[8]={0};
static RealTimeClockDS1307_t Time_Clock_Date;


RealTimeClockDS1307_t RealTimeClock_Get_Date_Time(void){
    Time_Clock_Date._Hours = I2C_Read1ByteRegister(0x68,0x02);
    Time_Clock_Date._Minutes = I2C_Read1ByteRegister(0x68,0x01);
    Time_Clock_Date._Month = I2C_Read1ByteRegister(0x68,0x05);
    Time_Clock_Date._Seconds = I2C_Read1ByteRegister(0x68,0x00);
    Time_Clock_Date._Year = I2C_Read1ByteRegister(0x68,0x06);
    Time_Clock_Date._day = I2C_Read1ByteRegister(0x68,0x04);
    return Time_Clock_Date;
}


void Send_Date_UART(void){
    Date_pack[0] = ((Time_Clock_Date._day >> 4)+0x30);
    Date_pack[1] = ((Time_Clock_Date._day & 0x0F)+0x30);
    Date_pack[2] = '-';
    Date_pack[3] = ((Time_Clock_Date._Month >> 4)+0x30);
    Date_pack[4] = ((Time_Clock_Date._Month & 0x0F)+0x30);
    Date_pack[5] = '-';
    Date_pack[6] = ((Time_Clock_Date._Year >> 4)+0x30);
    Date_pack[7] = ((Time_Clock_Date._Year & 0x0F)+0x30);
    Date_pack[8] = '/';
    Date_pack[9] = ((Time_Clock_Date._Hours >> 4)+0x30);
    Date_pack[10] = ((Time_Clock_Date._Hours & 0x0F)+0x30);
    Date_pack[11] = '-';
    Date_pack[12] = ((Time_Clock_Date._Minutes >> 4)+0x30);
    Date_pack[13] = ((Time_Clock_Date._Minutes & 0x0F)+0x30);
    Date_pack[14] = '-';
    Date_pack[15] = ((Time_Clock_Date._Seconds >> 4)+0x30);
    Date_pack[16] = ((Time_Clock_Date._Seconds & 0x0F)+0x30);
    Date_pack[17] = '\r';  
    UART_SEND_STRING("Date : ", 8);
    UART_SEND_STRING(Date_pack, 18);
}