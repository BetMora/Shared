cmake_minimum_required(VERSION 2.8)

project(Shared)

set(INCLUDE_DIR src/include)
set(SOURCE_DIR src/source)

include_directories(${INCLUDE_DIR})
include_directories(external)

set(SOURCE_SHARED	${SOURCE_DIR}/Directory.cpp
					${SOURCE_DIR}/FileSystem.cpp
					${SOURCE_DIR}/File.cpp
					${SOURCE_DIR}/Stream.cpp
					${SOURCE_DIR}/StringUtils.cpp
					${SOURCE_DIR}/Timer.cpp)
set(HEADER_SHARED	${INCLUDE_DIR}/Config.h
					${INCLUDE_DIR}/Defines.h
					${INCLUDE_DIR}/Directory.h
					${INCLUDE_DIR}/Endianness.h
					${INCLUDE_DIR}/FileSystem.h
					${INCLUDE_DIR}/File.h
					${INCLUDE_DIR}/Shared.h
					${INCLUDE_DIR}/Stream.h
					${INCLUDE_DIR}/StringUtils.h
					${INCLUDE_DIR}/Timer.h
					${INCLUDE_DIR}/Types.h)

add_library(Shared STATIC ${HEADER_SHARED} ${SOURCE_SHARED})