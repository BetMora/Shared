#pragma once

#include "Config.h"

#include "Types.h"
#include "Defines.h"

struct Option
{
	Option(std::string Name, std::string Description)
 	{
 		this->Name = Name;
 		this->Description = Description;
 	}

	std::string Name;
	std::string	Description;
};

class OptionsList : public std::vector<Option>
{
public:
	void AddOption(IN Option& OptionToAdd)
	{
		push_back(OptionToAdd);
	}
};

class Value
{
public:
	Value(IN char* OptionValue = 0)
	{
		this->OptionValue = OptionValue;
	}

	int AsInt()
	{
		return atoi(OptionValue);
	}

	char* AsCString()
	{
		return OptionValue;
	}
private:
	char* OptionValue;
};

typedef std::map<std::string, Value> OptionsMap;

class OptionsParser
{
public:
	static OptionsMap	Parse(IN OptionsList OptionsDescription, IN char** Options, IN int OptionsCount);
	static bool			Check(IN const char* Name);
private:
	static OptionsMap mParsedResults;
};