#pragma once

char* Strdup(char* Str);

// converts one OS slash to another OS slash
// for example UNIX(/) to Windows(\\) and vice versa
char* ConvertSlash(const char* Str);
void ConvertSlash(const char* Src, char* Dst);