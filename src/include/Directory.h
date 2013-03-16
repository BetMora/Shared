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

	std::vector<std::string>	Files();
	std::vector<std::string>	Directories();

	char*						FindFile(const char* Name);
	char*						FindDirectory(const char* Name);
private:
	DirectoryData*	mData;
};