#include "FileSystem.h"
#include "Config.h"
#include "StringUtils.h"
#include "File.h"

#include <direct.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <sys/types.h>
#include <sys/stat.h>

bool FileSystem::IsExist(const char* Path)
{
	/*	   struct stat fileinfo;

		   return !stat(filename, &fileinfo);
	 **/
	struct stat St;
	stat(Path, &St);

	if( (((St.st_mode) & S_IFMT) == S_IFDIR) || 
		(((St.st_mode) & S_IFMT) == S_IFREG) ) 
		return true;

	return false;
}

void FileSystem::RemoveFile(const char* Name)
{
	remove(Name);
}

void FileSystem::RenameFile(const char* SrcName, const char* DstName)
{
	rename(SrcName, DstName);
}

void FileSystem::CopyFile(const char* SrcPath, const char* DstPath)
{
	if(!IsExist(SrcPath))
		return;

	File Input,
		 Output;

	Input.Open(SrcPath);
	Output.Open(DstPath);

	size_t Size = Input.Size();

	char* Buffer = new char[Size];
	memset(Buffer, 0, sizeof(*Buffer) * Size);

	Buffer = Input.ReadRaw(Size);

	Output.WriteRaw(Buffer, sizeof(*Buffer) * Size);

	delete Buffer;

	Input.Close();
	Output.Close();
}

void FileSystem::MoveFile(const char* SrcPath, const char* DstPath)
{
	if(!IsExist(SrcPath) || IsExist(DstPath))
		return;

	CopyFile(SrcPath, DstPath);

	RemoveFile(SrcPath);
}

char* FileSystem::HomeDirectory()
{
	static char Buffer[1024];

#ifdef WINDOWS
	strcpy(Buffer, getenv("USERPROFILE"));
#elif LINUX
	strcpy(Buffer, getenv("HOME"));
#endif

	Buffer[sizeof(Buffer) - 1] = '\0';

	return Buffer;
}

char* FileSystem::WorkingDirectory()
{
	static char Buffer[1024];
#ifdef WINDOWS
	getcwd(Buffer, 1024);
#elif LINUX
	strcpy(Buffer, getenv("PWD"));
#endif

	Buffer[sizeof(Buffer) - 1] = '\0';

	return Buffer;
}

void FileSystem::CreateDirectory(const char* Path)
{
	_mkdir(Path);
}

void FileSystem::RemoveDirectory(const char* Path)
{
	_rmdir(Path);
}