#pragma once

#include "Basic.h"
#include "Types.h"
#include "Defines.h"
#include "Config.h"

class FileSystem
{
public:
	static void		CreateDirectoryTreeFromPath(const char* Path);

	static bool		IsExist(const char* Path);

	static void		RemoveFile(const char* Name);
	static void		RenameFile(const char* SrcName, const char* DstName);
	static void		CopyFile(const char* SrcPath, const char* DstPath);
	static void		MoveFile(const char* SrcPath, const char* DstPath);

	static char*	HomeDirectory();
	static char*	WorkingDirectory();

	static void		CreateDirectory(const char* Path);
	static void		RemoveDirectory(const char* Path);
};