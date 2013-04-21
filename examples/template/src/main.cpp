#include "Shared.h"
#include <iostream>
#include <vld.h>

int main(int argc, char** argv)
{
	char* str = new char[5];
	strcpy(str, "test");

	char* strduped = Strndup(str, strlen(str));

	std::cout << "str adress: " << &str << " str value: " << str << std::endl;
	std::cout << "strduped adress: " << &strduped << " strduped value: " << strduped << std::endl;

	delete[] strduped;
	delete[] str;

	return 0;
}