#include "ap_adc.h"
#include "adc1.h"
#include "adc2.h"
#include "bsp_def.h"


typedef struct
{
    uint16_t adc_1_result[ADC1_MAX_CHANNELS];
    uint16_t adc_2_result[ADC2_MAX_CHANNELS];

    bool adc_1_interrupt_called[ADC1_MAX_CHANNELS];
    bool adc_2_interrupt_called[ADC2_MAX_CHANNELS];

    bool adc_1_comparator_flag_called[ADC1_MAX_CMPS];
    bool adc_2_comparator_flag_called[ADC2_MAX_CMPS];
}ap_adc_t;


static ap_adc_t ap_adc_inst;

static void clearAdcResults(void);
static void clearAdcCallbacks(void);
static void enableAdcInterrupts(void);

static void pollingAdcTest(void);
static void interruptAdcLoop(void);

static void initAdc1Comparator(void);  // AD1CMPSTATbits
static void LoopAdc1Comparator(void);


static uint16_t _aDC1PollingResultGet(const enum ADC1_CHANNEL channel);
static uint16_t _aDC2PollingResultGet(const enum ADC2_CHANNEL channel);

static void _aDC1InterruptCall(const enum ADC1_CHANNEL channel);
static void _aDC2InterruptCall(const enum ADC2_CHANNEL channel);

void apAdcInit(void)
{
    initAdc1Comparator();
    
    clearAdcResults();
    clearAdcCallbacks();
    enableAdcInterrupts();

    ADC1_Enable();
    ADC2_Enable();
}

void apAdcLoop(void)
{
    // pollingAdcTest();
    interruptAdcLoop();
    LoopAdc1Comparator();
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
        ap_adc_inst.adc_1_interrupt_called[i] = true;
        ADC1_IndividualChannelInterruptFlagClear(i);
    }
    for(int i = 0; i < ADC2_MAX_CHANNELS; i++)
    {
        ap_adc_inst.adc_2_interrupt_called[i] = true;
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

static void interruptAdcLoop(void)
{
    for(int i = 0; i < ADC1_MAX_CHANNELS; i++)
    {
        _aDC1InterruptCall(i);
    }
    for(int i = 0; i < ADC2_MAX_CHANNELS; i++)
    {
        _aDC2InterruptCall(i);
    }
}

static void initAdc1Comparator(void)
{
    // ADC comparator range를 충족할경우 flag -> set
    AD1CMPSTATbits.CH0FLG = 0; 
    AD1CMPSTATbits.CH1FLG = 0;
    AD1CMPSTATbits.CH2FLG = 0;

    for(int i = 0; i < ADC1_MAX_CMPS; i++)
    {
        ap_adc_inst.adc_1_comparator_flag_called[i] = false;
    }
    for(int i = 0; i < ADC2_MAX_CMPS; i++)
    {
        ap_adc_inst.adc_2_comparator_flag_called[i] = false;
    }
}

static void LoopAdc1Comparator(void)
{
    // from void __attribute__ ( ( weak ) ) ADC1_ComparatorTasks ( enum ADC1_CMP comparator )
    // 위의 함수를 참고해 아래 작성
    for(int i = 0; i < ADC1_MAX_CMPS; i++)
    {
        switch(i)
        {   
            case ADC1_CMP0:
                if(AD1CMPSTATbits.CH0FLG == 1U)
                {
                    ap_adc_inst.adc_1_comparator_flag_called[i] = true;
                    // if(NULL != ADC1_ComparatorHandler)
                    // {
                    //     (*ADC1_ComparatorHandler)(ADC1_CMP0);
                    // }
                    AD1CMPSTATbits.CH0FLG = 0U;
                }
                break;
            case ADC1_CMP1:
                if(AD1CMPSTATbits.CH1FLG == 1U)
                {
                    ap_adc_inst.adc_1_comparator_flag_called[i] = true;
                    // if(NULL != ADC1_ComparatorHandler)
                    // {
                    //     (*ADC1_ComparatorHandler)(ADC1_CMP1);
                    // }
                    AD1CMPSTATbits.CH1FLG = 0U;
                }
                break;
            case ADC1_CMP2:
                if(AD1CMPSTATbits.CH2FLG == 1U)
                {
                    ap_adc_inst.adc_1_comparator_flag_called[i] = true;
                    // if(NULL != ADC1_ComparatorHandler)
                    // {
                    //     (*ADC1_ComparatorHandler)(ADC1_CMP2);
                    // }
                    AD1CMPSTATbits.CH2FLG = 0U;
                }
                break;
            default:
                break;
        }
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

static void _aDC1InterruptCall(const enum ADC1_CHANNEL channel)
{
    if(ap_adc_inst.adc_1_interrupt_called[channel] == true)
    {
        ap_adc_inst.adc_1_interrupt_called[channel] = false;
        ADC1_ChannelSoftwareTriggerEnable(channel);
    }
}

static void _aDC2InterruptCall(const enum ADC2_CHANNEL channel)
{
    if(ap_adc_inst.adc_2_interrupt_called[channel] == true)
    {
        ap_adc_inst.adc_2_interrupt_called[channel] = false;
        ADC1_ChannelSoftwareTriggerEnable(channel);
    }
}


void ADC1_ChannelCallback(enum ADC1_CHANNEL channel, uint16_t adcVal)
{
    // Handle ADC1 channel callback
    switch(channel)
    {
        case ADC1_Channel0:
            ap_adc_inst.adc_1_interrupt_called[channel] = true;
            ap_adc_inst.adc_1_result[channel] = adcVal;
            break;
        case ADC1_Channel1:
            ap_adc_inst.adc_1_interrupt_called[channel] = true;
            ap_adc_inst.adc_1_result[channel] = adcVal;
            break;
        case ADC1_Channel2:
            ap_adc_inst.adc_1_interrupt_called[channel] = true;
            ap_adc_inst.adc_1_result[channel] = adcVal;
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
            ap_adc_inst.adc_1_interrupt_called[channel] = true;
            ap_adc_inst.adc_2_result[channel] = adcVal;
            break;
        case ADC2_Channel1:
            ap_adc_inst.adc_1_interrupt_called[channel] = true;
            ap_adc_inst.adc_2_result[channel] = adcVal;
            break;
        case ADC2_Channel2:
            ap_adc_inst.adc_1_interrupt_called[channel] = true;
            ap_adc_inst.adc_2_result[channel] = adcVal;
            break;
        default:
            break;
    }
}