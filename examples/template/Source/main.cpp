#include "System.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ParseArguments(int argc, char** argv)
{
	OptionsList	ProgramOptions;
	OptionsMap	ParsedResult;

	ProgramOptions.AddOption(Option("help|h", "Show help message"));
	ProgramOptions.AddOption(Option("input|i", "Input file name"));
	ProgramOptions.AddOption(Option("output|o", "Output file name"));

	if(argc < 2)
	{
		int Tokens = Tokenizer::Tokenize<'\\'>(argv[0]);

		cout << "Usage syntax: " << Tokenizer::GetToken(Tokens - 1) << " [command]\nAvailable commands:\n";

		for(OptionsList::iterator it2 = ProgramOptions.begin(); it2 != ProgramOptions.end(); ++it2)
		{
			Tokenizer::Tokenize<'|'>(it2->Name.c_str());

			std::string Full	= "--" + Tokenizer::GetToken(0);
			std::string Short	= "--" + Tokenizer::GetToken(1);

			cout << setw(10) << Full << setw(10) << "[" << Short << "]" << setw(20) << it2->Description << endl;
		}
	}

	ParsedResult = OptionsParser::Parse(ProgramOptions, argv, argc);

	if(OptionsParser::Check("help|h"))
	{
		int Tokens = Tokenizer::Tokenize<'\\'>(argv[0]);

		cout << "Usage syntax: " << Tokenizer::GetToken(Tokens - 1) << " [command]\nAvailable commands:\n";

		for(OptionsList::iterator it2 = ProgramOptions.begin(); it2 != ProgramOptions.end(); ++it2)
		{
			Tokenizer::Tokenize<'|'>(it2->Name.c_str());

			std::string Full	= "--" + Tokenizer::GetToken(0);
			std::string Short	= "--" + Tokenizer::GetToken(1);
			
			cout << setw(15) << Full << setw(10) << "[" << Short << "]" << setw(20) << it2->Description << endl;
 		}
	}
}

int main(int argc, char** argv)
{	
	ParseArguments(argc, argv);

	getchar();
}