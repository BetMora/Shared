#pragma once

class FileSystem
{
public:
	void RemoveFile(const char* Name);
	void CopyFile(const char* SrcPath, const char* DstPath);
	void MoveFile(const char* SrcPath, const char* DstPath);
	void RenameFile(const char* SrcName, const char* DstName);

	char* HomeDirectory();

	void Mkdir(const char* Path);
	void Rmdir(const char* Path);
};

// todo
// create directory tree from path string
// \Root\Sub1\Sub2
// Will result creating tree like this:
// Root
// Root\Sub1
// Root\Sub1\Sub2