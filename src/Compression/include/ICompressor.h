#pragma once

#include "Basic.h"
#include "Types.h"
#include "Defines.h"
#include "Config.h"

class ICompressor
{
public:
	struct ICompressionHeader
	{
		uint32 Signature;
	};

	virtual size_t Compress(char* Dest, size_t DestLen, const char* Src, size_t SrcLen, int CompressionLevel = 5) = 0;
	virtual void Decompress(char* Dest, size_t DestLen, const char* Src, size_t SrcLen) = 0;
};