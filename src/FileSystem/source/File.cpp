#include "File.h"

#include <cstring>
#include <fstream>

struct File::FileData
{
	std::fstream	File;
	char*			Name;
};

File::File(IN const char* Name)
{
	mData		= new FileData();
	mData->Name = 0;

	if(Name != 0)
		Open(Name);
}

File::~File()
{
	delete mData;
}

bool File::Open(IN const char* Name)
{
	mData->File.open(Name, std::ios::binary|std::ios::out|std::ios::in|std::ios::app);

	if(mData->File.is_open())
	{
		mData->Name = new char[strlen(Name) + 1];
		strcpy(mData->Name, Name);

		return true;
	}

	return false;
}

bool File::Close()
{
	if(mData->File.is_open())
		mData->File.close();
	else
		return false;

	delete [] mData->Name;

	return true;
}

bool File::IsOpened()
{
	if(mData->File.is_open())
		return true;

	return false;
}

void File::Write(IN void* Data, IN size_t Size)
{
	mData->File.write((char*)Data, Size);
}

void File::Read(IN void* Data, IN size_t Size)
{
	mData->File.read((char*)Data, Size);
}

char* File::Data()
{
	return 0;
}

char* File::Name()
{
	return mData->Name;
}

size_t File::Size()
{
	Seek(0, END);

	size_t Sz = Tell();

	Seek(0, BEG);

	return Sz;
}

int File::Tell()
{
	return mData->File.tellg();
}

void File::Seek(IN int Offset, IN int SeekBase)
{
	switch(SeekBase)
	{
	case SET:
		mData->File.seekg(Offset);
		break;
	case BEG:
		mData->File.seekg(Offset, std::ios::beg);
		break;
	case END:
		mData->File.seekg(Offset, std::ios::end);
		break;
	case CUR:
		mData->File.seekg(Offset, std::ios::cur);
		break;
	default:
		break;
	}
}

bool File::IsEOF()
{
	return mData->File.eof();
}