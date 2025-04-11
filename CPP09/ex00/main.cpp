#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

void checkArguments(int argc)
{
	if(argc != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		std::exit(1);
	}
}

void splitLine(const std::string &line,char delimiter, std::map<std::string, int> &dataBase)
{
	std::stringstream ss(line);
	std::string key;
	std::string value;

	if (std::getline(ss, key, delimiter) && std::getline(ss, value))
	{
		std::istringstream valueStream(value);
		int intValue;
		if (valueStream >> intValue)
			dataBase[key] = intValue;
	}
	else
		std::cerr << "Error: malformed line: " << line << std::endl;
}

std::map<std::string, int> readDataBase()
{
	std::string file_name = "data.csv";
	std::ifstream file(file_name.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		std::exit(1);
	}

	std::string line;
	std::map<std::string, int> dataBase;
	while(std::getline(file, line))
		splitLine(line,',', dataBase);
	return dataBase;
}

void printDataBase(std::map<std::string, int> dataBase)
{
	// Print the database
	for (std::map<std::string, int>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it)
		std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
}

bool isYearValid(std::string year)
{
	int yearInt = std::atoi(year.c_str());

	if( yearInt < 2009 || yearInt > 2025)
	{
		std::cerr << "Invalid Year" << std::endl;
		return false;
	}
	return true;
}

bool isMonthValid(std::string month)
{
	int monthInt = std::atoi(month.c_str());

	if(monthInt < 1 || monthInt > 12)
		return false;
	return true;
}

bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}


bool isDayValid(bool leapYear, std::string month, std::string day)
{

	for (size_t i = 0; i < day.size(); ++i) {
		if (!std::isdigit(day[i]) && day[i] != 32)
		{
			std::cerr << "Invalid Day: contains non-digit characters" << std::endl;
			return false;
		}
	}

	int dayInt = std::atoi(day.c_str());
	int monthInt = std::atoi(month.c_str());

	std::map<int, int> mapMonths;
	mapMonths.insert(std::make_pair(1, 31));
	if(leapYear)
		mapMonths.insert(std::make_pair(2, 29));
	else
		mapMonths.insert(std::make_pair(2, 28));
	mapMonths.insert(std::make_pair(3, 31));
	mapMonths.insert(std::make_pair(4, 30));
	mapMonths.insert(std::make_pair(5, 31));
	mapMonths.insert(std::make_pair(6, 30));
	mapMonths.insert(std::make_pair(7, 31));
	mapMonths.insert(std::make_pair(8, 31));
	mapMonths.insert(std::make_pair(9, 30));
	mapMonths.insert(std::make_pair(10, 31));
	mapMonths.insert(std::make_pair(11, 30));
	mapMonths.insert(std::make_pair(12, 31));


	if(dayInt > mapMonths.at(monthInt) ||  dayInt < 1)
		return false;

	return true;
}

bool isDataValid(std::string date)
{
	size_t firstDash = date.find('-');
	size_t secondDash = date.find('-', firstDash + 1);

	if(firstDash == std::string::npos || secondDash == std::string::npos)
	{
		std::cerr << "Invalid Date format" << std::endl;
		return false;
	}
	std::string year = date.substr(0, firstDash);
	std::string month = date.substr(firstDash + 1, secondDash - firstDash - 1);
	std::string day = date.substr(secondDash + 1);
	bool leapYear = isLeapYear(std::atoi(year.c_str()));

	if(!isYearValid(year) || !isMonthValid(month) || !isDayValid(leapYear, month, day))
	{
		std::cerr << "Invalid Date Format" << std::endl;
		return false;
	}
	std::cout << year << "-" << month << "-" << day << "=>"  << std::endl;
	return true;
}

void checkLine(const std::string& line)
{
	std::stringstream ss(line);
	std::string data;
	std::string value;

	if (std::getline(ss, data, '|') && std::getline(ss, value))
	{
		std::istringstream valueStream(value);
		if(!isDataValid(data))
			std::cout << "Invalid Data Format" << std::endl;
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
	return file; // Return a pointer
}

void exchange(const std::map<std::string, int>&dataBase, std::string line)
{
	(void) dataBase;
	(void ) line;
	std::cout << "Correct Date " << std::endl;
}

void readLine(std::ifstream *file)
{
	std::map<std::string, int> dataBase =  readDataBase();
	std::string line;
	while (std::getline(*file, line))
	{
		checkLine(line);
		exchange(dataBase, line);
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	checkArguments(argc);
	std::ifstream* file = openFile(argv);
	readLine(file);

	delete file;
//	std::map<std::string, int> dataBase =  readDataBase();

    return 0;
}
