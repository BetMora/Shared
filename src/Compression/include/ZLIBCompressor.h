#pragma once

#include "Basic.h"
#include "Types.h"
#include "Defines.h"
#include "Config.h"

#include "ICompressor.h"

class ZLIBCompressor : public ICompressor
{
public:
	virtual size_t Compress(char* Dest, size_t DestLen, const char* Src, size_t SrcLen, int CompressionLevel = 5);
	virtual void Decompress(char* Dest, size_t DestLen, const char* Src, size_t SrcLen);
};