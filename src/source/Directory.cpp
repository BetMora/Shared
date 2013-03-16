#include "Directory.h"
#include "Config.h"
#include "StringUtils.h"

#ifdef WINDOWS
#include <Windows.h>
#include "dirent\dirent.h"
#else
#include <dirent.h>
#endif

#include <cstring>
#include <vector>
#include <string>
#include <map>

struct DirectoryData
{
	bool							IsOpened;
	
	std::string						RootPath;

	std::vector<std::string>		Files;
	std::vector<std::string>		FilesRelative;
	std::map<std::string, bool>		CachedFiles;
	std::vector<std::string>		Directories;
	std::vector<std::string>		DirectoriesRelative;
	std::map<std::string, bool>		CachedDirectories;

	DirectoryData()
	{
		IsOpened = false;
	}

	~DirectoryData()
	{
		IsOpened = false;
	}
};

char* AppendEntry(const char* RootPath, const char* DirEntry)
{
	size_t		NameSZ		= 0;
	size_t		DirEntrySZ	= 0;
	size_t		TmpSZ		= 0;
	char*		Tmp			= 0;
	char*		TmpPTR		= 0;
	bool		Slash		= false;

	NameSZ		= strlen(RootPath);
	DirEntrySZ	= strlen(DirEntry);
	// 2 characters to store separator and null terminating character
	TmpSZ		= NameSZ + DirEntrySZ + 2;

	Tmp = new char[TmpSZ];
	memset(Tmp, 0, TmpSZ);

	strcpy(Tmp, RootPath);

// 	TmpPTR = Strdup(Tmp);
// 
// 	while(*TmpPTR)
// 	{
// 		if(*TmpPTR == '\\' || *TmpPTR == '/')
// 		{
// 			Slash = true;
// 			break;
// 		}
// 
// 		TmpPTR++;
// 	}
// 
// 	if(Slash == false)
// 	{
   		Tmp[strlen(RootPath)] = '\\';
// 		NameSZ += 1; /* so we put file directory entry after slash
// 					  * as if we add slash manually pointer is set exact to this slash
// 					  * if slash has been set before, pointer is set to the character after the slash
// 					  */
// 	}

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

	if(mData->RootPath.empty())
		mData->RootPath = Name;

	dirent* DirEntry;

	if(Dir == 0)
		return;

	std::string Buffer = "";

	mData->IsOpened = true;

	while((DirEntry = readdir(Dir)) != 0)
	{
		if((strcmp(DirEntry->d_name, ".") != 0)	 &&	 (strcmp(DirEntry->d_name, "..") != 0)) 
		{
			int TokCount = TokenCount(Name);
			int RootTokCount = TokenCount(mData->RootPath.c_str());

													/* make sure we put last token aswell. little hack for loop, not for tokenization function itself */
			for(int n = RootTokCount; n < TokCount + 1; n++)
			{
				Buffer.append(PathToken(Name, n));
				Buffer.append("\\");
			}

			switch(DirEntry->d_type)
			{
			case DT_REG:
				mData->Files.push_back(AppendEntry(Name, DirEntry->d_name));
				mData->FilesRelative.push_back(AppendEntry(Buffer.c_str(), DirEntry->d_name));
				break;
			case DT_DIR:
				mData->Directories.push_back(AppendEntry(Name, DirEntry->d_name));
				mData->DirectoriesRelative.push_back(AppendEntry(Buffer.c_str(), DirEntry->d_name));
				Open(AppendEntry(Name, DirEntry->d_name));
				break;
			default:
				break;
			}

			Buffer.clear();
		}
	}

	closedir(Dir);
}

void Directory::Close()
{
	delete mData;
}

bool Directory::IsOpened()
{
	return mData->IsOpened;
}

size_t	Directory::FilesNum()
{
	return mData->Files.size();
}
size_t	Directory::DirectoriesNum()
{
	return mData->Directories.size();
}

std::vector<std::string> Directory::Files()
{
	return mData->Files;
}

std::vector<std::string> Directory::Directories()
{
	return mData->Directories;
}

char* Directory::FindFile(const char* Name)
{
	if(mData->IsOpened)
	{
		if(mData->Files.size() != 0)
		{
			for(size_t i = 0; i < mData->Files.size(); i++)
			{
				if(mData->Files[i].find(Name) != std::string::npos)
				{ 
					if(!mData->CachedFiles.empty())
					{
						if(mData->CachedFiles[mData->Files[i]] == false)
						{ 
							mData->CachedFiles[mData->Files[i]] = true;
							return (char*)mData->Files[i].c_str();
						}
					}
					else
					{
						mData->CachedFiles[mData->Files[i]] = true;
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
	if(mData->IsOpened)
	{
		if(mData->Directories.size() != 0)
		{
			for(size_t i = 0; i < mData->Directories.size(); i++)
			{
				if(mData->Directories[i].find(Name) != std::string::npos)
				{ 
					if(!mData->CachedDirectories.empty())
					{
						if(mData->CachedDirectories[mData->Directories[i]] == false)
						{ 
							mData->CachedDirectories[mData->Directories[i]] = true;
							return (char*)mData->Directories[i].c_str();
						}
					}
					else
					{
						mData->CachedDirectories[mData->Directories[i]] = true;
						return (char*)mData->Directories[i].c_str();
					}
				}
			}
		}
	}

	return 0;
}