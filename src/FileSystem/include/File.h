#pragma once

#include "Basic.h"
#include "Types.h"
#include "Defines.h"
#include "Config.h"

#include "Stream.h"

class File : public Stream
{
public:
	File(const char* Name = 0);
	virtual ~File();

	bool			Open(const char* Name);
	bool			Close();

	virtual void	Write(void* Data, size_t Size);
	virtual void	Read(void* Data, size_t Size);

	virtual bool	IsOpened();

	virtual char* Data();
	virtual size_t			Size();
	char*		Name();

	bool			IsEOF();
	void			Seek(int Offset, int SeekBase = SET);
	int				Tell();
private:
	struct FileData;
	FileData* mData;
};