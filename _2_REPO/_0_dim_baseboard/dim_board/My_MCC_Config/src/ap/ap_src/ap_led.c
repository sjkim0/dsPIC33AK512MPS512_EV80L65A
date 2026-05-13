#include "ap_led.h"
#include "pins.h"


typedef struct
{
    uint32_t delay_ms;
}ap_led_t;

static ap_led_t ap_led_inst;


void apLedInit(void)
{
    ap_led_inst.delay_ms = 100;
}

void apLedLoop(void)
{
    LD_1_SetHigh();
    __delay_ms(ap_led_inst.delay_ms);
    LD_1_SetLow();
    __delay_ms(ap_led_inst.delay_ms);
}