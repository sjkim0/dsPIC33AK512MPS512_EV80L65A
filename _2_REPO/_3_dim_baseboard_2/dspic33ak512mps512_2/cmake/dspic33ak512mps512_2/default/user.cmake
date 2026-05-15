set(MY_MCC_CONFIG_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../My_MCC_Config")
set(MY_AP_DIR "${MY_MCC_CONFIG_DIR}/src/ap")
set(MY_BSP_DIR "${MY_MCC_CONFIG_DIR}/src/bsp")
set(MY_AP_INC_DIR "${MY_MCC_CONFIG_DIR}/src/ap/ap_inc")

set(MY_ADC_DIR "${MY_MCC_CONFIG_DIR}/mcc/mcc_generated_files/adc")
set(MY_CMD_DIR "${MY_MCC_CONFIG_DIR}/mcc/mcc_generated_files/cmp")
set(MY_I2C_HOST_DIR "${MY_MCC_CONFIG_DIR}/mcc/mcc_generated_files/i2c_host")
set(MY_INPUT_CAPTURE_DIR "${MY_MCC_CONFIG_DIR}/mcc/mcc_generated_files/input_capture")
set(MY_SPI_HOST_DIR "${MY_MCC_CONFIG_DIR}/mcc/mcc_generated_files/spi_host")
set(MY_SYS_DIR "${MY_MCC_CONFIG_DIR}/mcc/mcc_generated_files/system")
set(MY_TIMER_DIR "${MY_MCC_CONFIG_DIR}/mcc/mcc_generated_files/timer")
set(MY_UART_DIR "${MY_MCC_CONFIG_DIR}/mcc/mcc_generated_files/uart")

# include("${CMAKE_CURRENT_LIST_DIR}/.generated/main.cmake")에서
# add_library (dspic33ak512mps512_2_default_default_XC_DSC_compile) 호출단에서 lib 이름이 정해진다.
# 이 library에 target include directories해야한다.

set(MPLAB_PROJECT_NAME dspic33ak512mps512_2) # project 이름 이곳에 추가
set(COMPILE_TARGET ${MPLAB_PROJECT_NAME}_default_default_XC_DSC_compile)

if(TARGET ${COMPILE_TARGET}) # target lib dir이 존재하는지 확인
    target_include_directories(${COMPILE_TARGET} PRIVATE
                            "${MY_MCC_CONFIG_DIR}/mcc"
                            "${MY_MCC_CONFIG_DIR}/src"
                            "${MY_AP_DIR}"
                            "${MY_BSP_DIR}"
                            "${MY_AP_INC_DIR}"
                            
                            "${MY_ADC_DIR}"
                            "${MY_CMD_DIR}"
                            "${MY_I2C_HOST_DIR}"
                            "${MY_INPUT_CAPTURE_DIR}"
                            "${MY_SPI_HOST_DIR}"
                            "${MY_SYS_DIR}"
                            "${MY_TIMER_DIR}"
                            "${MY_UART_DIR}"
    )
    message(STATUS "[SUCCESS] user.cmake operate done.")
else()
    message(FATAL_ERROR "Target lib dir not found.")
endif()