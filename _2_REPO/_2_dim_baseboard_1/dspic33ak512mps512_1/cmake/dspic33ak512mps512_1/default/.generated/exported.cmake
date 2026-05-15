set(DEPENDENT_MP_BIN2HEXdspic33ak512mps512_1_default_FErFsWIU "c:/Program Files/Microchip/xc-dsc/v3.31.01/bin/xc-dsc-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFdspic33ak512mps512_1_default_FErFsWIU ${CMAKE_CURRENT_LIST_DIR}/../../../../out/dspic33ak512mps512_1/default.elf)
set(DEPENDENT_TARGET_DIRdspic33ak512mps512_1_default_FErFsWIU ${CMAKE_CURRENT_LIST_DIR}/../../../../out/dspic33ak512mps512_1)
set(DEPENDENT_BYPRODUCTSdspic33ak512mps512_1_default_FErFsWIU ${DEPENDENT_TARGET_DIRdspic33ak512mps512_1_default_FErFsWIU}/${sourceFileNamedspic33ak512mps512_1_default_FErFsWIU}.s)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRdspic33ak512mps512_1_default_FErFsWIU}/${sourceFileNamedspic33ak512mps512_1_default_FErFsWIU}.s
    COMMAND ${DEPENDENT_MP_BIN2HEXdspic33ak512mps512_1_default_FErFsWIU} ${DEPENDENT_DEPENDENT_TARGET_ELFdspic33ak512mps512_1_default_FErFsWIU} --image ${sourceFileNamedspic33ak512mps512_1_default_FErFsWIU} ${addressdspic33ak512mps512_1_default_FErFsWIU} ${modedspic33ak512mps512_1_default_FErFsWIU} -mdfp=C:/Users/ksj10/.mchp_packs/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRdspic33ak512mps512_1_default_FErFsWIU}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFdspic33ak512mps512_1_default_FErFsWIU})
add_custom_target(
    dependent_produced_source_artifactdspic33ak512mps512_1_default_FErFsWIU 
    DEPENDS ${DEPENDENT_TARGET_DIRdspic33ak512mps512_1_default_FErFsWIU}/${sourceFileNamedspic33ak512mps512_1_default_FErFsWIU}.s
    )
