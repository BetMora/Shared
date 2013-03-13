#pragma once

class FileSystem
{
public:

    // creates directory tree from specified path
    void    CreateDirectoryTreeFromPath(const char* Path);

    // checks if file or directory exist
    bool    IsExist(const char* Path);

    void    RemoveFile(const char* Name);
    void    RenameFile(const char* SrcName, const char* DstName);
    void    CopyFile(const char* SrcPath, const char* DstPath);
    void    MoveFile(const char* SrcPath, const char* DstPath);

	char*   HomeDirectory();

	void    CreateDirectory(const char* Path);
	void    RemoveDirectory(const char* Path);
};