#include "FileSystem.h"
#include "Config.h"
#include "StringUtils.h"
#include "File.h"

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
	File Input,
		 Output;

	Input.Open(SrcPath);
	Output.Open(DstPath);

	size_t Size = Input.Size();

	char* Buffer = new char[Size];

	Buffer = Input.ReadRaw(Size);

	// Output.WriteRaw(Buffer);

	Input.Close();
	Output.Close();
}

void FileSystem::MoveFile(const char* SrcPath, const char* DstPath)
{
	CopyFile(SrcPath, DstPath);

	RemoveFile(SrcPath);
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
	_mkdir(Path);
}

void FileSystem::Rmdir(const char* Path)
{
	_rmdir(Path);
}