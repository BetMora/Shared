#include "Log.h"

#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>

#include "StringUtils.h"

static const char* InfoMessage		= "INFO: ";
static const char* WarningMessage	= "WARNING: ";
static const char* ErrorMessage		= "ERROR: ";
static const char* FatalMessage		= "FATAL: ";
static const char* TimeFormat		= "[%X]"; // 23:59:59

static const char* HTMLHeader		=
	"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n \
	 <html>\n \
	 <head>\n \
	 <title>Log file</title>\n \
	 <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>\n \
	 <style type=\"text/css\">\n \
		body { background: #eee; color: #b4c8d2; margin-right: 20px; margin-left: 20px; font-size: 14px; font-family: Helvetica; }\n \
		h1 { text-align: center; color: #626569; }\n \
		h2 { color: #ffffff; }\n \
		.m, .w, .e, .f { padding: 3px; overflow: auto; }\n \
		.m { background-color: #333; color: #ffffff; }\n \
		.w { background-color: #FFF0AA; color: #626569; }\n \
		.e { background-color: #FD794B; color: #FDEDD0; }\n \
		.f { background-color: #FF4229; color: #FDEDD0; }\n \
		dl { padding: 0 0 0 10px; }\n \
		dl.section { margin-left: 0px; padding-left: 0px; }\n \
		dl.warning { margin-left: -7px; padding-left: 3px; border-left: 4px solid; border-color: #FFF0AA; }\n \
		dl.error { margin-left: -7px; padding-left: 3px; border-left: 4px solid; border-color: #FD794B; }\n \
		dl.fatal { margin-left: -7px; padding-left: 3px; border-left: 4px solid; border-color: #FF4229; }\n \
	 </style>\n \
	 </head>\n \
	 <body>\n \
	 <h1>Log file</h1>\n";

std::string Log::mFileName			= "Log.html";
bool		Log::mInitialised		= false;

std::string ConvertToHTML(const char* Str)
{
	std::string ReturnString;
	const char* Ptr = Str;

	while(*Ptr)
	{
		switch(*Ptr)
		{
		case '\t':
			ReturnString += "&nbsp; &nbsp; ";
			break;
		case '<':
			ReturnString += "&lt;";
			break;
		case '>':
			ReturnString += "&gt;";
			break;
		case '\n':
			ReturnString += "<br>";
			break;
		default:
			ReturnString += *Ptr;
			break;
		}

		Ptr++;
	}

	return ReturnString;
}

void Log::FileName(std::string Name)
{
	mFileName = Name;
}

std::string Log::FileName()
{
	return mFileName;
}

void Log::Output(std::string Message, int LogLevel /* = Info */)
{
	std::fstream		File(mFileName, std::ios::app|std::ios::out);
	std::stringstream	Buffer;

	if(!mInitialised)
	{
		Buffer << HTMLHeader;

		mInitialised = true;
	}

	time_t	RawTime;
	tm*		TimeInfo;
	char	Time[128];

	time(&RawTime);
	TimeInfo = localtime(&RawTime);

	strftime(Time, 128, TimeFormat, TimeInfo);

	switch(LogLevel)
	{
	case Info:
		Buffer << "<div class=\"m\">";
		break;
	case Warning:
		Buffer << "<div class=\"w\">";
		break;
	case Error:
		Buffer << "<div class=\"e\">";
		break;
	case Fatal:
		Buffer << "<div class=\"f\">";
		break;
	default:
		break;
	}

	Buffer << Time << " ";

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
	default:
		break;
	}

	Buffer << Message << "<br>";

	Buffer << "</div>\n";
	
	File << Buffer.str();

	File.close();
}

std::string ComposeError(std::string ErrorMessage, const char* Function, const char* File, int Line)
{
	std::stringstream Buffer;

	Buffer << ErrorMessage << "<br>";
	Buffer << "File: " << File << " " << "Function: " << Function << "() " << "Line: " << Line; 

	std::string Message(Buffer.str());

	return Message;
}