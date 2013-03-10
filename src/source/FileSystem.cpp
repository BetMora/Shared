#include "FileSystem.h"
#include "Config.h"
#include "StringUtils.h"

#include <direct.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void FileSystem::RemoveFile(const char* Name)
{
	remove(Name);
}

void FileSystem::CopyFile(const char* SrcPath, const char* DstPath)
{
	//copy(SrcPath, DstPath);
}

void FileSystem::MoveFile(const char* SrcPath, const char* DstPath)
{
	//move(SrcPath, DstPath);
}

void FileSystem::RenameFile(const char* SrcName, const char* DstName)
{
	rename(SrcName, DstName);
}

char* FileSystem::HomeDirectory()
{
	static char Buffer[1024];

#ifdef WINDOWS
	strcpy(Buffer, getenv("USERPROFILE"));
#else
	strcpy(Buffer, getenv("HOME"));
#endif

	Buffer[sizeof(Buffer) - 1] = '\0';

	return Buffer;
}

void FileSystem::Mkdir(const char* Path)
{
//#ifdef WINDOWS
	mkdir(Path);
// #elif defined LINUX
// 	mkdir(Path, 0755);
// #endif
}

void FileSystem::Rmdir(const char* Path)
{
	rmdir(Path);
}