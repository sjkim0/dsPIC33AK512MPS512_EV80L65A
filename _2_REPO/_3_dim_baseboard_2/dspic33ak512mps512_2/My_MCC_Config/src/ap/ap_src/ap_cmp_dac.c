#include "ap_cmp_dac.h"
#include "cmp1.h"
#include "cmp2.h"


typedef struct
{
    bool cmp_1_event_called;
    bool cmp_2_event_called;

    uint16_t cmp_1_dac_voltage;
    uint16_t cmp_2_dac_voltage;
    
    float cmp_ref_voltage;
    uint16_t cmp_resolution;

    bool cmp_1_state_get;
    bool cmp_2_state_get;
}ap_cmp_dac_t;


static ap_cmp_dac_t ap_cmp_dac_inst;


static void isCmp1Called(void);
static void isCmp2Called(void);

static void writeCmp1DacVoltage(float voltage);
static void writeCmp2DacVoltage(float voltage);


void apCmpDacInit(void)
{
    ap_cmp_dac_inst.cmp_1_event_called = false;
    ap_cmp_dac_inst.cmp_2_event_called = false;

    ap_cmp_dac_inst.cmp_1_dac_voltage = 2048; // Example voltage, adjust as needed
    ap_cmp_dac_inst.cmp_2_dac_voltage = 2048; // Example voltage, adjust as needed

    ap_cmp_dac_inst.cmp_ref_voltage = 3.3f;
    ap_cmp_dac_inst.cmp_resolution = 4096; // Example resolution, adjust as needed

    writeCmp1DacVoltage(1.0F);
    writeCmp2DacVoltage(1.5F);
}

void apCmpDacLoop(void)
{
    isCmp1Called();
    isCmp2Called();

    ap_cmp_dac_inst.cmp_1_state_get = CMP1_StatusGet();  // polling으로 cmp out 상태를 읽는다.
    ap_cmp_dac_inst.cmp_2_state_get = CMP2_StatusGet();  // polling으로 cmp out 상태를 읽는다.
}

static void isCmp1Called(void)
{
    if(IFS2bits.CMP1IF == 1U)
    {
        // CMP1 callback function 
        // if(NULL != CMP1_EventHandler)
        // {
        //     (*CMP1_EventHandler)();
        // }
    
        ap_cmp_dac_inst.cmp_1_event_called = true;
        // clear the CMP1 interrupt flag
        IFS2bits.CMP1IF = 0U;
    }
}

static void isCmp2Called(void)
{
    if(IFS2bits.CMP2IF == 1U)
    {
        // CMP2 callback function 
        // if(NULL != CMP2_EventHandler)
        // {
        //     (*CMP2_EventHandler)();
        // }
    
        ap_cmp_dac_inst.cmp_1_event_called = true;
        // clear the CMP2 interrupt flag
        IFS2bits.CMP2IF = 0U;
    }
}


static void writeCmp1DacVoltage(float voltage)
{
    if(ap_cmp_dac_inst.cmp_1_dac_voltage != voltage)
    {
        uint16_t write_buff = (size_t)((voltage / ap_cmp_dac_inst.cmp_ref_voltage) * (ap_cmp_dac_inst.cmp_resolution));
        if(write_buff >= (ap_cmp_dac_inst.cmp_resolution))
        {
            write_buff = ap_cmp_dac_inst.cmp_resolution - 1;
        }
        ap_cmp_dac_inst.cmp_1_dac_voltage = write_buff;
        CMP1_DACDataWrite(write_buff);
        CMP1_DACEnable();
    }
}

static void writeCmp2DacVoltage(float voltage)
{
    if(ap_cmp_dac_inst.cmp_2_dac_voltage != voltage)
    {
        uint16_t write_buff = (size_t)((voltage / ap_cmp_dac_inst.cmp_ref_voltage) * (ap_cmp_dac_inst.cmp_resolution));
        if(write_buff >= (ap_cmp_dac_inst.cmp_resolution))
        {
            write_buff = ap_cmp_dac_inst.cmp_resolution - 1;
        }
        ap_cmp_dac_inst.cmp_2_dac_voltage = write_buff;
        CMP2_DACDataWrite(write_buff);
        CMP2_DACEnable();
    }
}
