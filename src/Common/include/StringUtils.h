#pragma once

#include "Basic.h"
#include <string>

char* Strdup(const char* Str);
char* Strdnup(const char* Str, size_t MaxCount);

void ConvertSlash(char* String);

// returns number of tokens in the path
int TokenCount(const char* Path);

// returns token specified by Token from Path
char* PathToken(const char* Path, int Token);

char* SplitPathFromFileName(const char* FileName);
char* SplitFileNameFromPath(const char* Path);
char* SplitExtension(const char* Path);

std::string Format(const char* String, ...);