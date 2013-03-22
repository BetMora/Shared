#pragma once

#include "Config.h"

#include "Types.h"
#include "Defines.h"

class ICompressor
{
public:
	struct ICompressionHeader{};

	virtual size_t	Compress(OUT char* Dest, IN size_t DestLen, IN const char* Src, IN size_t SrcLen, IN int CompressionLevel = 5) = 0;
	virtual void	Decompress(OUT char* Dest, IN size_t DestLen, IN const char* Src, IN size_t SrcLen) = 0;
};