set(DEPENDENT_MP_BIN2HEXdspic33ak512mps512_2_default_DrlWevia "c:/Program Files/Microchip/xc-dsc/v3.31.01/bin/xc-dsc-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFdspic33ak512mps512_2_default_DrlWevia ${CMAKE_CURRENT_LIST_DIR}/../../../../out/dspic33ak512mps512_2/default.elf)
set(DEPENDENT_TARGET_DIRdspic33ak512mps512_2_default_DrlWevia ${CMAKE_CURRENT_LIST_DIR}/../../../../out/dspic33ak512mps512_2)
set(DEPENDENT_BYPRODUCTSdspic33ak512mps512_2_default_DrlWevia ${DEPENDENT_TARGET_DIRdspic33ak512mps512_2_default_DrlWevia}/${sourceFileNamedspic33ak512mps512_2_default_DrlWevia}.s)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRdspic33ak512mps512_2_default_DrlWevia}/${sourceFileNamedspic33ak512mps512_2_default_DrlWevia}.s
    COMMAND ${DEPENDENT_MP_BIN2HEXdspic33ak512mps512_2_default_DrlWevia} ${DEPENDENT_DEPENDENT_TARGET_ELFdspic33ak512mps512_2_default_DrlWevia} --image ${sourceFileNamedspic33ak512mps512_2_default_DrlWevia} ${addressdspic33ak512mps512_2_default_DrlWevia} ${modedspic33ak512mps512_2_default_DrlWevia} -mdfp=C:/Users/ksj10/.mchp_packs/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRdspic33ak512mps512_2_default_DrlWevia}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFdspic33ak512mps512_2_default_DrlWevia})
add_custom_target(
    dependent_produced_source_artifactdspic33ak512mps512_2_default_DrlWevia 
    DEPENDS ${DEPENDENT_TARGET_DIRdspic33ak512mps512_2_default_DrlWevia}/${sourceFileNamedspic33ak512mps512_2_default_DrlWevia}.s
    )
