#include "File.h"

#include <fstream>

struct FileData
{
	std::fstream	File;
	char*			Name;
};

File::File(const char* Name)
{
	mData		= new FileData();
	mData->Name = 0;

	if(Name[0] != '\0')
		Open(Name);
}

File::~File()
{
	delete mData;
}

bool File::Open(const char* Name)
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

size_t File::Write(void* Data, size_t Size)
{
	mData->File.write((char*)Data, Size);

	return mData->File.gcount();
}

size_t File::Read(void* Data, size_t Size)
{
	mData->File.read((char*)Data, Size);

	return mData->File.gcount();
}

const char* File::Name()
{
	return mData->Name;
}

size_t File::Size()
{
	int Offset = Tell();

	Seek(0, END);

	size_t Sz = Tell();

	Seek(Offset, SET);

	return Sz;
}

bool File::IsEOF()
{
	return mData->File.eof();
}

void File::Seek(int Offset, int SeekBase)
{
	switch(SeekBase)
	{
	case SET:
		mData->File.seekg(Offset);
		break;
	case BEG:
		mData->File.seekg(Offset, std::ios::beg);
	case END:
		mData->File.seekg(Offset, std::ios::end);
		break;
	case CUR:
		mData->File.seekg(Offset, std::ios::cur);
	}
}

int File::Tell()
{
	return mData->File.tellg();
}