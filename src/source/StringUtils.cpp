#include "StringUtils.h"

#include <cstring>

char* Strdup(const char* Str)
{
	char* Dest = new char[strlen(Str) + 1];

	if(Dest == 0)
		return 0;

	strcpy(Dest, Str);

	return Dest;
}

char* ConvertSlash(const char* Str)
{
	char*	Buffer	= Strdup(Str);
	char*	Ptr		= Strdup(Str);
	int		Count	= 0;

	while(*Ptr != '\0')
	{
		switch(*Ptr)
		{
		case '/':
			Buffer[Count] = '\\';
			break;
		case '\\':
			Buffer[Count] = '/';
			break;
		default:
			break;
		}

		// takes first element of the char array and increments it to next
		*Ptr++;
		Count++;
	}

	Ptr = 0;
	delete Ptr;

	return Buffer;
}

void ConvertSlash(const char* Src, char* Dst)
{
	int Count = 0;
	strcpy(Dst, Src);

	while(*Src != '\0')
	{
		switch(*Src)
		{
		case '/':
			Dst[Count] = '\\';
			break;
		case '\\':
			Dst[Count] = '/';
			break;
		default:
			break;
		}

		*Src++;
		Count++;
	}
}