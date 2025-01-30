#include <iostream>
#include <string>
#include "iter.hpp"

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

void printInt(int x)
{
	std::cout << x << " ";
}

void incrementInt(int &x)
{
	++x;
}

void printChar(char c)
{
	std::cout << c << " ";
}

void toUpperCase(char &c)
{
	c = std::toupper(c);
}

void printFloat(float x)
{
	std::cout << x << " ";
}

void multiplyByTwo(float &x)
{
	x *= 2;
}

void printString(const std::string &s)
{
	std::cout << s << " ";
}

void appendExclamation(std::string &s)
{
	s += "!";
}

int main() {
	{
		std::cout << cyan <<  "\n►►►►►►  Testing iter with int array  ◄◄◄◄◄◄" << reset << std::endl;
		int intArray[] = {1, 2, 3, 4, 5};
		size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

		std::cout << "Original int array: ";
		iter(intArray, intLength, printInt);
		std::cout << std::endl;

		iter(intArray, intLength, incrementInt);

		std::cout << "Incremented int array: ";
		iter(intArray, intLength, printInt);
		std::cout << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  Testing iter with char array  ◄◄◄◄◄◄" << reset << std::endl;
		char charArray[] = "hello";
		size_t charLength = sizeof(charArray) / sizeof(charArray[0]) - 1;

		std::cout << "Original char array: ";
		iter(charArray, charLength, printChar);
		std::cout << std::endl;

		iter(charArray, charLength, toUpperCase);

		std::cout << "Uppercase char array: ";
		iter(charArray, charLength, printChar);
		std::cout << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  Testing iter with float array  ◄◄◄◄◄◄" << reset << std::endl;
		float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		size_t floatLength = sizeof(floatArray) / sizeof(floatArray[0]);

		std::cout << "Original float array: ";
		iter(floatArray, floatLength, printFloat);
		std::cout << std::endl;

		iter(floatArray, floatLength, multiplyByTwo);

		std::cout << "Multiplied float array: ";
		iter(floatArray, floatLength, printFloat);
		std::cout << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  Testing iter with string array  ◄◄◄◄◄◄" << reset << std::endl;
		std::string stringArray[] = {"hello", "world", "test"};
		size_t stringLength = sizeof(stringArray) / sizeof(stringArray[0]);

		std::cout << "Original string array: ";
		iter(stringArray, stringLength, printString);
		std::cout << std::endl;

		iter(stringArray, stringLength, appendExclamation);

		std::cout << "Modified string array: ";
		iter(stringArray, stringLength, printString);
		std::cout << std::endl;
	}

	return 0;
}