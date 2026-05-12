include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(dim_board_default_library_list )

# Handle files with suffix s, for group default-XC-DSC
if(dim_board_default_default_XC_DSC_FILE_TYPE_assemble)
add_library(dim_board_default_default_XC_DSC_assemble OBJECT ${dim_board_default_default_XC_DSC_FILE_TYPE_assemble})
    dim_board_default_default_XC_DSC_assemble_rule(dim_board_default_default_XC_DSC_assemble)
    list(APPEND dim_board_default_library_list "$<TARGET_OBJECTS:dim_board_default_default_XC_DSC_assemble>")

endif()

# Handle files with suffix S, for group default-XC-DSC
if(dim_board_default_default_XC_DSC_FILE_TYPE_assemblePreproc)
add_library(dim_board_default_default_XC_DSC_assemblePreproc OBJECT ${dim_board_default_default_XC_DSC_FILE_TYPE_assemblePreproc})
    dim_board_default_default_XC_DSC_assemblePreproc_rule(dim_board_default_default_XC_DSC_assemblePreproc)
    list(APPEND dim_board_default_library_list "$<TARGET_OBJECTS:dim_board_default_default_XC_DSC_assemblePreproc>")

endif()

# Handle files with suffix c, for group default-XC-DSC
if(dim_board_default_default_XC_DSC_FILE_TYPE_compile)
add_library(dim_board_default_default_XC_DSC_compile OBJECT ${dim_board_default_default_XC_DSC_FILE_TYPE_compile})
    dim_board_default_default_XC_DSC_compile_rule(dim_board_default_default_XC_DSC_compile)
    list(APPEND dim_board_default_library_list "$<TARGET_OBJECTS:dim_board_default_default_XC_DSC_compile>")

endif()

# Handle files with suffix cpp, for group default-XC-DSC
if(dim_board_default_default_XC_DSC_FILE_TYPE_compile_cpp)
add_library(dim_board_default_default_XC_DSC_compile_cpp OBJECT ${dim_board_default_default_XC_DSC_FILE_TYPE_compile_cpp})
    dim_board_default_default_XC_DSC_compile_cpp_rule(dim_board_default_default_XC_DSC_compile_cpp)
    list(APPEND dim_board_default_library_list "$<TARGET_OBJECTS:dim_board_default_default_XC_DSC_compile_cpp>")

endif()

# Handle files with suffix s, for group default-XC-DSC
if(dim_board_default_default_XC_DSC_FILE_TYPE_dependentObject)
add_library(dim_board_default_default_XC_DSC_dependentObject OBJECT ${dim_board_default_default_XC_DSC_FILE_TYPE_dependentObject})
    dim_board_default_default_XC_DSC_dependentObject_rule(dim_board_default_default_XC_DSC_dependentObject)
    list(APPEND dim_board_default_library_list "$<TARGET_OBJECTS:dim_board_default_default_XC_DSC_dependentObject>")

endif()

# Handle files with suffix elf, for group default-XC-DSC
if(dim_board_default_default_XC_DSC_FILE_TYPE_bin2hex)
add_library(dim_board_default_default_XC_DSC_bin2hex OBJECT ${dim_board_default_default_XC_DSC_FILE_TYPE_bin2hex})
    dim_board_default_default_XC_DSC_bin2hex_rule(dim_board_default_default_XC_DSC_bin2hex)
    list(APPEND dim_board_default_library_list "$<TARGET_OBJECTS:dim_board_default_default_XC_DSC_bin2hex>")

endif()


# Main target for this project
add_executable(dim_board_default_image_KmWvuiAj ${dim_board_default_library_list})

if(NOT CMAKE_HOST_WIN32)
    set_target_properties(dim_board_default_image_KmWvuiAj PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${dim_board_default_output_dir}")
endif()
set_target_properties(dim_board_default_image_KmWvuiAj PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf")
target_link_libraries(dim_board_default_image_KmWvuiAj PRIVATE ${dim_board_default_default_XC_DSC_FILE_TYPE_link})

# Add the link options from the rule file.
dim_board_default_link_rule( dim_board_default_image_KmWvuiAj)

# Call bin2hex function from the rule file
dim_board_default_bin2hex_rule(dim_board_default_image_KmWvuiAj)
if(CMAKE_HOST_WIN32)
    add_custom_command(
        TARGET dim_board_default_image_KmWvuiAj
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${dim_board_default_output_dir}
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dim_board_default_image_KmWvuiAj> ${dim_board_default_output_dir}/${dim_board_default_original_image_name}
        BYPRODUCTS ${dim_board_default_output_dir}/${dim_board_default_original_image_name}
        COMMENT "Copying elf to out location")
    set_property(
        TARGET dim_board_default_image_KmWvuiAj
        APPEND PROPERTY ADDITIONAL_CLEAN_FILES
        ${dim_board_default_output_dir}/${dim_board_default_original_image_name})
endif()

