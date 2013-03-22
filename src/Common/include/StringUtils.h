#pragma once

#include "Config.h"

#include "Types.h"
#include "Defines.h"

#include <string>

char* Strdup(IN const char* Str);
char* Strdnup(IN const char* Str, IN size_t MaxCount);

void ConvertSlash(IN char* String);

// returns number of tokens in the path
int TokenCount(IN const char* Path);

// returns token by its number
char* PathToken(IN const char* Path, int Token);

char* SplitPathFromFileName(IN const char* FileName);
char* SplitFileNameFromPath(IN const char* Path);
char* SplitExtension(IN const char* Path);

std::string Format(IN const char* String, ...);