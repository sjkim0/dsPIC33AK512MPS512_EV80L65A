set(MY_MCC_CONFIG_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../My_MCC_Config")
set(MY_AP_DIR "${MY_MCC_CONFIG_DIR}/src/ap")
set(MY_BSP_DIR "${MY_MCC_CONFIG_DIR}/src/bsp")
set(MY_SYS_DIR "${MY_MCC_CONFIG_DIR}/mcc/mcc_generated_files/system")


target_include_directories(dim_board_default_default_XC_DSC_compile PRIVATE
    "${MY_MCC_CONFIG_DIR}/mcc"
    "${MY_MCC_CONFIG_DIR}/src"
    "${MY_AP_DIR}"
    "${MY_BSP_DIR}"
    "${MY_SYS_DIR}"
)