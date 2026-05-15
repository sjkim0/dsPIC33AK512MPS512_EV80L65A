#include "ap_adc.h"
#include "adc1.h"
#include "adc2.h"


typedef struct
{
    uint16_t adc_1_result[ADC1_MAX_CHANNELS];
    uint16_t adc_2_result[ADC2_MAX_CHANNELS];

    bool adc_1_interrupt_called[ADC1_MAX_CHANNELS];
    bool adc_2_interrupt_called[ADC2_MAX_CHANNELS];
}ap_adc_t;


static ap_adc_t ap_adc_inst;

static void clearAdcResults(void);
static void clearAdcCallbacks(void);
static void enableAdcInterrupts(void);

static void pollingAdcTest(void);
static void interruptAdcTest(void);

static uint16_t _aDC1PollingResultGet(const enum ADC1_CHANNEL channel);
static uint16_t _aDC2PollingResultGet(const enum ADC2_CHANNEL channel);

static uint16_t _aDC1InterruptResultCall(const enum ADC1_CHANNEL channel);
static uint16_t _aDC2InterruptResultCall(const enum ADC2_CHANNEL channel);

void apAdcInit(void)
{
    clearAdcResults();
    clearAdcCallbacks();
    enableAdcInterrupts();
    
    ADC1_Enable();
    ADC2_Enable();
}

void apAdcLoop(void)
{
    // pollingAdcTest();
    interruptAdcTest();
}

static void clearAdcResults(void)
{
    for(int i = 0; i < ADC1_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_1_result[i] = 0;
    }
    for(int i = 0; i < ADC2_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_2_result[i] = 0;
    }
}

static void clearAdcCallbacks(void)
{
    for(int i = 0; i < ADC1_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_1_interrupt_called[i] = false;
        ADC1_IndividualChannelInterruptFlagClear(i);
    }
    for(int i = 0; i < ADC2_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_2_interrupt_called[i] = false;
        ADC2_IndividualChannelInterruptFlagClear(i);
    }
}

static void enableAdcInterrupts(void)
{
    for(int i = 0; i < ADC1_MAX_CHANNELS; i++)
    {
        ADC1_IndividualChannelInterruptEnable(i);
    }
    for(int i = 0; i < ADC2_MAX_CHANNELS; i++)
    {
        ADC2_IndividualChannelInterruptEnable(i);
    }
}

static void pollingAdcTest(void)
{
    clearAdcResults();
    for(int i = 0; i < ADC1_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_1_result[i] = _aDC1PollingResultGet(i);
    }
    clearAdcResults();
    for(int i = 0; i < ADC2_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_2_result[i] = 0;
        ap_adc_inst.adc_2_result[i] = _aDC2PollingResultGet(i);
    }
}

static void interruptAdcTest(void)
{
    clearAdcResults();
    for(int i = 0; i < ADC1_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_1_result[i] = _aDC1InterruptResultCall(i);
    }
    clearAdcResults();
    for(int i = 0; i < ADC2_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_2_result[i] = _aDC2InterruptResultCall(i);
    }
}

static uint16_t _aDC1PollingResultGet(const enum ADC1_CHANNEL channel)
{
    ADC1_ChannelSoftwareTriggerEnable(channel);
    while(ADC1_IsConversionComplete(channel) == false)
    {
    }
    return ADC1_ConversionResultGet(channel);
}

static uint16_t _aDC2PollingResultGet(const enum ADC2_CHANNEL channel)
{
    ADC2_ChannelSoftwareTriggerEnable(channel);
    while(ADC2_IsConversionComplete(channel) == false)
    {
    }
    return ADC2_ConversionResultGet(channel);
}

static uint16_t _aDC1InterruptResultCall(const enum ADC1_CHANNEL channel)
{
    if(ap_adc_inst.adc_1_interrupt_called[channel] == false)
    {
        ap_adc_inst.adc_1_interrupt_called[channel] = true;
        ADC1_ChannelSoftwareTriggerEnable(channel);
    }
    return ap_adc_inst.adc_1_result[channel];
}

static uint16_t _aDC2InterruptResultCall(const enum ADC2_CHANNEL channel)
{
    if(ap_adc_inst.adc_2_interrupt_called[channel] == false)
    {
        ap_adc_inst.adc_2_interrupt_called[channel] = true;
        ADC2_ChannelSoftwareTriggerEnable(channel);
    }
    return ap_adc_inst.adc_2_result[channel];
}