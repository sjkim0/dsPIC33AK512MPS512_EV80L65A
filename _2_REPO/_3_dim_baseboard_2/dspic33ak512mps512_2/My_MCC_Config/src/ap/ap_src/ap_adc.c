#include "ap_adc.h"
#include "adc1.h"
#include "adc2.h"


typedef struct
{
    uint16_t adc_1_result[ADC1_MAX_CHANNELS];
    uint16_t adc_2_result[ADC2_MAX_CHANNELS];
}ap_adc_t;


static ap_adc_t ap_adc_inst;


static uint16_t _aDC1ConversionResultGet(const enum ADC1_CHANNEL channel);
static uint16_t _aDC2ConversionResultGet(const enum ADC2_CHANNEL channel);

void apAdcInit(void)
{
    for(int i = 0; i < ADC1_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_1_result[i] = 0;
    }
    for(int i = 0; i < ADC2_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_2_result[i] = 0;
    }

    ADC1_Enable();
    ADC2_Enable();
}

void apAdcLoop(void)
{
    for(int i = 0; i < ADC1_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_1_result[i] = _aDC1ConversionResultGet(i);
    }
    for(int i = 0; i < ADC2_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_2_result[i] = _aDC2ConversionResultGet(i);
    }
}

static uint16_t _aDC1ConversionResultGet(const enum ADC1_CHANNEL channel)
{
    ADC1_ChannelSoftwareTriggerEnable(channel);
    while(ADC1_IsConversionComplete(channel) == false)
    {
    }
    return ADC1_ConversionResultGet(channel);
}

static uint16_t _aDC2ConversionResultGet(const enum ADC2_CHANNEL channel)
{
    ADC2_ChannelSoftwareTriggerEnable(channel);
    while(ADC2_IsConversionComplete(channel) == false)
    {
    }
    return ADC2_ConversionResultGet(channel);
}