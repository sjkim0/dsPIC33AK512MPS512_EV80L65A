#include "bsp_def.h"


static bsp_t bsp_inst;


void bspCallbackInit(void)
{
    bsp_inst.timer_count = 0;
    for(int i = 0; i < CALLBACK_ID_MAX; i++)
    {
        bsp_inst.is_called[i] = false;
    }
}

bool bspIsCalled(enum ENUM_CALLBACK_ID callback_id)
{
    switch(callback_id)
    {
        case CALLBACK_ID_I2C1:
        {
            bool is_called = bsp_inst.is_called[CALLBACK_ID_I2C1];
            bsp_inst.is_called[CALLBACK_ID_I2C1] = false;
            return is_called;
        }
        default:
            return false;
    }
}

void setTimerCount(uint32_t count)
{
    bsp_inst.timer_count = count;
}

uint32_t getTimerCount(void)
{
    return bsp_inst.timer_count;
}

void TMR1_TimeoutCallback(void)
{
    bsp_inst.timer_count++;
}

void I2C1_Callback(void)
{
    bsp_inst.is_called[CALLBACK_ID_I2C1] = true;
}