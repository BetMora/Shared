#pragma once

struct DirectoryData;

class Directory
{
public:
	Directory();
	~Directory();

	void	Open(const char* Name);
	void	Close();

	bool	IsOpened();

	size_t  FilesNum();
	size_t  DirectoriesNum();

	// returns full path to specified file
	char*	FindFile(const char* Name);
	char*   FindDirectory(const char* Name);
private:
	DirectoryData*	mData;
};

/* TODO
 * Add support for searching multiple files with a carriage
 * */