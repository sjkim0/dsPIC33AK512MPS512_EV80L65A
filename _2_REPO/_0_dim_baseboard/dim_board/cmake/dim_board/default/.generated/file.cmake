# The following variables contains the files used by the different stages of the build process.
set(dim_board_default_default_XC_DSC_FILE_TYPE_assemble
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/dmt_asm.s"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/where_was_i.s")
set_source_files_properties(${dim_board_default_default_XC_DSC_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${dim_board_default_default_XC_DSC_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(dim_board_default_default_XC_DSC_FILE_TYPE_assemblePreproc)
set_source_files_properties(${dim_board_default_default_XC_DSC_FILE_TYPE_assemblePreproc} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${dim_board_default_default_XC_DSC_FILE_TYPE_assemblePreproc})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(dim_board_default_default_XC_DSC_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/adc/src/adc1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/adc/src/adc2.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/cmp/src/cmp1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/cmp/src/cmp2.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/i2c_host/src/i2c1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/input_capture/src/sccp1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/input_capture/src/sccp2.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/spi_host/src/spi1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/clock.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/config_bits.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/dmt.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/interrupt.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/pins.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/reset.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/system.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/traps.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/timer/src/tmr1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/uart/src/uart1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/ap/ap.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/ap/ap_src/ap_adc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/ap/ap_src/ap_comm.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/ap/ap_src/ap_ext_dac.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/ap/ap_src/ap_fram.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/ap/ap_src/ap_led.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/bsp/bsp.c")
set_source_files_properties(${dim_board_default_default_XC_DSC_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(dim_board_default_default_XC_DSC_FILE_TYPE_compile_cpp)
set_source_files_properties(${dim_board_default_default_XC_DSC_FILE_TYPE_compile_cpp} PROPERTIES LANGUAGE CXX)
set(dim_board_default_default_XC_DSC_FILE_TYPE_link)
set(dim_board_default_default_XC_DSC_FILE_TYPE_bin2hex)
set(dim_board_default_image_name "default.elf")
set(dim_board_default_image_base_name "default")

# The output directory of the final image.
set(dim_board_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/dim_board")

# The full path to the final image.
set(dim_board_default_full_path_to_image ${dim_board_default_output_dir}/${dim_board_default_image_name})
