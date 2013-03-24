cmake_minimum_required(VERSION 2.8)

project(zlibcd)

include_directories(../../shared/src/Buffer/include
					../../shared/src/Common/include
					../../shared/src/Compression/include
					../../shared/src/FileSystem/include
					../../shared/src/Log/include
					../../shared/src/Stream/include)
link_directories(../../../external/zlib-1.2.7/lib)

add_executable(zlibcd src/main.cpp)

target_link_libraries(zlibcd 	Shared
								zlib)