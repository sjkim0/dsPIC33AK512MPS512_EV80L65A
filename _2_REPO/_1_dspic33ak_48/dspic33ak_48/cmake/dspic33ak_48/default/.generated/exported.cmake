set(DEPENDENT_MP_BIN2HEXdspic33ak_48_default_5gNueavg "c:/Program Files/Microchip/xc-dsc/v3.31.01/bin/xc-dsc-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFdspic33ak_48_default_5gNueavg ${CMAKE_CURRENT_LIST_DIR}/../../../../out/dspic33ak_48/default.elf)
set(DEPENDENT_TARGET_DIRdspic33ak_48_default_5gNueavg ${CMAKE_CURRENT_LIST_DIR}/../../../../out/dspic33ak_48)
set(DEPENDENT_BYPRODUCTSdspic33ak_48_default_5gNueavg ${DEPENDENT_TARGET_DIRdspic33ak_48_default_5gNueavg}/${sourceFileNamedspic33ak_48_default_5gNueavg}.s)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRdspic33ak_48_default_5gNueavg}/${sourceFileNamedspic33ak_48_default_5gNueavg}.s
    COMMAND ${DEPENDENT_MP_BIN2HEXdspic33ak_48_default_5gNueavg} ${DEPENDENT_DEPENDENT_TARGET_ELFdspic33ak_48_default_5gNueavg} --image ${sourceFileNamedspic33ak_48_default_5gNueavg} ${addressdspic33ak_48_default_5gNueavg} ${modedspic33ak_48_default_5gNueavg} -mdfp=C:/Users/ksj10/.mchp_packs/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRdspic33ak_48_default_5gNueavg}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFdspic33ak_48_default_5gNueavg})
add_custom_target(
    dependent_produced_source_artifactdspic33ak_48_default_5gNueavg 
    DEPENDS ${DEPENDENT_TARGET_DIRdspic33ak_48_default_5gNueavg}/${sourceFileNamedspic33ak_48_default_5gNueavg}.s
    )
