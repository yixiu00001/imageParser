#########################################################
#    Copyright (C) 2015 Inpur Inc.
#  
#    All rights reserved.
#########################################################

cmake_minimum_required(VERSION 2.6.0)
project(clcnst)


SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set (CMAKE_BUILD_TYPE Debug)

find_package( OpenCV REQUIRED )
# 查找当前目录下的所有源文件
# 添加 src 子目录
#add_subdirectory(clcnst)
#compile sub directory
aux_source_directory(. CLCNST_SRCS)
ADD_LIBRARY(clcnst SHARED  ${CLCNST_SRCS})



MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
#ADD_EXECUTABLE(hello ${DIR_SRCS})

#target_link_libraries(hello BrightFunctions)
#target_link_libraries(hello ${OpenCV_LIBS} )

