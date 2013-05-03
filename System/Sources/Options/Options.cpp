#include "Options.h"

#include "Tokenization.h"

OptionsMap OptionsParser::mParsedResults = OptionsMap();

OptionsMap OptionsParser::Parse(IN OptionsList OptionsDescription, IN char** Options, IN int OptionsCount)
{	
	if(mParsedResults.size() != 0)
		mParsedResults = OptionsMap();

	OptionsMap OM;

	if(OptionsCount == 0)
		return OM;

	std::map<std::string, std::vector<std::string> > KeyPairs;

	for(OptionsList::iterator it = OptionsDescription.begin(); it != OptionsDescription.end(); ++it)
	{
		Tokenizer::Tokenize<'|'>(it->Name.c_str());

		std::string Full = "--" + Tokenizer::GetToken(0);
		std::string Short = "--" + Tokenizer::GetToken(1);

		KeyPairs[it->Name].push_back(Full);
		KeyPairs[it->Name].push_back(Short);
	}

	for(size_t i = 0; i < OptionsCount; i++)
	{
		for(OptionsList::iterator it = OptionsDescription.begin(); it != OptionsDescription.end(); ++it)
		{
			if(	(strcmp(Options[i], KeyPairs[it->Name][0].c_str()) == 0)  // --arg
				||
				(strcmp(Options[i], KeyPairs[it->Name][1].c_str()) == 0)) // --a
			{
				OM[std::string(Options[i])] = Value(Options[i + 1]);
			}
		}
	}

	mParsedResults = OM;

	return OM;
}

bool OptionsParser::Check(IN const char* Name)
{
	if(mParsedResults.size() == 0)
	{
		throw std::string("OptionsParser::Check throwed an exception.\nParsed results arrays is empty.");
	}

	for(OptionsMap::iterator it = mParsedResults.begin(); it != mParsedResults.end(); ++it)
	{
		Tokenizer::Tokenize<'|'>(it->first.c_str());

		std::string Full	= "--" + Tokenizer::GetToken(0);
		std::string Short	= "--" + Tokenizer::GetToken(1);

		if( (strcmp(it->first.c_str(), Full.c_str()))
			|| 
			(strcmp(it->first.c_str(), Short.c_str()))
			== 0)
		{
			return true;
		}
	}

	return false;
}