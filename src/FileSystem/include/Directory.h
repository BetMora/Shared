#pragma once

#include "Basic.h"
#include "Defines.h"

#include <vector>
#include <string>

struct DirectoryData;

class Directory
{
public:
	Directory();
	~Directory();

	void						Open(IN const char* Name);
	void						Close();

	bool						IsOpened();

	size_t						FilesNum();
	size_t						DirectoriesNum();

	char*						RootDirectory();

	std::vector<std::string>	Files(IN bool Relative = false);
	std::vector<std::string>	Directories(IN bool Relative = false);

	char*						FindFile(IN const char* Name);
	char*						FindDirectory(IN const char* Name);
private:
	DirectoryData*	mData;
};