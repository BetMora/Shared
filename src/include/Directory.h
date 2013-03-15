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

	size_t	FilesNum();
	size_t	DirectoriesNum();

	char*	FindFile(const char* Name);
	char*	FindDirectory(const char* Name);
private:
	DirectoryData*	mData;
};