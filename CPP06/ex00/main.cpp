#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **agrv)
{
	if (argc == 2)
		ScalarConverter::converter(agrv[1]);

	else
		std::cout << "Wrong nbr of args" << std::endl;

	return 0;
}