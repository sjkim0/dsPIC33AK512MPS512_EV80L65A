include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(my_project_8_default_library_list )

# Handle files with suffix s, for group default-XC-DSC
if(my_project_8_default_default_XC_DSC_FILE_TYPE_assemble)
add_library(my_project_8_default_default_XC_DSC_assemble OBJECT ${my_project_8_default_default_XC_DSC_FILE_TYPE_assemble})
    my_project_8_default_default_XC_DSC_assemble_rule(my_project_8_default_default_XC_DSC_assemble)
    list(APPEND my_project_8_default_library_list "$<TARGET_OBJECTS:my_project_8_default_default_XC_DSC_assemble>")

endif()

# Handle files with suffix S, for group default-XC-DSC
if(my_project_8_default_default_XC_DSC_FILE_TYPE_assemblePreproc)
add_library(my_project_8_default_default_XC_DSC_assemblePreproc OBJECT ${my_project_8_default_default_XC_DSC_FILE_TYPE_assemblePreproc})
    my_project_8_default_default_XC_DSC_assemblePreproc_rule(my_project_8_default_default_XC_DSC_assemblePreproc)
    list(APPEND my_project_8_default_library_list "$<TARGET_OBJECTS:my_project_8_default_default_XC_DSC_assemblePreproc>")

endif()

# Handle files with suffix c, for group default-XC-DSC
if(my_project_8_default_default_XC_DSC_FILE_TYPE_compile)
add_library(my_project_8_default_default_XC_DSC_compile OBJECT ${my_project_8_default_default_XC_DSC_FILE_TYPE_compile})
    my_project_8_default_default_XC_DSC_compile_rule(my_project_8_default_default_XC_DSC_compile)
    list(APPEND my_project_8_default_library_list "$<TARGET_OBJECTS:my_project_8_default_default_XC_DSC_compile>")

endif()

# Handle files with suffix cpp, for group default-XC-DSC
if(my_project_8_default_default_XC_DSC_FILE_TYPE_compile_cpp)
add_library(my_project_8_default_default_XC_DSC_compile_cpp OBJECT ${my_project_8_default_default_XC_DSC_FILE_TYPE_compile_cpp})
    my_project_8_default_default_XC_DSC_compile_cpp_rule(my_project_8_default_default_XC_DSC_compile_cpp)
    list(APPEND my_project_8_default_library_list "$<TARGET_OBJECTS:my_project_8_default_default_XC_DSC_compile_cpp>")

endif()

# Handle files with suffix s, for group default-XC-DSC
if(my_project_8_default_default_XC_DSC_FILE_TYPE_dependentObject)
add_library(my_project_8_default_default_XC_DSC_dependentObject OBJECT ${my_project_8_default_default_XC_DSC_FILE_TYPE_dependentObject})
    my_project_8_default_default_XC_DSC_dependentObject_rule(my_project_8_default_default_XC_DSC_dependentObject)
    list(APPEND my_project_8_default_library_list "$<TARGET_OBJECTS:my_project_8_default_default_XC_DSC_dependentObject>")

endif()

# Handle files with suffix elf, for group default-XC-DSC
if(my_project_8_default_default_XC_DSC_FILE_TYPE_bin2hex)
add_library(my_project_8_default_default_XC_DSC_bin2hex OBJECT ${my_project_8_default_default_XC_DSC_FILE_TYPE_bin2hex})
    my_project_8_default_default_XC_DSC_bin2hex_rule(my_project_8_default_default_XC_DSC_bin2hex)
    list(APPEND my_project_8_default_library_list "$<TARGET_OBJECTS:my_project_8_default_default_XC_DSC_bin2hex>")

endif()


# Main target for this project
add_executable(my_project_8_default_image_9d9NoUvH ${my_project_8_default_library_list})

if(NOT CMAKE_HOST_WIN32)
    set_target_properties(my_project_8_default_image_9d9NoUvH PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${my_project_8_default_output_dir}")
endif()
set_target_properties(my_project_8_default_image_9d9NoUvH PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf")
target_link_libraries(my_project_8_default_image_9d9NoUvH PRIVATE ${my_project_8_default_default_XC_DSC_FILE_TYPE_link})

# Add the link options from the rule file.
my_project_8_default_link_rule( my_project_8_default_image_9d9NoUvH)

# Call bin2hex function from the rule file
my_project_8_default_bin2hex_rule(my_project_8_default_image_9d9NoUvH)
if(CMAKE_HOST_WIN32)
    add_custom_command(
        TARGET my_project_8_default_image_9d9NoUvH
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${my_project_8_default_output_dir}
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:my_project_8_default_image_9d9NoUvH> ${my_project_8_default_output_dir}/${my_project_8_default_original_image_name}
        BYPRODUCTS ${my_project_8_default_output_dir}/${my_project_8_default_original_image_name}
        COMMENT "Copying elf to out location")
    set_property(
        TARGET my_project_8_default_image_9d9NoUvH
        APPEND PROPERTY ADDITIONAL_CLEAN_FILES
        ${my_project_8_default_output_dir}/${my_project_8_default_original_image_name})
endif()

