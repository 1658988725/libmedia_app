#cmake_minimum_required(VERSION 2.8)		
#app CMakelist.txt
set(mainSRC_LIST main.c)	
add_executable(${PROJECT_NAME} ${mainSRC_LIST})	
target_link_libraries(${PROJECT_NAME} libmedia.so stdc++)
#include (${PROJECT_SOURCE_DIR}/src/libmedia/platform/sdk_040/lib/link.cmake)
#include (${PROJECT_SOURCE_DIR}/src/lib/link.cmake)