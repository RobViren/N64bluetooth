#First Try
cmake_minimum_required(VERSION 2.6)
project (Bran)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(SFML 2 COMPONENTS graphics system window REQUIRED)


include_directories(include)

SET(bridge_SRCS 	
	src/main.cpp
	src/Display.cpp
	include/Display.h
)

add_executable(${PROJECT_NAME} ${bridge_SRCS})


if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()





