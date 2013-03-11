#pragma once

#include "Types.h"
#include "Defines.h"

class Stream
{
public:
	enum
	{
		SET,
		BEG,
		CUR,
		END
	};

	virtual ~Stream() { }

	virtual size_t	Write(void* Data, size_t Size) = 0;
	virtual size_t	Read(void* Data, size_t Size) = 0;

	virtual bool	IsOpened() = 0;

	void			WriteString(const char* Str, bool NullTerminated = false);
	char*			ReadString(bool NullTerminated = false);
	char*			ReadString(size_t Size);

	char*			ReadRaw(size_t Size);

	DECLARE_WRITE		(sint8,		WriteSINT8);
	DECLARE_READ		(sint8,		ReadSINT8)
	
	DECLARE_WRITE		(uint8,		WriteUINT8);
	DECLARE_READ		(uint8,		ReadUINT8)
	
	DECLARE_WRITE		(sint16,	WriteSINT16);
	DECLARE_READ		(sint16,	ReadSINT16)

	DECLARE_WRITE		(uint16,	WriteUINT16);
	DECLARE_READ		(uint16,	ReadUINT16)

	DECLARE_WRITE		(sint32,	WriteSINT32);
	DECLARE_READ		(sint32,	ReadSINT32)

	DECLARE_WRITE		(uint32,	WriteUINT32);
	DECLARE_READ		(uint32,	ReadUINT32)

	DECLARE_WRITE		(sint64,	WriteSINT64);
	DECLARE_READ		(sint64,	ReadSINT64)

	DECLARE_WRITE		(uint64,	WriteUINT64);
	DECLARE_READ		(uint64,	ReadUINT64)

	DECLARE_WRITE		(f32,		WriteF32);
	DECLARE_READ		(f32,		ReadF32)

	DECLARE_WRITE		(f64,		WriteF64);
	DECLARE_READ		(f64,		ReadF64)
};

// todo
// write/read array