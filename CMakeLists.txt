cmake_minimum_required(VERSION 3.1.3)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER "arm-hisiv500-linux-gcc")
set(CMAKE_CXX_COMPILER "arm-hisiv500-linux-g++")

project(hisi_app)

include_directories(${PROJECT_SOURCE_DIR}/comm/libmedia)
link_directories(${PROJECT_SOURCE_DIR}/comm/libmedia)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -pthread")

#Link System lib
link_libraries(pthread)
link_libraries(dl)
link_libraries(rt)
link_libraries(m)

#build app
add_subdirectory(src/app)