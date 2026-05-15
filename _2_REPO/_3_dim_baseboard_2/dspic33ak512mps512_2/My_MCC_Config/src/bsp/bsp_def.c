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
        case CALLBACK_ID_ADC1_CH0:
        case CALLBACK_ID_ADC1_CH1:
        case CALLBACK_ID_ADC1_CH2:
        {
            bool is_called = bsp_inst.is_called[callback_id];
            bsp_inst.is_called[callback_id] = false;
            return is_called;
        }
        case CALLBACK_ID_ADC2_CH0:
        case CALLBACK_ID_ADC2_CH1:
        case CALLBACK_ID_ADC2_CH2:
        {
            bool is_called = bsp_inst.is_called[callback_id];
            bsp_inst.is_called[callback_id] = false;
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

void ADC1_ChannelCallback(enum ADC1_CHANNEL channel, uint16_t adcVal)
{
    // Handle ADC1 channel callback
    switch(channel)
    {
        case ADC1_Channel0:
            bsp_inst.is_called[CALLBACK_ID_ADC1_CH0] = true;
            break;
        case ADC1_Channel1:
            bsp_inst.is_called[CALLBACK_ID_ADC1_CH1] = true;
            break;
        case ADC1_Channel2:
            bsp_inst.is_called[CALLBACK_ID_ADC1_CH2] = true;
            break;
        default:
            break;
    }
}

void ADC2_ChannelCallback(enum ADC2_CHANNEL channel, uint16_t adcVal)
{
    switch(channel)
    {
        case ADC2_Channel0:
            bsp_inst.is_called[CALLBACK_ID_ADC2_CH0] = true;
            break;
        case ADC2_Channel1:
            bsp_inst.is_called[CALLBACK_ID_ADC2_CH1] = true;
            break;
        case ADC2_Channel2:
            bsp_inst.is_called[CALLBACK_ID_ADC2_CH2] = true;
            break;
        default:
            break;
    }
}