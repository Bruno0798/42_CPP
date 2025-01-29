#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
public:
	static void converter(std::string value);
};

#endif