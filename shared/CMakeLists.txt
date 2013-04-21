cmake_minimum_required(VERSION 2.8)

project(Shared)

include_directories(src/Buffer/include
					src/Common/include
					src/Compression/include
					src/FileSystem/include
					src/Log/include
					src/Network/include
					src/Package/include
					src/Serialization/include
					src/Stream/include
					../external
					../external/zlib-1.2.7
					../external/curl-7.29.0/include)
					
# setting variables containing source paths
					
set(BUFFER_SOURCES			src/Buffer/include/Buffer.h
							src/Buffer/source/Buffer.cpp)
					
set(COMMON_SOURCES			src/Common/include/Config.h
							src/Common/include/Defines.h
							src/Common/include/Endianness.h
							src/Common/include/Shared.h
							src/Common/include/StringUtils.h
							src/Common/source/StringUtils.cpp
							src/Common/include/Timer.h
							src/Common/source/Timer.cpp
							src/Common/include/Types.h)
					
set(COMPRESSION_SOURCES		src/Compression/include/ICompressor.h
							src/Compression/include/ZLIBCompressor.h
							src/Compression/source/ZLIBCompressor.cpp)
						
set(FILESYSTEM_SOURCES		src/FileSystem/include/Directory.h
							src/FileSystem/source/Directory.cpp
							src/FileSystem/include/File.h
							src/FileSystem/source/File.cpp
							src/FileSystem/include/FileSystem.h
							src/FileSystem/source/FileSystem.cpp)
						
set(LOG_SOURCES				src/Log/include/Log.h
							src/Log/source/Log.cpp)
						
set(NETWORK_SOURCES			src/Network/include/FileDownloader.h
							src/Network/source/FileDownloader.cpp)
						
set(SERIALIZATION_SOURCES	src/Serialization/include/ISerializable.h)

set(STREAM_SOURCES			src/Stream/include/Stream.h
							src/Stream/source/Stream.cpp)
							
set(SHARED_SOURCES			${BUFFER_SOURCES}
							${COMMON_SOURCES}
							${COMPRESSION_SOURCES}
							${FILESYSTEM_SOURCES}
							${LOG_SOURCES}
							${NETWORK_SOURCES}
							${SERIALIZATION_SOURCES}
							${STREAM_SOURCES})
							
# setting source groups for some projects

source_group(Buffer			FILES ${BUFFER_SOURCES})
source_group(Common			FILES ${COMMON_SOURCES})
source_group(Compression	FILES ${COMPRESSION_SOURCES})
source_group(FileSystem		FILES ${FILESYSTEM_SOURCES})
source_group(Log			FILES ${LOG_SOURCES})
source_group(Network		FILES ${NETWORK_SOURCES})
source_group(Serialization	FILES ${SERIALIZATION_SOURCES})
source_group(Stream			FILES ${STREAM_SOURCES})

add_library(Shared STATIC ${SHARED_SOURCES})