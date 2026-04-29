set(DEPENDENT_MP_BIN2HEXmy_project_9_default_Xuje_DHC "c:/Program Files/Microchip/xc-dsc/v3.31/bin/xc-dsc-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFmy_project_9_default_Xuje_DHC ${CMAKE_CURRENT_LIST_DIR}/../../../../out/my_project_9/default.elf)
set(DEPENDENT_TARGET_DIRmy_project_9_default_Xuje_DHC ${CMAKE_CURRENT_LIST_DIR}/../../../../out/my_project_9)
set(DEPENDENT_BYPRODUCTSmy_project_9_default_Xuje_DHC ${DEPENDENT_TARGET_DIRmy_project_9_default_Xuje_DHC}/${sourceFileNamemy_project_9_default_Xuje_DHC}.s)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRmy_project_9_default_Xuje_DHC}/${sourceFileNamemy_project_9_default_Xuje_DHC}.s
    COMMAND ${DEPENDENT_MP_BIN2HEXmy_project_9_default_Xuje_DHC} ${DEPENDENT_DEPENDENT_TARGET_ELFmy_project_9_default_Xuje_DHC} --image ${sourceFileNamemy_project_9_default_Xuje_DHC} ${addressmy_project_9_default_Xuje_DHC} ${modemy_project_9_default_Xuje_DHC} -mdfp=C:/Users/ksj10/.mchp_packs/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRmy_project_9_default_Xuje_DHC}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFmy_project_9_default_Xuje_DHC})
add_custom_target(
    dependent_produced_source_artifactmy_project_9_default_Xuje_DHC 
    DEPENDS ${DEPENDENT_TARGET_DIRmy_project_9_default_Xuje_DHC}/${sourceFileNamemy_project_9_default_Xuje_DHC}.s
    )
