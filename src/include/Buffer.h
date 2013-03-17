#pragma once

#include "Basic.h"
#include "Stream.h"

struct BufferData;

class Buffer : public Stream
{
public:
	Buffer();
	virtual ~Buffer();

	virtual ~Stream() { }

	virtual size_t	Write(void* Data, size_t Size) = 0;
	virtual size_t	Read(void* Data, size_t Size) = 0;

	void			Allocate(size_t Size);
	void			Resize(size_t Size);
private:
	BufferData* mData;
};