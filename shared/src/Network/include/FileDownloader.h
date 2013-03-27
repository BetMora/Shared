#pragma once

#include "Config.h"

#include "Types.h"
#include "Defines.h"

class File;

class FileDownloader
{
public:
	FileDownloader();
	~FileDownloader();

	bool Download(const char* URL, const char* OutputFileName);
private:
	File* mOutputFile;
};