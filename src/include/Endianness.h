#pragma once

#include "Types.h"

uint16 Swap(uint16& u16)
{
	uint16 Return = u16;
	Return =	(Return >> 8) |
				(Return << 8);

	return Return;
}

uint32 Swap(uint32& u32)
{
	uint32 Return = u32;
	Return =	(Return		>>	24)					|
				((Return	<<	8)	& 0x00FF0000)	|
				((Return	>>	8)	& 0x0000FF00)	|
				(Return		<<	24);

	return Return;
}

uint64 Swap(uint64& u64)
{
	uint64 Return = u64;
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