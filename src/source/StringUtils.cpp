#include "StringUtils.h"

#include <string>
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

	memcpy(Dest, Str, MaxCount);

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

		Src++;
		Count++;
	}
}

int TokenCount(const char* Path)
{
	int Result = 0;

	//while(*Path)
	for(;;)
	{
		switch(*Path)
		{
		case '\0':
		case '/':
		case '\\':
			Result++;
			break;
		default:
			break;
		}

		// little hack, if path is C:\TestDir we'll be able to have 2 tokens and get last one for some purposes :)
		if(*Path == '\0')
			break;

		Path++;
	}

	return Result;
}

char* PathToken(const char* Path, int Token)
{
	size_t	Length			= strlen(Path);
	int		Count			= 0;
	int	CountToken		= 0;
	int*	Tokens		= new int[128];
	memset(Tokens, 0, sizeof(int) * 128);

	const char* Ptr;
	Ptr = Path;

	char* Buffer = new char[Length];
	memset(Buffer, 0, Length);

	//while(*Ptr)
	for(;;)
	{
		switch(*Ptr)
		{
		case '\0':
		case '/':
		case '\\':
			CountToken++;
			Tokens[CountToken] = Count + 1;

			break;
		default:
			break;
		}

		if(*Ptr == '\0')
			break;

		Ptr++;
		Count++;
	}

	if(Token <= CountToken)
	{
		// -1 is to delete slash out of path
		// as Tokens[x] contains something like this: "path\"
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

char* SplitPathFromFileName(const char* FileName)
{
	int TokensCount = TokenCount(FileName);
	std::string Temp;

	// we don't add 1 to tokenscount as we don't want the filename to be append
	for(size_t i = 1; i < TokensCount; i++)
	{
		Temp.append(PathToken(FileName, i));
		Temp.append("\\");
	}

	return Strdup(Temp.c_str());
}

char* SplitFileNameFromPath(const char* Path)
{
	int TokensCount = TokenCount(Path);

	return PathToken(Path, TokensCount);
}

char* SplitExtension(const char* Path)
{
	int TokensCount = TokenCount(Path);

	std::string Temp;

	Temp = PathToken(Path, TokensCount);

	int DotPos = 0;

	if((DotPos = Temp.find(".")) == std::string::npos)
		return Strdup(Temp.c_str());

	int BufferSize = Temp.size() - DotPos;

	char* Buffer = new char[BufferSize];
	Temp.copy(Buffer, BufferSize, DotPos);
	Buffer[BufferSize] = '\0';

	return Buffer;
}