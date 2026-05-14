#include "bsp.h"
#include "tmr1.h"



typedef struct
{
    uint32_t timer_count;
    bool i2c_called;
}bsp_t;


static bsp_t bsp_inst;


void bspInit(void)
{
    bsp_inst.timer_count = 0;
    bsp_inst.i2c_called = false;

    SYSTEM_Initialize();

    TMR1_Start();
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

bool bspIsCalled(enum ENUM_CALLBACK_ID callback_id)
{
    switch(callback_id)
    {
        case CALLBACK_ID_I2C1:
        {
            bool is_called = bsp_inst.i2c_called;
            bsp_inst.i2c_called = false;
            return is_called;
        }
        default:
            return false;
    }
}

void TMR1_TimeoutCallback(void)
{
    bsp_inst.timer_count++;
}

void I2C1_Callback(void)
{
    bsp_inst.i2c_called = true;
}