#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

	static int checkType(std::string value);
	static bool checkChar(std::string value);
	static bool checkInt(std::string value);
	static bool checkFloat(std::string value);
	static bool checkDouble(std::string value);

	static void printChar(std::string value);
	static void printInt(std::string value);
	static void printFloat(std::string value);
	static void printDouble(std::string value);
public:
	static void converter(std::string value);
};

#endif