/* 
 * File:   RealTimeClockDs1307.h
 * Author: minas
 *
 * Created on September 30, 2023, 11:11 AM
 */

#ifndef REALTIMECLOCKDS1307_H
#define	REALTIMECLOCKDS1307_H

#include "../mcc_generated_files/mcc.h"
#include "../AECUL/UART_Depugging_Data/UART_Depugging_Data.h"

typedef struct {
    uint8_t _Hours;
    uint8_t _Minutes;
    uint8_t _Seconds;
    uint8_t _Year;
    uint8_t _Month;
    uint8_t _day;
}RealTimeClockDS1307_t;

RealTimeClockDS1307_t RealTimeClock_Get_Date_Time(void);
void Send_Date_UART(void);

#endif	/* REALTIMECLOCKDS1307_H */

