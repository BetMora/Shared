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

char* Strndup(const char* Str, size_t MaxCount)
{
	char* Dest;
	size_t StrLen = strlen(Str);

	if(StrLen < MaxCount)
		return Strdup(Str);

	if(!Str || MaxCount < 0 || !(Dest = new char[MaxCount + 1]))
		return 0;

	memcpy(Dest, Src, MaxCount);

	Dest[MaxCount] = 0;

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
	int		Result	= 0;
	bool	HadChar = false;

	while(*Path != '\0')
	{
		switch(*Path)
		{
		case 0:
		case '/':
		case '\\':
			if(!HadChar)
				break;

			Result++;

			HadChar = false;
			break;
		default:
			HadChar = true;
			break;
		}

		Path++;
	}

}

char* PathToken(const char* Path, int* Length, int Token)
{
	size_t	Len	= 0;
	int		Count	= 0;
	bool Char = false, Slash = false;

	const char* Ptr;
	Ptr = Path;

	while(*Path != '\0')
	{
		switch(*Path)
		{
		case 0:
		case '/':
		case '\\':
			Slash = true;

			if(!Char)
				break;

			if(Count++ == Token)
			{
				while(Len && (Ptr[Len - 1] == ' '))
					Len--;

				if(Length)
					*Length = Len;

				return (char*)Ptr;
			}

			Char = false;
			break;
		default:
			Char = true;
			Len++;

			if(!Slash)
				break;

			Slash = false;

			Ptr = Path;

			Len = 1;
		}

		*Path++;
	}

	return 0;
}