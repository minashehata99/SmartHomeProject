/* 
 * File:   UART_Depugging_Data.c
 * Author: minas
 *
 * Created on September 30, 2023, 1:14 PM
 */


#include "UART_Depugging_Data.h"

void UART_SEND_STRING(uint8_t *string, uint8_t sting_lenght){
    uint8_t l_sting_lenght = 0;
    for(l_sting_lenght = 0; l_sting_lenght<sting_lenght; l_sting_lenght++){
    EUSART_Write(*string++);
    }
}