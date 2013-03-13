#pragma once

// note: deletes passed string
char* Strdup(const char* Str);
char* Strdnup(const char* Str, size_t MaxCount);

// converts one OS slash to another OS slash
// for example UNIX(/) to Windows(\\) and vice versa
void ConvertSlash(const char* Src, char* Dst);

// returns number of tokens in the path
int TokenCount(const char* Path);

// returns token specified by Token from Path
char* PathToken(const char* Path, int Token);