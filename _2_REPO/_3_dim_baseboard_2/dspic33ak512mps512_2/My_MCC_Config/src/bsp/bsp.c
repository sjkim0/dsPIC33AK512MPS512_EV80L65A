#include "bsp.h"


void bspInit(void)
{
    SYSTEM_Initialize();
    bspCallbackInit();

    TMR1_Start();
}

uint32_t millis(void)
{
    return getTimerCount();
}

void delay(uint32_t ms)
{
    uint32_t start_time = millis();
    while((millis() - start_time) < ms);
}
