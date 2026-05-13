#include "ap_led.h"
#include "pins.h"

void apLedInit(void)
{
}

void apLedLoop(void)
{
    LD_1_SetHigh();
    __delay_ms(500);
    LD_1_SetLow();
    __delay_ms(500);
}