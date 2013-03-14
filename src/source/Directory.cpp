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
    bool                            IsOpened;
    size_t                          FilesNum;
    size_t                          CachedFilesNum;
    size_t                          DirectoriesNum;
    size_t                          CachedDirectoriesNum;

    std::vector<std::string>        Files;
    std::vector<std::string>        CachedFiles;
    std::vector<std::string>        Directories;
    std::vector<std::string>        CachedDirectories;

	DirectoryData()
	{
		IsOpened                = false;
		FilesNum                = 0;
        CachedFilesNum          = 0;
		DirectoriesNum          = 0;
        CachedDirectoriesNum    = 0;
	}

	~DirectoryData()
	{
		IsOpened                = false;
		FilesNum                = 0;
        CachedFilesNum          = 0;
		DirectoriesNum          = 0;
        CachedDirectoriesNum    = 0;
	}
};

char* AppendEntry(const char* RootPath, const char* DirEntry)
{
	size_t      NameSZ      = 0;
	size_t      DirEntrySZ  = 0;
	size_t      TmpSZ       = 0;
	char*       Tmp         = 0;

	NameSZ              = strlen(RootPath);
	DirEntrySZ          = strlen(DirEntry);
	// 2 characters to store separator and null terminating character
	TmpSZ               = NameSZ + DirEntrySZ + 2;

	Tmp = new char[TmpSZ];
	memset(Tmp, 0, TmpSZ);

	strcpy(Tmp, RootPath);

	Tmp[strlen(RootPath)] = '\\';

	for(size_t i = NameSZ + 1 /* so we put file name after directory entry */, n = 0; i < TmpSZ, n < DirEntrySZ; i++, n++)
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
    if(mData->IsOpened)
    {
	    if(mData->FilesNum != 0)
        {
		    for(size_t i = 0; i < mData->FilesNum; i++)
            {
			    // check if any of stored files matches the provided pattern
			    if(mData->Files[i].find(Name) != std::string::npos)
                { 
                    if(mData->CachedFiles.size() != 0) // if we have cached files already
                    {
                        // for every cached file
                        for(size_t n = 0; n < mData->CachedFilesNum; n++)
                        {
                            if(mData->CachedFiles[n].length() != 0)
                            {
                                // checking if we have not cached("found before") this file already
                                if(mData->CachedFiles[n].find(mData->Files[i]) == std::string::npos)
                                { // no, we didn't
                                    // so we cache and return it this one
                                    mData->CachedFiles.push_back(mData->Files[i]);
                                    mData->CachedFilesNum++;
                                    return (char*)mData->Files[i].c_str();
                                }
                            }
                        }
                    }
                    else // we have no cached files yet
                    {
                        // so we cache and return it this one
                        mData->CachedFiles.push_back(mData->Files[i]);
                        mData->CachedFilesNum++;
                        return (char*)mData->Files[i].c_str();
                    }
                }
            }
        }
    }

	return 0;
}

char* Directory::FindDirectory(const char* Name)
{

	return 0;
}