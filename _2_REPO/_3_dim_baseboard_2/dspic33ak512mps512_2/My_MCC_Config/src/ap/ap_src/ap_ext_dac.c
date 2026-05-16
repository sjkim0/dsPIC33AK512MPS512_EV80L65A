#include "ap_ext_dac.h"
#include "pins.h"
#include "spi1.h"


#define DEF_LOOP_INTERVAL (1U)
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

    uint16_t test_voltage;

    uint16_t now_dac_voltage[ENUM_DAC_PIN_CH_LENGTH];
    float dac_reference_voltage;
    uint16_t dac_resolution;
}ap_ext_dac_t;


ap_ext_dac_t ap_ext_dac_inst;


static void disableInternalRef(void);
static void writeDacVoltage12bit(uint8_t pin, uint16_t voltage);
static void writeDacVoltageVoltage(uint8_t pin, float voltage);

void apExtDacInit(void)
{
    // HOST_CONFIG
    SPI1_Open(0);  // spi 1을 ext dac 통신에 사용하기 위해 open

    ap_ext_dac_inst.tick = millis();
    ap_ext_dac_inst.tick_interval = DEF_LOOP_INTERVAL;
    ap_ext_dac_inst.dac_reference_voltage = 3.3f;  // 예: 5V 참조 전압
    ap_ext_dac_inst.dac_resolution = 4096;  // 12-bit DAC
    disableInternalRef();

    writeDacVoltage12bit(ENUM_DAC_PIN_CH_0, 0xFFF);
    writeDacVoltage12bit(ENUM_DAC_PIN_CH_1, 0xFFF);
    writeDacVoltage12bit(ENUM_DAC_PIN_CH_2, 0xFFF);
    writeDacVoltage12bit(ENUM_DAC_PIN_CH_3, 0xFFF);
}

void apExtDacLoop(void)
{
    if(millis() - ap_ext_dac_inst.tick >= ap_ext_dac_inst.tick_interval)
    {
        ap_ext_dac_inst.tick = millis();
        writeDacVoltageVoltage(ENUM_DAC_PIN_CH_0, 1.0f);
        writeDacVoltageVoltage(ENUM_DAC_PIN_CH_1, 1.1f);
        writeDacVoltageVoltage(ENUM_DAC_PIN_CH_2, 3.3f);
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
static void writeDacVoltage12bit(uint8_t pin, uint16_t voltage)
{
    ap_ext_dac_inst.data_format[0] = 0b00010000 | ((pin << 1) & 0b110);
    ap_ext_dac_inst.data_format[1] = (voltage >> 4) & 0xFF;
    ap_ext_dac_inst.data_format[2] = (voltage << 4) & 0xFF;

    if(ap_ext_dac_inst.now_dac_voltage[pin] != voltage)
    {
        ap_ext_dac_inst.now_dac_voltage[pin] = voltage;

        // DAC에 전압을 쓰는 코드 작성
        SPI_SS_SetLow();
        SPI1_BufferWrite(ap_ext_dac_inst.data_format, sizeof(ap_ext_dac_inst.data_format));
        SPI_SS_SetHigh();
    }
}

static void writeDacVoltageVoltage(uint8_t pin, float voltage)
{
    uint16_t dac_value = (uint16_t)((voltage / ap_ext_dac_inst.dac_reference_voltage) * (ap_ext_dac_inst.dac_resolution));
    if(dac_value >= (ap_ext_dac_inst.dac_resolution))
    {
        dac_value = ap_ext_dac_inst.dac_resolution - 1;
    }
    else if(dac_value < 0)
    {
        dac_value = 0;
    }
    writeDacVoltage12bit(pin, dac_value);
}