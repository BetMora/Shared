#include "Directory.h"
#include "Config.h"

#ifdef WINDOWS
#include <Windows.h>
#include "dirent\dirent.h"
#else
#include <dirent.h>
#endif

#include <cstring>
#include <vector>
#include <string>

struct DirectoryData
{
	bool							IsOpened;
	size_t							FilesNum;
	size_t							DirectoriesNum;

	std::vector<std::string>		Files;
	std::vector<std::string>		Directories;

	DirectoryData()
	{
		IsOpened = false;
		FilesNum = 0;
		DirectoriesNum = 0;
	}

	~DirectoryData()
	{
		IsOpened = false;
		FilesNum = 0;
		DirectoriesNum = 0;
	}
};

char* AppendEntry(const char* RootPath, const char* DirEntry)
{
	size_t		NameSZ		= 0;
	size_t		DirEntrySZ	= 0;
	size_t		TmpSZ		= 0;
	char*		Tmp			= 0;

	NameSZ				= strlen(RootPath);
	DirEntrySZ			= strlen(DirEntry);
	// 2 characters to store separator and null terminating character
	TmpSZ				= NameSZ + DirEntrySZ + 2;

	Tmp = new char[TmpSZ];
	memset(Tmp, 0, TmpSZ);

	strcpy(Tmp, RootPath);

	Tmp[strlen(RootPath)] = '\\';

	for(size_t i = NameSZ + 1, n = 0; i < TmpSZ, n < DirEntrySZ; i++, n++)
	{
		Tmp[i] = DirEntry[n];
	}

	Tmp[TmpSZ - 1] = '\0';

	return Tmp;
}

Directory::Directory()
{
	mData = new DirectoryData();
}

Directory::~Directory()
{
	if(mData->IsOpened)
		Close();
}

void Directory::Open(const char* Name)
{
	DIR* Dir = opendir(Name);
	dirent* DirEntry;

	if(Dir == 0)
		return;

	mData->IsOpened = true;

	int		NameSZ		= 0;
	int		DirEntrySZ	= 0;
	int		TmpSZ		= 0;
	char*	Tmp			= 0;

	while((DirEntry = readdir(Dir)) != 0)
	{
		if((strcmp(DirEntry->d_name, ".") != 0)  &&  (strcmp(DirEntry->d_name, "..") != 0)) 
		{
			switch(DirEntry->d_type)
			{
			case DT_REG:
				mData->Files.push_back(AppendEntry(Name, DirEntry->d_name));
				mData->FilesNum++;
				break;
			case DT_DIR:
				mData->Directories.push_back(AppendEntry(Name, DirEntry->d_name));
				mData->DirectoriesNum++;
				Open(AppendEntry(Name, DirEntry->d_name));
				break;
			default:
				break;
			}
		}
	}

	closedir(Dir);
}

void Directory::Close()
{
	mData->Files.clear();
	delete mData;
}

bool Directory::IsOpened()
{
	return mData->IsOpened;
}

size_t  Directory::FilesNum()
{
	return mData->FilesNum;
}
size_t  Directory::DirectoriesNum()
{
	return mData->DirectoriesNum;
}

char* Directory::FindFile(const char* Name)
{
	if(mData->FilesNum != 0)
		for(size_t i = 0; i < mData->FilesNum; i++)
			// if any of stored files contains Name in the path
			if(mData->Files[i].find(Name) != std::string::npos)
				return (char*)mData->Files[i].c_str();

	return "";
}

char* Directory::FindDirectory(const char* Name)
{
	if(mData->DirectoriesNum != 0)
		for(size_t i = 0; i < mData->DirectoriesNum; i++)
			// if any of stored files contains Name in the path
			if(mData->Directories[i].find(Name) != std::string::npos)
				return (char*)mData->Directories[i].c_str();

	return "";
}