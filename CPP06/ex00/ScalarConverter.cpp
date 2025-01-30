#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "ScalarConverter Copy Constructor Called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor Called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "ScalarConverter Assignment Operator Called" << std::endl;
	(void)other;
	return *this;
}

int ScalarConverter::checkType(std::string value)
{
	if(!(value[1] == '+' || value[1] == '-'))
	{
		if (checkChar(value))
			return 1;
		else if (checkInt(value))
			return 2;
		else if(checkFloat(value))
			return 3;
		if(checkDouble(value))
		return 4;
	}
	return 0;
}

void ScalarConverter::converter(std::string value)
{
	std::cout << std::fixed << std::setprecision(1);
	switch (checkType(value))
	{
		case 1:
			printChar(value); break;
		case 2:
			printInt(value); break;
		case 3:
			printFloat(value); break;
		case 4:
			printDouble(value); break;
		default: 	std::cout << "Syntax Error" << std::endl;
	}

}
bool ScalarConverter::checkChar(std::string value)
{
	return value.length() == 1 && !std::isdigit(value[0]);
}

bool ScalarConverter::checkInt(std::string value)
{
	for (size_t i = 0; i < value.length(); ++i)
	{
		if(!(std::isdigit(value[i])))
			return false;
	}
	return true;
}

bool ScalarConverter::checkFloat(std::string value)
{
	if (value == "nanf" || value == "+inff" || value == "-inff")
		return true;

	char* end;
	std::strtof(value.c_str(), &end);
	return *end == '\0' || *end == 'f';
}

bool ScalarConverter::checkDouble(std::string value)
{
	if (value == "nan" || value == "+inf" || value == "-inf")
		return true;

	char* end;
	std::strtod(value.c_str(), &end);
	return *end == '\0';
}

void ScalarConverter::printChar(std::string value)
{
	std::cout << "char: " << value << std::endl
			  << "int: " << static_cast<int>(value[0]) << std::endl
			  << "float: " << static_cast<float >(value[0]) << "f" << std::endl
			  << "double: " << static_cast<float >(value[0]) << std::endl;
}

void ScalarConverter::printInt(std::string value)
{

	long intValue = std::strtol(value.c_str(), NULL, 10);

	if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max() && isprint(static_cast<char>(intValue)))
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max())
	    std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << static_cast<float>(intValue) << "f" << std::endl
			  << "double: " << static_cast<double>(intValue) << std::endl;

}

void ScalarConverter::printFloat(std::string value)
{
	float floatValue = strtof(value.c_str(), NULL);

	if (value == "+inff" || value == "-inff")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: " << value << std::endl
				  << "double: " << (value[0] == '+' ? "+inf" : "-inf") << std::endl;
	} else if (value == "nan")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: nanf" << std::endl
				  << "double: nan" << std::endl;
	} else
	{
		std::cout << "char: " << (floatValue >= 0 && floatValue <= 127 && isprint(floatValue) ? "'" + std::string(1, static_cast<char>(floatValue)) + "'" : "Non displayable") << std::endl;
		if (floatValue < std::numeric_limits<int>::min() || floatValue > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(floatValue) << std::endl;

		std::cout << "float: " << floatValue << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
	}
}

void ScalarConverter::printDouble(std::string value)
{
	double doubleValue = std::strtod(value.c_str(), NULL);

	if (value == "+inf" || value == "-inf") {
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: " << (value[0] == '+' ? "+inff" : "-inff") << std::endl
				  << "double: " << value << std::endl;
	} else if (value == "nan") {
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: nanf" << std::endl
				  << "double: nan" << std::endl;
	} else {
		std::cout << "char: " << (doubleValue >= 0 && doubleValue <= 127 && isprint(doubleValue) ? "'" + std::string(1, static_cast<char>(doubleValue)) + "'" : "Non displayable") << std::endl;
		if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;

		std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
		std::cout << "double: " << doubleValue << std::endl;
	}
}

