set(DEPENDENT_MP_BIN2HEXdim_board_default_KmWvuiAj "c:/Program Files/Microchip/xc-dsc/v3.31.01/bin/xc-dsc-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFdim_board_default_KmWvuiAj ${CMAKE_CURRENT_LIST_DIR}/../../../../out/dim_board/default.elf)
set(DEPENDENT_TARGET_DIRdim_board_default_KmWvuiAj ${CMAKE_CURRENT_LIST_DIR}/../../../../out/dim_board)
set(DEPENDENT_BYPRODUCTSdim_board_default_KmWvuiAj ${DEPENDENT_TARGET_DIRdim_board_default_KmWvuiAj}/${sourceFileNamedim_board_default_KmWvuiAj}.s)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRdim_board_default_KmWvuiAj}/${sourceFileNamedim_board_default_KmWvuiAj}.s
    COMMAND ${DEPENDENT_MP_BIN2HEXdim_board_default_KmWvuiAj} ${DEPENDENT_DEPENDENT_TARGET_ELFdim_board_default_KmWvuiAj} --image ${sourceFileNamedim_board_default_KmWvuiAj} ${addressdim_board_default_KmWvuiAj} ${modedim_board_default_KmWvuiAj} -mdfp=C:/Users/ksj10/.mchp_packs/Microchip/dsPIC33AK-MP_DFP/1.3.185/xc16 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRdim_board_default_KmWvuiAj}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFdim_board_default_KmWvuiAj})
add_custom_target(
    dependent_produced_source_artifactdim_board_default_KmWvuiAj 
    DEPENDS ${DEPENDENT_TARGET_DIRdim_board_default_KmWvuiAj}/${sourceFileNamedim_board_default_KmWvuiAj}.s
    )
