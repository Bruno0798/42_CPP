#include <iostream>
#include "RPN.hpp"


bool checkSymbols(char **argv)
{
	size_t digitCount = 0;
	size_t symbolCount = 0;

	for(int i =0; argv[1][i] != '\0'; ++i)
	{
		if(!(std::isdigit(argv[1][i]) || !(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '-' && argv[1][i] != '+' && argv[1][i] != '*' && argv[1][i] != '/')))
		{
			std::cout << "Error" << std::endl;
			return false;
		}
		if(std::isdigit(argv[1][i]))
			digitCount++;
		else if(argv[1][i] != ' ')
			symbolCount++;
	}
	if(symbolCount != (digitCount - 1))
	{
//		std::cout << "Digit: " << digitCount << std::endl << "Symbols: " << symbolCount << std::endl;
		std::cout << "Error" << std::endl;
		return false;
	}
	return true;
}

std::string charPtrToString(char **argv)
{
	std::string result;
	for (int i = 0; argv[1][i] != '\0'; ++i)
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
			continue;
		result += argv[1][i];
	}
	return result;
}

int main(int argc, char **argv)
{
	RPN rpn;
    if(argc != 2)
		return std::cout << "Invalid number of arguments", 1;
	try
	{
		if (checkSymbols(argv))
			rpn.polish(charPtrToString(argv));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    return 0;
}
