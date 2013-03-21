#pragma once

#include <string>

class Log
{
public:
	enum
	{
		Info,
		Warning,
		Error,
		Fatal
	};

	static void			FileName(std::string Name);
	static std::string	FileName();

	static void			Output(std::string Message, int LogLevel = Info);
private:
	static std::string	mFileName;
	static bool			mInitialised;
};

std::string ComposeError(std::string ErrorMessage, const char* Function, const char* File, int Line);

#define Error(ErrorMessage) ComposeError(ErrorMessage, __FUNCTION__, __FILE__, __LINE__)