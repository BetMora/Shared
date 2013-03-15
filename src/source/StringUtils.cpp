#include "StringUtils.h"

#include <cstring>

char* Strdup(const char* Str)
{
	char* Dest = new char[strlen(Str) + 1];

	if(Dest == 0)
		return 0;

	strcpy(Dest, Str);

	delete Str;

	return Dest;
}

char* Strndup(const char* Str, size_t MaxCount)
{
	char* Dest;
	size_t StrLen = strlen(Str);

	if(StrLen < MaxCount)
		return Strdup(Str);

	if(!Str || MaxCount < 0 || !(Dest = new char[MaxCount + 1]))
		return 0;

	memcpy(Dest, Str, MaxCount);

	Dest[MaxCount] = 0;

	delete Str;

	return Dest;
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

int TokenCount(const char* Path)
{
	int Result = 0;

	while(*Path != '\0')
	{
		switch(*Path)
		{
		case '/':
		case '\\':
			Result++;
			break;
		default:
			break;
		}

		*Path++;
	}

	return Result;
}

char* PathToken(const char* Path, int Token)
{
	size_t	Length			= strlen(Path);
	int		Count			= 0;
	int		CountToken		= 0;
	int*	Tokens			= new int[128];
	memset(Tokens, 0, sizeof(int) * 128);

	const char* Ptr;
	Ptr = Path;

	char* Buffer = new char[Length];
	memset(Buffer, 0, Length);

	while(*Ptr != '\0')
	{
		switch(*Ptr)
		{
		case '/':
		case '\\':
			CountToken++;
			Tokens[CountToken] = Count + 1;

			break;
		default:
			break;
		}

		*Ptr++;
		Count++;
	}

	if(Token <= CountToken)
	{
		// -1 is to delete slash out of path
		int TokenLength = Tokens[Token] - Tokens[Token - 1] - 1;

		int i = 0;

		for(size_t n = Tokens[Token - 1]; n < Tokens[Token]; n++)
		{
			if(i != TokenLength)
				Buffer[i] = Path[n];

			i++;
		}

		delete Tokens;

		return Buffer;
	}
	else
		return 0;
}