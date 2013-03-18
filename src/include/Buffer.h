#pragma once

#include "Basic.h"
#include "Types.h"
#include "Stream.h"

struct BufferData;

class Buffer : public Stream
{
public:
	// by default buffer size is 8 KiB
	Buffer(size_t Size = 8192);
	virtual ~Buffer();

	virtual size_t	Write(void* Data, size_t Size);
	virtual size_t	Read(void* Data, size_t Size);

	virtual bool	IsOpened();

	void			Allocate(size_t Capacity);
	void			Resize(size_t Capactiy);

	void			Clear();

	uint8*			Data();
	size_t			Size();

	bool			IsEOF();
	void			Seek(int Offset, int SeekBase = SET);
	int				Tell();
private:
	BufferData* mData;
};