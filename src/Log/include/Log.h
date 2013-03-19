#pragma once

#include <string>

enum // message level
{
	Info,
	Warning,
	Error,
	Fatal
};
// add features to compose message like this: Output(Error("Blah"));
// resulting composed message: [15:15:20][ERROR] Blah Directory.cpp, line 180

class Log
{
public:
	static void		FileName(const char* Name);
	static char*	FileName();

	static void		Output(const char* Message, int LogLevel = Info);

	static void		Console(bool OutputToConSole)
	{
		mOutputToConsole = OutputToConSole;
	}
private:
	static std::string	mFileName;
	static bool			mOutputToConsole;
};