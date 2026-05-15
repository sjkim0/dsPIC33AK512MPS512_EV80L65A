#include "ap_fram.h"
#include "bsp.h"
#include "i2c1.h"


#define DEF_LOOP_INTERVAL (1000U)
#define DEF_BUFFER_LENGTH (256U)


enum ENUM_I2C_ERROR
{
    ENUM_I2C_ERROR_NONE = 0,
    ENUM_I2C_ERROR_NACK_RECEIVED,
    ENUM_I2C_ERROR_BUS_COLLISION,
};

typedef struct
{
    uint32_t interval;
    uint32_t tick;
    bool is_i2c_busy;
    bool is_i2c_interrupt_called;
    uint8_t tx_buffer[DEF_BUFFER_LENGTH];
    uint8_t rx_buffer[DEF_BUFFER_LENGTH];

    uint8_t fram_address;
    uint8_t tx_address_msb;
    uint8_t tx_address_lsb;
    bool is_read_called;

    enum ENUM_I2C_ERROR is_i2c_error;
}ap_fram_t;


static ap_fram_t ap_fram_inst;


static bool _isFramBusy(void);
static void _framWrite(uint16_t write_address, uint8_t *data, int data_length);
static void _framRead(uint16_t read_address, int data_length);


void apFramInit(void)
{
    ap_fram_inst.tick = millis();
    ap_fram_inst.interval = DEF_LOOP_INTERVAL;
    ap_fram_inst.is_i2c_busy = _isFramBusy();
    ap_fram_inst.is_i2c_interrupt_called = false;
    ap_fram_inst.fram_address = 0x50; // slave id 7bit address
    ap_fram_inst.is_i2c_error = ENUM_I2C_ERROR_NONE;

    _framWrite(0x0000, (uint8_t*)"Hello, FRAM!", 13);
}

void apFramLoop(void)
{
    if (millis() - ap_fram_inst.tick >= ap_fram_inst.interval)
    {
        ap_fram_inst.tick = millis();
        ap_fram_inst.is_i2c_busy = _isFramBusy();
        ap_fram_inst.is_i2c_interrupt_called = bspIsCalled(CALLBACK_ID_I2C1);

        bool is_readable = !ap_fram_inst.is_i2c_busy && ap_fram_inst.is_i2c_interrupt_called;

        ap_fram_inst.is_i2c_error = I2C1_ErrorGet();
        if(ap_fram_inst.is_i2c_error == ENUM_I2C_ERROR_NONE)
        {
            if (is_readable == true)
            {
                // I2C 인터럽트가 호출된 경우, 필요한 작업을 수행
                ap_fram_inst.is_i2c_interrupt_called = false;
                if (ap_fram_inst.is_read_called == false)
                {
                    _framRead(0x0000, 13);
                }
            }
        }
        else if(ap_fram_inst.is_i2c_error == ENUM_I2C_ERROR_NACK_RECEIVED)
        {
            // NACK received
        }
        else if(ap_fram_inst.is_i2c_error == ENUM_I2C_ERROR_BUS_COLLISION)
        {
            // Bus collision occurred
        }
    }
}

static bool _isFramBusy(void)
{
    return I2C1_IsBusy();
}

static void _framWrite(uint16_t write_address, uint8_t *data, int data_length)
{
    if(data_length > (DEF_BUFFER_LENGTH - 2))
    {
        // 데이터 길이가 버퍼 크기를 초과
        return;
    }

    ap_fram_inst.tx_address_msb = (write_address >> 8) & 0xFF; // 상위 8비트
    ap_fram_inst.tx_address_lsb = write_address & 0xFF; // 하위 8비트
    ap_fram_inst.tx_buffer[0] = ap_fram_inst.tx_address_msb;
    ap_fram_inst.tx_buffer[1] = ap_fram_inst.tx_address_lsb;

    memcpy(&ap_fram_inst.tx_buffer[2], data, data_length); // 데이터 복사

    if(I2C1_Write(ap_fram_inst.fram_address, 
                  ap_fram_inst.tx_buffer, 
                  (size_t)(data_length + 2)) == true)
    {
        // Write successful
        ap_fram_inst.is_read_called = false; // 읽기 상태 초기화
    }
}

static void _framRead(uint16_t read_address, int data_length)
{
    if(data_length > DEF_BUFFER_LENGTH)
    {
        // 데이터 길이가 버퍼 크기를 초과
        return;
    }

    ap_fram_inst.tx_address_msb = (read_address >> 8) & 0xFF; // 상위 8비트
    ap_fram_inst.tx_address_lsb = read_address & 0xFF; // 하위 8비트
    ap_fram_inst.tx_buffer[0] = ap_fram_inst.tx_address_msb;
    ap_fram_inst.tx_buffer[1] = ap_fram_inst.tx_address_lsb;

    if(I2C1_WriteRead(ap_fram_inst.fram_address, 
                    ap_fram_inst.tx_buffer, 
                    2, // 주소 전송
                    ap_fram_inst.rx_buffer, 
                    (size_t)data_length) == true)
    {
        ap_fram_inst.is_read_called = true;
    }
}