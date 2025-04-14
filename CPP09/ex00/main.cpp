#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include "BitcoinExchange.hpp"

void checkArguments(int argc)
{
	if(argc != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		std::exit(1);
	}
}

void splitLine(const std::string &line,char delimiter, std::map<std::string, float> &dataBase)
{
	std::stringstream ss(line);
	std::string key;
	std::string value;

	if (std::getline(ss, key, delimiter) && std::getline(ss, value))
	{
		std::istringstream valueStream(value);
		float intValue;
		if (valueStream >> intValue)
			dataBase[key] = intValue;
	}
	else
		std::cerr << "Error: malformed line: " << line << std::endl;
}

std::map<std::string, float> readDataBase()
{
	std::string file_name = "data.csv";
	std::ifstream file(file_name.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		std::exit(1);
	}

	std::string line;
	std::map<std::string, float> dataBase;
	while(std::getline(file, line))
		splitLine(line,',', dataBase);
	return dataBase;
}
std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	size_t last = str.find_last_not_of(" \t\n\r");
	if (first == std::string::npos || last == std::string::npos)
		return "";
	return str.substr(first, last - first + 1);
}


void printDataBase(std::map<std::string, int> dataBase)
{
	for (std::map<std::string, int>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it)
		std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
}

bool isDataValid(BitcoinExchange &bitcoin, std::string date)
{
	size_t firstDash = date.find('-');
	size_t secondDash = date.find('-', firstDash + 1);
	if(firstDash == std::string::npos || secondDash == std::string::npos)
		return false;
	bitcoin.setYear(std::atoi(date.substr(0, firstDash).c_str()));
	bitcoin.setMonth(std::atoi(date.substr(firstDash + 1, secondDash - firstDash - 1).c_str()));
	bitcoin.setDay(date.substr(secondDash + 1).c_str());

	return true;
}

void checkLine(BitcoinExchange &bitcoin, const std::string& line)
{
	try
	{
		std::stringstream ss(line);
		std::string date;
		std::string value;

		if (std::getline(ss, date, '|') && std::getline(ss, value))
		{
			date = trim(date);
			value = trim(value);
			if (date.empty() || value.empty())
			{
				std::cout << "Error: bad input => " << line << std::endl;
				return;
			}
			if (!isDataValid(bitcoin, date))
			{
				std::cout << "Error: invalid date => " << date << std::endl;
				return;
			}
			char* end;
			double amount = std::strtod(value.c_str(), &end);
			if (*end != '\0')
			{
				std::cout << "Error: invalid value => " << value << std::endl;
				return;
			}
			bitcoin.setValue(amount);
			bitcoin.exchange();
		}
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}


std::ifstream* openFile(char **argv)
{
	std::ifstream* file = new std::ifstream(argv[1]);
	if (!file->is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		std::exit(1);
	}
	return file;
}

void exchange(const std::map<std::string, float>&dataBase, std::string line)
{
	(void) dataBase;
	(void ) line;
	std::cout << "Correct Date " << std::endl;
}

void readLine(BitcoinExchange &bitcoin, std::ifstream *file)
{
	std::string line;
	std::getline(*file, line);
	while (std::getline(*file, line))
		checkLine(bitcoin, line);
}

int main(int argc, char **argv)
{
	checkArguments(argc);
	std::ifstream* file = openFile(argv);
	BitcoinExchange bitcoin(readDataBase());
	readLine(bitcoin, file);

	delete file;
    return 0;
}
