include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(My_Project_default_library_list )

# Handle files with suffix s, for group default-XC-DSC
if(My_Project_default_default_XC_DSC_FILE_TYPE_assemble)
add_library(My_Project_default_default_XC_DSC_assemble OBJECT ${My_Project_default_default_XC_DSC_FILE_TYPE_assemble})
    My_Project_default_default_XC_DSC_assemble_rule(My_Project_default_default_XC_DSC_assemble)
    list(APPEND My_Project_default_library_list "$<TARGET_OBJECTS:My_Project_default_default_XC_DSC_assemble>")

endif()

# Handle files with suffix S, for group default-XC-DSC
if(My_Project_default_default_XC_DSC_FILE_TYPE_assemblePreproc)
add_library(My_Project_default_default_XC_DSC_assemblePreproc OBJECT ${My_Project_default_default_XC_DSC_FILE_TYPE_assemblePreproc})
    My_Project_default_default_XC_DSC_assemblePreproc_rule(My_Project_default_default_XC_DSC_assemblePreproc)
    list(APPEND My_Project_default_library_list "$<TARGET_OBJECTS:My_Project_default_default_XC_DSC_assemblePreproc>")

endif()

# Handle files with suffix c, for group default-XC-DSC
if(My_Project_default_default_XC_DSC_FILE_TYPE_compile)
add_library(My_Project_default_default_XC_DSC_compile OBJECT ${My_Project_default_default_XC_DSC_FILE_TYPE_compile})
    My_Project_default_default_XC_DSC_compile_rule(My_Project_default_default_XC_DSC_compile)
    list(APPEND My_Project_default_library_list "$<TARGET_OBJECTS:My_Project_default_default_XC_DSC_compile>")

endif()

# Handle files with suffix cpp, for group default-XC-DSC
if(My_Project_default_default_XC_DSC_FILE_TYPE_compile_cpp)
add_library(My_Project_default_default_XC_DSC_compile_cpp OBJECT ${My_Project_default_default_XC_DSC_FILE_TYPE_compile_cpp})
    My_Project_default_default_XC_DSC_compile_cpp_rule(My_Project_default_default_XC_DSC_compile_cpp)
    list(APPEND My_Project_default_library_list "$<TARGET_OBJECTS:My_Project_default_default_XC_DSC_compile_cpp>")

endif()

# Handle files with suffix s, for group default-XC-DSC
if(My_Project_default_default_XC_DSC_FILE_TYPE_dependentObject)
add_library(My_Project_default_default_XC_DSC_dependentObject OBJECT ${My_Project_default_default_XC_DSC_FILE_TYPE_dependentObject})
    My_Project_default_default_XC_DSC_dependentObject_rule(My_Project_default_default_XC_DSC_dependentObject)
    list(APPEND My_Project_default_library_list "$<TARGET_OBJECTS:My_Project_default_default_XC_DSC_dependentObject>")

endif()

# Handle files with suffix elf, for group default-XC-DSC
if(My_Project_default_default_XC_DSC_FILE_TYPE_bin2hex)
add_library(My_Project_default_default_XC_DSC_bin2hex OBJECT ${My_Project_default_default_XC_DSC_FILE_TYPE_bin2hex})
    My_Project_default_default_XC_DSC_bin2hex_rule(My_Project_default_default_XC_DSC_bin2hex)
    list(APPEND My_Project_default_library_list "$<TARGET_OBJECTS:My_Project_default_default_XC_DSC_bin2hex>")

endif()


# Main target for this project
add_executable(My_Project_default_image_LhabGpX0 ${My_Project_default_library_list})

if(NOT CMAKE_HOST_WIN32)
    set_target_properties(My_Project_default_image_LhabGpX0 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${My_Project_default_output_dir}")
endif()
set_target_properties(My_Project_default_image_LhabGpX0 PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf")
target_link_libraries(My_Project_default_image_LhabGpX0 PRIVATE ${My_Project_default_default_XC_DSC_FILE_TYPE_link})

# Add the link options from the rule file.
My_Project_default_link_rule( My_Project_default_image_LhabGpX0)

# Call bin2hex function from the rule file
My_Project_default_bin2hex_rule(My_Project_default_image_LhabGpX0)
if(CMAKE_HOST_WIN32)
    add_custom_command(
        TARGET My_Project_default_image_LhabGpX0
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${My_Project_default_output_dir}
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:My_Project_default_image_LhabGpX0> ${My_Project_default_output_dir}/${My_Project_default_original_image_name}
        BYPRODUCTS ${My_Project_default_output_dir}/${My_Project_default_original_image_name}
        COMMENT "Copying elf to out location")
    set_property(
        TARGET My_Project_default_image_LhabGpX0
        APPEND PROPERTY ADDITIONAL_CLEAN_FILES
        ${My_Project_default_output_dir}/${My_Project_default_original_image_name})
endif()

