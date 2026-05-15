include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(dspic33ak512mps512_1_default_library_list )

# Handle files with suffix s, for group default-XC-DSC
if(dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_assemble)
add_library(dspic33ak512mps512_1_default_default_XC_DSC_assemble OBJECT ${dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_assemble})
    dspic33ak512mps512_1_default_default_XC_DSC_assemble_rule(dspic33ak512mps512_1_default_default_XC_DSC_assemble)
    list(APPEND dspic33ak512mps512_1_default_library_list "$<TARGET_OBJECTS:dspic33ak512mps512_1_default_default_XC_DSC_assemble>")

endif()

# Handle files with suffix S, for group default-XC-DSC
if(dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_assemblePreproc)
add_library(dspic33ak512mps512_1_default_default_XC_DSC_assemblePreproc OBJECT ${dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_assemblePreproc})
    dspic33ak512mps512_1_default_default_XC_DSC_assemblePreproc_rule(dspic33ak512mps512_1_default_default_XC_DSC_assemblePreproc)
    list(APPEND dspic33ak512mps512_1_default_library_list "$<TARGET_OBJECTS:dspic33ak512mps512_1_default_default_XC_DSC_assemblePreproc>")

endif()

# Handle files with suffix c, for group default-XC-DSC
if(dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_compile)
add_library(dspic33ak512mps512_1_default_default_XC_DSC_compile OBJECT ${dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_compile})
    dspic33ak512mps512_1_default_default_XC_DSC_compile_rule(dspic33ak512mps512_1_default_default_XC_DSC_compile)
    list(APPEND dspic33ak512mps512_1_default_library_list "$<TARGET_OBJECTS:dspic33ak512mps512_1_default_default_XC_DSC_compile>")

endif()

# Handle files with suffix cpp, for group default-XC-DSC
if(dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_compile_cpp)
add_library(dspic33ak512mps512_1_default_default_XC_DSC_compile_cpp OBJECT ${dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_compile_cpp})
    dspic33ak512mps512_1_default_default_XC_DSC_compile_cpp_rule(dspic33ak512mps512_1_default_default_XC_DSC_compile_cpp)
    list(APPEND dspic33ak512mps512_1_default_library_list "$<TARGET_OBJECTS:dspic33ak512mps512_1_default_default_XC_DSC_compile_cpp>")

endif()

# Handle files with suffix s, for group default-XC-DSC
if(dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_dependentObject)
add_library(dspic33ak512mps512_1_default_default_XC_DSC_dependentObject OBJECT ${dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_dependentObject})
    dspic33ak512mps512_1_default_default_XC_DSC_dependentObject_rule(dspic33ak512mps512_1_default_default_XC_DSC_dependentObject)
    list(APPEND dspic33ak512mps512_1_default_library_list "$<TARGET_OBJECTS:dspic33ak512mps512_1_default_default_XC_DSC_dependentObject>")

endif()

# Handle files with suffix elf, for group default-XC-DSC
if(dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_bin2hex)
add_library(dspic33ak512mps512_1_default_default_XC_DSC_bin2hex OBJECT ${dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_bin2hex})
    dspic33ak512mps512_1_default_default_XC_DSC_bin2hex_rule(dspic33ak512mps512_1_default_default_XC_DSC_bin2hex)
    list(APPEND dspic33ak512mps512_1_default_library_list "$<TARGET_OBJECTS:dspic33ak512mps512_1_default_default_XC_DSC_bin2hex>")

endif()


# Main target for this project
add_executable(dspic33ak512mps512_1_default_image_FErFsWIU ${dspic33ak512mps512_1_default_library_list})

if(NOT CMAKE_HOST_WIN32)
    set_target_properties(dspic33ak512mps512_1_default_image_FErFsWIU PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${dspic33ak512mps512_1_default_output_dir}")
endif()
set_target_properties(dspic33ak512mps512_1_default_image_FErFsWIU PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf")
target_link_libraries(dspic33ak512mps512_1_default_image_FErFsWIU PRIVATE ${dspic33ak512mps512_1_default_default_XC_DSC_FILE_TYPE_link})

# Add the link options from the rule file.
dspic33ak512mps512_1_default_link_rule( dspic33ak512mps512_1_default_image_FErFsWIU)

# Call bin2hex function from the rule file
dspic33ak512mps512_1_default_bin2hex_rule(dspic33ak512mps512_1_default_image_FErFsWIU)
if(CMAKE_HOST_WIN32)
    add_custom_command(
        TARGET dspic33ak512mps512_1_default_image_FErFsWIU
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${dspic33ak512mps512_1_default_output_dir}
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dspic33ak512mps512_1_default_image_FErFsWIU> ${dspic33ak512mps512_1_default_output_dir}/${dspic33ak512mps512_1_default_original_image_name}
        BYPRODUCTS ${dspic33ak512mps512_1_default_output_dir}/${dspic33ak512mps512_1_default_original_image_name}
        COMMENT "Copying elf to out location")
    set_property(
        TARGET dspic33ak512mps512_1_default_image_FErFsWIU
        APPEND PROPERTY ADDITIONAL_CLEAN_FILES
        ${dspic33ak512mps512_1_default_output_dir}/${dspic33ak512mps512_1_default_original_image_name})
endif()

