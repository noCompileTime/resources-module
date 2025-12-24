#=======================================================================================================================
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
 target_precompile_headers(${PROJECT_NAME} PUBLIC headers.hpp)
     target_link_libraries(${PROJECT_NAME} PUBLIC common_module)
#=======================================================================================================================