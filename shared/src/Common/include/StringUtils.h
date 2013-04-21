#pragma once

#include "Config.h"

#include "Types.h"
#include "Defines.h"

char* Strdup(IN const char* Str);
char* Strndup(IN const char* Str, IN size_t MaxCount);

// assumes that path has no mixed slashes
void ConvertSlash(INOUT char* String);

int GetTokensCount(IN const char* Path);
char* GetToken(IN const char* Path, int Token);

char* GetPath(IN const char* FileName);
char* GetFileName(IN const char* Path);
char* GetExtension(IN const char* Path);

std::string MakePathRelative(IN const char* RootPath, IN const char* FileName);

std::string Format(IN const char* String, ...);