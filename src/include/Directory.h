#pragma once

#include "Basic.h"

#include <vector>
#include <string>

struct DirectoryData;

class Directory
{
public:
	Directory();
	~Directory();

	void						Open(const char* Name);
	void						Close();

	bool						IsOpened();

	size_t						FilesNum();
	size_t						DirectoriesNum();

	char*						RootDirectory();

	std::vector<std::string>	Files(bool Relative = false);
	std::vector<std::string>	Directories(bool Relative = false);

	char*						FindFile(const char* Name);
	char*						FindDirectory(const char* Name);
private:
	DirectoryData*	mData;
};