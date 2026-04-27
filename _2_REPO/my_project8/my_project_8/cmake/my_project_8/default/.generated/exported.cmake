set(DEPENDENT_MP_BIN2HEXmy_project_8_default_9d9NoUvH "c:/Program Files/Microchip/xc-dsc/v3.31/bin/xc-dsc-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFmy_project_8_default_9d9NoUvH ${CMAKE_CURRENT_LIST_DIR}/../../../../out/my_project_8/default.elf)
set(DEPENDENT_TARGET_DIRmy_project_8_default_9d9NoUvH ${CMAKE_CURRENT_LIST_DIR}/../../../../out/my_project_8)
set(DEPENDENT_BYPRODUCTSmy_project_8_default_9d9NoUvH ${DEPENDENT_TARGET_DIRmy_project_8_default_9d9NoUvH}/${sourceFileNamemy_project_8_default_9d9NoUvH}.s)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRmy_project_8_default_9d9NoUvH}/${sourceFileNamemy_project_8_default_9d9NoUvH}.s
    COMMAND ${DEPENDENT_MP_BIN2HEXmy_project_8_default_9d9NoUvH} ${DEPENDENT_DEPENDENT_TARGET_ELFmy_project_8_default_9d9NoUvH} --image ${sourceFileNamemy_project_8_default_9d9NoUvH} ${addressmy_project_8_default_9d9NoUvH} ${modemy_project_8_default_9d9NoUvH} -mdfp=C:/Users/ksj10/.mchp_packs/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRmy_project_8_default_9d9NoUvH}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFmy_project_8_default_9d9NoUvH})
add_custom_target(
    dependent_produced_source_artifactmy_project_8_default_9d9NoUvH 
    DEPENDS ${DEPENDENT_TARGET_DIRmy_project_8_default_9d9NoUvH}/${sourceFileNamemy_project_8_default_9d9NoUvH}.s
    )
