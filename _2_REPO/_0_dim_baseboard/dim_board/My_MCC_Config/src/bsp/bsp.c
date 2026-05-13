#include "bsp.h"
#include "tmr1.h"



typedef struct
{
    uint32_t timer_count;
}bsp_t;


static bsp_t bsp_inst;


void bspInit(void)
{
    bsp_inst.timer_count = 0;

    SYSTEM_Initialize();

    TMR1_Start();
}

void TMR1_TimeoutCallback(void)
{
    bsp_inst.timer_count++;
}

uint32_t millis(void)
{
    return bsp_inst.timer_count;
}

void delay(uint32_t ms)
{
    uint32_t start_time = millis();
    while((millis() - start_time) < ms);
}