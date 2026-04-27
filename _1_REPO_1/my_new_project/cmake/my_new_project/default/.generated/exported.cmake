set(DEPENDENT_MP_BIN2HEXmy_new_project_default_XfZXS_gm "c:/Program Files/Microchip/xc-dsc/v3.31/bin/xc-dsc-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFmy_new_project_default_XfZXS_gm ${CMAKE_CURRENT_LIST_DIR}/../../../../out/my_new_project/default.elf)
set(DEPENDENT_TARGET_DIRmy_new_project_default_XfZXS_gm ${CMAKE_CURRENT_LIST_DIR}/../../../../out/my_new_project)
set(DEPENDENT_BYPRODUCTSmy_new_project_default_XfZXS_gm ${DEPENDENT_TARGET_DIRmy_new_project_default_XfZXS_gm}/${sourceFileNamemy_new_project_default_XfZXS_gm}.s)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRmy_new_project_default_XfZXS_gm}/${sourceFileNamemy_new_project_default_XfZXS_gm}.s
    COMMAND ${DEPENDENT_MP_BIN2HEXmy_new_project_default_XfZXS_gm} ${DEPENDENT_DEPENDENT_TARGET_ELFmy_new_project_default_XfZXS_gm} --image ${sourceFileNamemy_new_project_default_XfZXS_gm} ${addressmy_new_project_default_XfZXS_gm} ${modemy_new_project_default_XfZXS_gm} -mdfp=C:/Users/ksj10/.mchp_packs/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRmy_new_project_default_XfZXS_gm}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFmy_new_project_default_XfZXS_gm})
add_custom_target(
    dependent_produced_source_artifactmy_new_project_default_XfZXS_gm 
    DEPENDS ${DEPENDENT_TARGET_DIRmy_new_project_default_XfZXS_gm}/${sourceFileNamemy_new_project_default_XfZXS_gm}.s
    )
