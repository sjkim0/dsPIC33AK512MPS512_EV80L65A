set(DEPENDENT_MP_BIN2HEXMy_Project_default_LhabGpX0 "c:/Program Files/Microchip/xc-dsc/v3.30/bin/xc-dsc-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFMy_Project_default_LhabGpX0 ${CMAKE_CURRENT_LIST_DIR}/../../../../out/My_Project/default.elf)
set(DEPENDENT_TARGET_DIRMy_Project_default_LhabGpX0 ${CMAKE_CURRENT_LIST_DIR}/../../../../out/My_Project)
set(DEPENDENT_BYPRODUCTSMy_Project_default_LhabGpX0 ${DEPENDENT_TARGET_DIRMy_Project_default_LhabGpX0}/${sourceFileNameMy_Project_default_LhabGpX0}.s)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRMy_Project_default_LhabGpX0}/${sourceFileNameMy_Project_default_LhabGpX0}.s
    COMMAND ${DEPENDENT_MP_BIN2HEXMy_Project_default_LhabGpX0} ${DEPENDENT_DEPENDENT_TARGET_ELFMy_Project_default_LhabGpX0} --image ${sourceFileNameMy_Project_default_LhabGpX0} ${addressMy_Project_default_LhabGpX0} ${modeMy_Project_default_LhabGpX0} -mdfp=C:/Users/ksj10/.mchp_packs/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRMy_Project_default_LhabGpX0}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFMy_Project_default_LhabGpX0})
add_custom_target(
    dependent_produced_source_artifactMy_Project_default_LhabGpX0 
    DEPENDS ${DEPENDENT_TARGET_DIRMy_Project_default_LhabGpX0}/${sourceFileNameMy_Project_default_LhabGpX0}.s
    )
