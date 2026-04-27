# The following functions contains all the flags passed to the different build stages.

set(PACK_REPO_PATH "C:/Users/ksj10/.mchp_packs" CACHE PATH "Path to the root of a pack repository.")

function(my_new_project_default_default_XC_DSC_assemble_rule target)
    set(options
        "-g"
        "-mcpu=33AK512MPS512"
        "-Wa,--defsym=__MPLAB_BUILD=1,--no-relax"
        "-mdfp=${PACK_REPO_PATH}/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
function(my_new_project_default_default_XC_DSC_assemblePreproc_rule target)
    set(options
        "-x"
        "assembler-with-cpp"
        "-g"
        "-mcpu=33AK512MPS512"
        "-Wa,--defsym=__MPLAB_BUILD=1,--no-relax"
        "-mdfp=${PACK_REPO_PATH}/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
function(my_new_project_default_default_XC_DSC_compile_rule target)
    set(options
        "-g"
        "-mcpu=33AK512MPS512"
        "-ffunction-sections"
        "-O0"
        "-msmart-io=1"
        "-Wall"
        "-msfr-warn=off"
        "-mdfp=${PACK_REPO_PATH}/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
function(my_new_project_default_default_XC_DSC_compile_cpp_rule target)
    set(options
        "-g"
        "${CC_PRE}"
        "-mcpu=33AK512MPS512"
        "-frtti"
        "-fexceptions"
        "-fno-check-new"
        "-fenforce-eh-specs"
        "-ffunction-sections"
        "-O1"
        "-fno-common"
        "-mdfp=${PACK_REPO_PATH}/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
function(my_new_project_default_dependentObject_rule target)
    set(options
        "-c"
        "-mcpu=33AK512MPS512"
        "-mdfp=${PACK_REPO_PATH}/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
endfunction()
function(my_new_project_default_link_rule target)
    set(options
        "-g"
        "-mcpu=33AK512MPS512"
        "-Wl,--script=p33AK512MPS512.gld,--local-stack,--defsym=__MPLAB_BUILD=1,--heap=0,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem,--memorysummary,memoryfile.xml"
        "-mdfp=${PACK_REPO_PATH}/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16")
    list(REMOVE_ITEM options "")
    target_link_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
function(my_new_project_default_bin2hex_rule target)
    add_custom_target(
        my_new_project_default_Bin2Hex ALL
        COMMAND ${MP_BIN2HEX} ${my_new_project_default_image_name} -a -mdfp=${PACK_REPO_PATH}/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16
        WORKING_DIRECTORY ${my_new_project_default_output_dir}
        BYPRODUCTS "${my_new_project_default_output_dir}/${my_new_project_default_image_base_name}.hex"
        COMMENT "Convert build file to .hex")
    add_dependencies(my_new_project_default_Bin2Hex ${target})
endfunction()
