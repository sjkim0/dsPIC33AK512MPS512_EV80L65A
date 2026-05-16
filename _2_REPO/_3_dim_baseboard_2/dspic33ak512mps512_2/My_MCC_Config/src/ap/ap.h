#ifndef AP_H
#define AP_H


#include "ap_def.h"
#include "ap_comm.h"
#include "ap_led.h"
#include "ap_adc.h"
#include "ap_fram.h"
#include "ap_ext_dac.h"
#include "ap_cmp_dac.h"


void apInit(void);
void apLoop(void);


#endif
