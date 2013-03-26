#pragma once

#include "Config.h"

#include "Types.h"
#include "Defines.h"

class Buffer;

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

	virtual void	Write(IN void* Data, IN size_t Size) = 0;
	virtual void	Read(OUT void* Data, IN size_t Size) = 0;

	virtual bool	IsOpened() = 0;

	virtual char*	Data() = 0;
	virtual size_t	Size() = 0;

	void			WriteString(IN const char* Str, IN bool NullTerminated = false);
	char*			ReadString(IN bool NullTerminated = false);
	char*			ReadString(IN size_t Size);

 	void			WriteRaw(IN void* Buffer, size_t Size);
 	char*			ReadRaw(IN size_t Size);

	void			WriteToBuffer(OUT Buffer* Buf);
	void			WriteFromBuffer(IN Buffer* Buf);

	DECLARE_WRITE		(sint8,		WriteSINT8);
	DECLARE_READ		(sint8,		ReadSINT8)
	DECLARE_WRITE_ARRAY (sint8,		WriteSINT8);
	DECLARE_READ_ARRAY	(sint8,		ReadSINT8);
	
	DECLARE_WRITE		(uint8,		WriteUINT8);
	DECLARE_READ		(uint8,		ReadUINT8)
	DECLARE_WRITE_ARRAY (uint8,		WriteUINT8);
	DECLARE_READ_ARRAY	(uint8,		ReadUINT8);
	
	DECLARE_WRITE		(sint16,	WriteSINT16);
	DECLARE_READ		(sint16,	ReadSINT16)
	DECLARE_WRITE_ARRAY (sint16,	WriteSINT16);
	DECLARE_READ_ARRAY	(sint16,	ReadSINT16);

	DECLARE_WRITE		(uint16,	WriteUINT16);
	DECLARE_READ		(uint16,	ReadUINT16)
	DECLARE_WRITE_ARRAY (uint16,	WriteUINT16);
	DECLARE_READ_ARRAY	(uint16,	ReadUINT16);

	DECLARE_WRITE		(sint32,	WriteSINT32);
	DECLARE_READ		(sint32,	ReadSINT32)
	DECLARE_WRITE_ARRAY (sint32,	WriteSINT32);
	DECLARE_READ_ARRAY	(sint32,	ReadSINT32);

	DECLARE_WRITE		(uint32,	WriteUINT32);
	DECLARE_READ		(uint32,	ReadUINT32)
	DECLARE_WRITE_ARRAY (uint32,	WriteUINT32);
	DECLARE_READ_ARRAY	(uint32,	ReadUINT32);

	DECLARE_WRITE		(sint64,	WriteSINT64);
	DECLARE_READ		(sint64,	ReadSINT64)
	DECLARE_WRITE_ARRAY (sint64,	WriteSINT64);
	DECLARE_READ_ARRAY	(sint64,	ReadSINT64);

	DECLARE_WRITE		(uint64,	WriteUINT64);
	DECLARE_READ		(uint64,	ReadUINT64)
	DECLARE_WRITE_ARRAY (uint64,	WriteUINT64);
	DECLARE_READ_ARRAY	(uint64,	ReadUINT64);

	DECLARE_WRITE		(f32,		WriteF32);
	DECLARE_READ		(f32,		ReadF32)
	DECLARE_WRITE_ARRAY (f32,		WriteF32);
	DECLARE_READ_ARRAY	(f32,		ReadF32);

	DECLARE_WRITE		(f64,		WriteF64);
	DECLARE_READ		(f64,		ReadF64)
	DECLARE_WRITE_ARRAY (f64,		WriteF64);
	DECLARE_READ_ARRAY	(f64,		ReadF64);
};