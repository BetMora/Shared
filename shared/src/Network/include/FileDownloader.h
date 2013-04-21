#pragma once

#include "Config.h"

#include "Types.h"
#include "Defines.h"

class FileDownloader
{
public:
	FileDownloader();
	~FileDownloader();

	bool Download(IN const char* URL, IN const char* OutputFileName);
};