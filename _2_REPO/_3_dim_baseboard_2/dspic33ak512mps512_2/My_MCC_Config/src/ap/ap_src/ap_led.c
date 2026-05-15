#include "ap_led.h"
#include "bsp.h"
#include "pins.h"


typedef struct
{
    uint32_t delay_ms;
    uint32_t tick_ms;

    bool is_high;
}ap_led_t;

static ap_led_t ap_led_inst;


void apLedInit(void)
{
    LD_1_SetLow();
    ap_led_inst.delay_ms = 250;
    ap_led_inst.tick_ms = millis();
    ap_led_inst.is_high = false;
}

void apLedLoop(void)
{
    if(millis() - ap_led_inst.tick_ms >= ap_led_inst.delay_ms)
    {
        ap_led_inst.tick_ms = millis();
        ap_led_inst.is_high = !ap_led_inst.is_high;
        if(ap_led_inst.is_high)
        {
            LD_1_SetHigh();
        }
        else
        {
            LD_1_SetLow();
        }
    }
}