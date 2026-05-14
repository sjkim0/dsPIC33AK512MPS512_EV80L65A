#include "ap_ext_dac.h"
#include "pins.h"
#include "spi1.h"


#define DEF_LOOP_INTERVAL (1000U)
#define DEF_DAC_DATA_FORMAT_SIZE (3U)

enum ENUM_DAC_PIN_CH
{
    ENUM_DAC_PIN_CH_0,
    ENUM_DAC_PIN_CH_1,
    ENUM_DAC_PIN_CH_2,
    ENUM_DAC_PIN_CH_3,
    ENUM_DAC_PIN_CH_LENGTH,
};

typedef struct
{
    uint32_t tick;
    uint32_t tick_interval;
    uint8_t data_format[DEF_DAC_DATA_FORMAT_SIZE];
}ap_ext_dac_t;


ap_ext_dac_t ap_ext_dac_inst;


static void disableInternalRef(void);
static void writeDacVoltage(uint8_t pin, uint16_t voltage);


void apExtDacInit(void)
{
    // HOST_CONFIG
    SPI1_Open(0);  // spi 1을 ext dac 통신에 사용하기 위해 open

    ap_ext_dac_inst.tick = millis();
    ap_ext_dac_inst.tick_interval = DEF_LOOP_INTERVAL;
    
    disableInternalRef();

    writeDacVoltage(ENUM_DAC_PIN_CH_0, 0xFFF);
    writeDacVoltage(ENUM_DAC_PIN_CH_1, 0xFFF);
    writeDacVoltage(ENUM_DAC_PIN_CH_2, 0xFFF);
    writeDacVoltage(ENUM_DAC_PIN_CH_3, 0xFFF);
}

void apExtDacLoop(void)
{
    if(millis() - ap_ext_dac_inst.tick >= ap_ext_dac_inst.tick_interval)
    {
        ap_ext_dac_inst.tick = millis();
    }
}

static void disableInternalRef(void)
{
    ap_ext_dac_inst.data_format[0] = 0x01;
    ap_ext_dac_inst.data_format[1] = 0x20;
    ap_ext_dac_inst.data_format[2] = 0x00;

    for(int i = 0; i < 5; i++)
    {
        SPI_SS_SetLow();

        SPI1_BufferWrite(ap_ext_dac_inst.data_format, sizeof(ap_ext_dac_inst.data_format));

        SPI_SS_SetHigh();
    }

}

static void writeDacVoltage(uint8_t pin, uint16_t voltage)
{
    ap_ext_dac_inst.data_format[0] = 0b00010000 | ((pin << 1) & 0b110);
    ap_ext_dac_inst.data_format[1] = (voltage >> 4) & 0xFF;
    ap_ext_dac_inst.data_format[2] = (voltage << 4) & 0xFF;

    // DAC에 전압을 쓰는 코드 작성
    SPI_SS_SetLow();

    SPI1_BufferWrite(ap_ext_dac_inst.data_format, sizeof(ap_ext_dac_inst.data_format));

    SPI_SS_SetHigh();
}