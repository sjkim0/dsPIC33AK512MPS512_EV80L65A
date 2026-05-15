#ifndef BSP_H
#define BSP_H


// #include "../../mcc/mcc_generated_files/system/system.h"
// #include "../../mcc/mcc_generated_files/system/pins.h"

#include "system.h"
#include "stdbool.h"

// delay 함수를 사용하기 위해 FCY를 정의해야함
#define FCY 200000000UL
#include <libpic30.h>


enum ENUM_CALLBACK_ID
{
    CALLBACK_ID_I2C1 = 0,
    CALLBACK_ID_MAX
};


void bspInit(void);
uint32_t millis(void);
void delay(uint32_t ms);


bool bspIsCalled(enum ENUM_CALLBACK_ID callback_id);


#endif