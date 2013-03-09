cmake_minimum_required(VERSION 2.8)

project(Shared)

include_directories(src/include)
include_directories(external)

set(SOURCE_SHARED src/source/Directory.cpp
				  src/source/File.cpp
				  src/source/Stream.cpp
				  src/source/StringUtils.cpp)
set(HEADER_SHARED src/include/Config.h
				  src/include/Defines.h
				  src/include/Directory.h
				  src/include/File.h
				  src/include/Shared.h
				  src/include/Stream.h
				  src/include/StringUtils.h
				  src/include/Types.h)

add_library(Shared STATIC ${HEADER_SHARED} ${SOURCE_SHARED})