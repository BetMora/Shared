#include "Log.h"

#include <ctime>
#include <sstream>
#include <fstream>

static const char* InfoMessage		= "[INFO] ";
static const char* WarningMessage	= "[WARNING] ";
static const char* ErrorMessage		= "[ERROR] ";
static const char* FatalMessage		= "[FATAL] ";
static const char* TimeFormat		= "[%X]"; // 23:59:59

std::string Log::mFileName = "Output.log";

void Log::FileName(const char* Name)
{
	mFileName = Name;
}

char* Log::FileName()
{
	return (char*)mFileName.c_str();
}

void Log::Output(const char* Message, int LogLevel /* = Info */)
{
	std::fstream		File(mFileName, std::ios::app|std::ios::out);
	std::stringstream	Buffer;

	time_t	RawTime;
	tm*		TimeInfo;
	char	Temp[128];

	time(&RawTime);
	TimeInfo = localtime(&RawTime);

	strftime(Temp, 128, TimeFormat, TimeInfo);

	Buffer << Temp;

	switch(LogLevel)
	{
	case Info:
		Buffer << InfoMessage;
		break;
	case Warning:
		Buffer << WarningMessage;
		break;
	case Error:
		Buffer << ErrorMessage;
		break;
	case Fatal:
		Buffer << FatalMessage;
		break;
	}

	Buffer << Message << "\n";

	File << Buffer.str();

	File.close();
}