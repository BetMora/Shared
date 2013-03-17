#pragma once

#include <string>

enum // message level
{
	Info,
	Warning,
	Error,
	Fatal
};

class Log
{
public:
	static void		FileName(const char* Name);
	static char*	FileName();
	static void		Output(const char* Message, int LogLevel = Info);
private:
	static std::string mFileName;
};