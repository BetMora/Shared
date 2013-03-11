#include "Stream.h"
#include "Config.h"
#include "Defines.h"
#include "StringUtils.h"

#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <memory>

void Stream::WriteString(const char* Str, bool NullTerminated)
{
	if(NullTerminated)
	{
		uint32 Length = strlen(Str) + 1;

		Write((void*)Str, Length);
	}
	else
	{
		uint32 Length = strlen(Str);

		WriteUINT32(Length); 

		Write((void*)Str, Length);
	}
}

char* Stream::ReadString(bool NullTerminated)
{
	if(NullTerminated)
	{
		bool		NT		= false;
		char		Tmp		= 0;
		int			Count	= 0;
		// 512 bytes is kinda enought for largest possible string in the binary
		char		Buffer[MaxStringLength];

		while(NT == false)
		{
			// read one byte from stream
			Read(&Tmp, sizeof(Tmp));
			// if byte is not null-terminating character
			if(Tmp != '\0')
			{
				// add character to the buffer
				Buffer[Count] = Tmp;
			}
			else // we've reached null-terminating character - end of string
			{
				NT = true;
				Buffer[Count] = '\0';
			}

			Count++;
		}

		return Strdup(Buffer);
	}

	uint32 Length = ReadUINT32();

	char* Buffer = new char[Length];
	//memset(Buffer, 0, sizeof(Buffer) * Length);
	memset(Buffer, 0, sizeof(Buffer));

	Read(Buffer, Length);

	Buffer[Length - 1] = '\0';

	return Buffer;	
}

char* Stream::ReadString(size_t Size)
{
	char* Buffer = new char[Size];
	memset(Buffer, 0, Size);

	Read(Buffer, Size);

	Buffer[Size - 1] = '\0';

	return Buffer;
}

char* Stream::ReadRaw(size_t Size)
{
	char		Tmp		= 0;
	int			Count	= 0;

	char*		Buffer	= new char[Size];
	//memset(Buffer, 0, sizeof(Buffer) * Size);
	memset(Buffer, 0, sizeof(Buffer));

	while(Count != Size)
	{
	 	Read(&Tmp, sizeof(Tmp));

	 	if(Tmp != '\0')
	 		Buffer[Count] = Tmp;
		else
			break;
	 
	 	Count++;
	}
	 
	Buffer[Count - 1] = '\0';
	 
	return Strdup(Buffer);
}

#ifdef BIG_ENDIAN

#undef BIG_ENDIAN

IMPLEMENT_WRITE(sint8, WriteSINT8)
IMPLEMENT_READ(sint8, ReadSINT8)

IMPLEMENT_WRITE(uint8, WriteUINT8)
IMPLEMENT_READ(uint8, ReadUINT8)

#define BIG_ENDIAN

#else

IMPLEMENT_WRITE(sint8, WriteSINT8)
IMPLEMENT_READ(sint8, ReadSINT8)

IMPLEMENT_WRITE(uint8, WriteUINT8)
IMPLEMENT_READ(uint8, ReadUINT8)

#endif
	
IMPLEMENT_WRITE(sint16, WriteSINT16)
IMPLEMENT_READ(sint16, ReadSINT16)

IMPLEMENT_WRITE(uint16, WriteUINT16)
IMPLEMENT_READ(uint16, ReadUINT16)

IMPLEMENT_WRITE(sint32, WriteSINT32)
IMPLEMENT_READ(sint32, ReadSINT32)

IMPLEMENT_WRITE(uint32, WriteUINT32)
IMPLEMENT_READ(uint32, ReadUINT32)

IMPLEMENT_WRITE(sint64, WriteSINT64)
IMPLEMENT_READ(sint64, ReadSINT64)

IMPLEMENT_WRITE(uint64, WriteUINT64)
IMPLEMENT_READ(uint64, ReadUINT64)

IMPLEMENT_WRITE(f32, WriteF32)
IMPLEMENT_READ(f32, ReadF32)

IMPLEMENT_WRITE(f64, WriteF64)
IMPLEMENT_READ(f64, ReadF64)