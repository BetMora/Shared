#pragma once

#include "Config.h"

#include "Types.h"
#include "Defines.h"

#include "ICompressor.h"

class ZLIBCompressor : public ICompressor
{
public:
	struct ZLIBCompressionHeader : public ICompressor::ICompressionHeader
	{
		u32 Signature;

		ZLIBCompressionHeader()
		{
			Signature = 0x311B;
		}
	};

	virtual size_t	Compress(OUT char* Dest, IN size_t DestLen, IN const char* Src, IN size_t SrcLen, IN int CompressionLevel = 9);
	virtual size_t	Decompress(OUT char* Dest, IN size_t DestLen, IN const char* Src, IN size_t SrcLen);
};