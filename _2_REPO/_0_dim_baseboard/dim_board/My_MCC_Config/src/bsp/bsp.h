#ifndef BSP_H
#define BSP_H


// #include "../../mcc/mcc_generated_files/system/system.h"
// #include "../../mcc/mcc_generated_files/system/pins.h"

#include "system.h"

// delay 함수를 사용하기 위해 FCY를 정의해야함
#define FCY 200000000UL
#include <libpic30.h>


void bspInit(void);


#endif