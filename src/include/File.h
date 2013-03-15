#pragma once

#include "Stream.h"

struct FileData;

class File : public Stream
{
public:
	File(const char* Name = 0);
	virtual ~File();

	bool			Open(const char* Name);
	bool			Close();

	virtual size_t	Write(void* Data, size_t Size);
	virtual size_t	Read(void* Data, size_t Size);

	virtual bool	IsOpened();

	const char*		Name();
	size_t			Size();

	bool			IsEOF();
	void			Seek(int Offset, int SeekBase = SET);
	int				Tell();
private:
	FileData* mData;
};