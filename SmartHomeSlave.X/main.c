

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
uint8_t temp=0;
static void I2C_CUSTOMSlaveDefRdInterruptHandler() {
    temp = SSPBUF;
}



void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();


    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    
    I2C_Open();
    I2C_SlaveSetReadIntHandler(I2C_CUSTOMSlaveDefRdInterruptHandler);
    while (1)
    {
        if(temp>35){
        DCM_Pin0_SetHigh();
        DCM_Pin1_SetLow();
        }
        else{
        DCM_Pin0_SetLow();
        DCM_Pin1_SetLow();
        }
    }
}
