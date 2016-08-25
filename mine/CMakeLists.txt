#########################################################
#    Copyright (C) 2015 Inpur Inc.
#  
#    All rights reserved.
#########################################################

cmake_minimum_required(VERSION 2.6.0)
project(ImageParser)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

INCLUDE_DIRECTORIES( #相关头文件的目录
${PROJECT_BINARY_DIR}/include
)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set (CMAKE_BUILD_TYPE Debug)

find_package( OpenCV REQUIRED )
# 查找当前目录下的所有源文件

# 并将名称保存到 DIR_SRCS 变量
#aux_source_directory(lbpTest.cpp DIR_SRCS)

MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
ADD_EXECUTABLE(hello lbpTest.cpp)

#target_link_libraries(hello BrightFunctions)
target_link_libraries(hello ${OpenCV_LIBS} )

