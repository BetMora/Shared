#pragma once

#include "Config.h"

#include "Types.h"
#include "Defines.h"

#include "Stream.h"

class File : public Stream
{
public:
	File(IN const char* Name = 0);
	virtual ~File();

	bool			Open(IN const char* Name);
	bool			Close();

	virtual void	Write(IN void* Data, IN size_t Size);
	virtual void	Read(OUT void* Data, IN size_t Size);

	virtual bool	IsOpened();

	virtual char*	Data();
	virtual size_t	Size();
	char*			Name();

	int				Tell();
	void			Seek(int Offset, int SeekBase = Set);

	bool			IsEOF();
private:
	struct FileData;
	FileData* mData;
};