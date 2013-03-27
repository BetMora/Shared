cmake_minimum_required(VERSION 2.8)

project(Shared)

include_directories(src/Buffer/include
					src/Common/include
					src/Compression/include
					src/FileSystem/include
					src/Log/include
					src/Network/include
					src/Stream/include
					../external
					../external/zlib-1.2.7
					../external/curl-7.29.0/include)
					
set(INCLUDE_SHARED	src/Buffer/include/Buffer.h
					src/Common/include/Config.h
					src/Common/include/Defines.h
					src/Common/include/Endianness.h
					src/Common/include/Shared.h
					src/Common/include/StringUtils.h
					src/Common/include/Timer.h
					src/Common/include/Types.h
					src/Compression/include/ICompressor.h
					src/Compression/include/ZLIBCompressor.h
					src/FileSystem/include/Directory.h
					src/FileSystem/include/File.h
					src/FileSystem/include/FileSystem.h
					src/Log/include/Log.h
					src/Network/include/FileDownloader.h
					src/Stream/include/Stream.h)

set(SOURCE_SHARED	src/Buffer/source/Buffer.cpp
					src/Common/source/StringUtils.cpp
					src/Common/source/Timer.cpp
					src/Compression/source/ZLIBCompressor.cpp
					src/FileSystem/source/Directory.cpp
					src/FileSystem/source/File.cpp
					src/FileSystem/source/FileSystem.cpp
					src/Log/source/Log.cpp
					src/Network/source/FileDownloader.cpp
					src/Stream/source/Stream.cpp)

add_library(Shared STATIC ${INCLUDE_SHARED} ${SOURCE_SHARED})