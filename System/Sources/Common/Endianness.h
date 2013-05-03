#pragma once

#include "Types.h"

namespace Endianness
{
	enum
	{
		Big,
		Little
	};
	int Check()
	{
		short Word = 0x0001;
		char* Byte = (char*) &Word;
		return(Byte[0] ? Little : Big);
	}

	u16 Swap(u16& Value)
	{
		u16 Return = Value;
		Return	=	(Return >> 8) |
					(Return << 8);

		return Return;
	}

	u32 Swap(u32& Value)
	{
		u32 Return = Value;
		Return =	(Return		>>	24)					|
					((Return	<<	8)	& 0x00FF0000)	|
					((Return	>>	8)	& 0x0000FF00)	|
					(Return		<<	24);

		return Return;
	}

	u64 Swap(u64& Value)
	{
		u64 Return = Value;
		Return =	(Return		>>	56)							|
					((Return	<<	40)	& 0x00FF000000000000)	|
					((Return	<<	24)	& 0x0000FF0000000000)	|
					((Return	<<	8)	& 0x000000FF00000000)	|
					((Return	>>	8)	& 0x00000000FF000000)	|
					((Return	>>	24)	& 0x0000000000FF0000)	|
					((Return	>>	40)	& 0x000000000000FF00)	|
					(Return		<<	56);

		return Return;
	}

	s16 Swap(s16& Value)
	{
		s16 Return = Value;
		Return =	(Return >> 8) |
					(Return << 8);

		return Return;
	}

	s32 Swap(s32& Value)
	{
		s32 Return = Value;
		Return =	(Return		>>	24)					|
					((Return	<<	8)	& 0x00FF0000)	|
					((Return	>>	8)	& 0x0000FF00)	|
					(Return		<<	24);

		return Return;
	}

	s64 Swap(s64& Value)
	{
		s64 Return = Value;
		Return =	(Return		>>	56)							|
					((Return	<<	40)	& 0x00FF000000000000)	|
					((Return	<<	24)	& 0x0000FF0000000000)	|
					((Return	<<	8)	& 0x000000FF00000000)	|
					((Return	>>	8)	& 0x00000000FF000000)	|
					((Return	>>	24)	& 0x0000000000FF0000)	|
					((Return	>>	40)	& 0x000000000000FF00)	|
					(Return		<<	56);

		return Return;
	}
}

