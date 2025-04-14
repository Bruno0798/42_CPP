#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
//	std::cout << "BitcoinExchange Default Constructor Called" << std::endl;

}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> data)
{
	dataBase = data;
	mapMonths[1] = 31;
	mapMonths.insert(std::make_pair(2, 29));
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

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
//	std::cout << "BitcoinExchange Copy Constructor Called" << std::endl;
	*this = other;
}

BitcoinExchange::~BitcoinExchange()
{
//	std::cout << "BitcoinExchange Destructor Called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
//	std::cout << "BitcoinExchange Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		// Copy assignment operator implementation
	}
	return *this;
}

const std::map<std::string, float> &BitcoinExchange::getDataBase() const
{
	return dataBase;
}

void BitcoinExchange::setDataBase(const std::map<std::string, float> &dataBase)
{
	BitcoinExchange::dataBase = dataBase;
}

int BitcoinExchange::getYear() const
{
	return year;
}

void BitcoinExchange::setYear(int year)
{
	std::ostringstream oss;
	if (year < 2009)
	{
		oss << "Year: " << year << " Cant Be Lower than 2009";
		throw MyException(oss.str());
	}
	else if (year > 2025)
	{
		oss << "Year: " << year << " Cant Be Bigger than 2009";
		throw MyException(oss.str());
	}
	BitcoinExchange::year = year;
}

int BitcoinExchange::getMonth() const
{
	return month;
}

void BitcoinExchange::setMonth(int month)
{
	if(month < 1)
		throw MyException("Month: Cant be Lower than 1");
	else if (month > 12)
		throw MyException("Month: Cant be bigger than 12");
	BitcoinExchange::month = month;
}

int BitcoinExchange::getDay() const
{
	return day;
}

void BitcoinExchange::setDay(std::string dayString)
{
	for (size_t i = 0; i < dayString.size(); ++i)
		if (!std::isdigit(dayString[i]) && dayString[i] != 32)
			throw MyException("Invalid Day: contains non-digit characters");

	int day = std::atoi(dayString.c_str());
	if(day == 29 && getMonth() == 2 && !isLeapYear(year))
		throw MyException("Invalid Day, this year is not a leap year");
	if(day > mapMonths.at(getMonth()))
		throw MyException("Invalid Day");

	BitcoinExchange::day = day;
}

bool BitcoinExchange::isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

void BitcoinExchange::exchange()
{
	std::map<std::string, float>::iterator it = dataBase.lower_bound("2011-01-01");
	if (it == dataBase.begin())
		throw MyException("Error: Data too low");
	else if (it == dataBase.end())
		throw MyException("Error: Data too high");
	else
		std::cout << getYear() << "-" << getMonth() << "-" << getDay() << " => " << value << " " << (value * it->second) << std::endl;
}

int BitcoinExchange::getValue() const
{
	return value;
}

void BitcoinExchange::setValue(int value)
{
	if(value < 0)
		throw MyException("Value cant be lower than 0");
	else if (value > 1000)
		throw MyException("Value cant be bigger than 1000");
	BitcoinExchange::value = value;
}

BitcoinExchange::MyException::MyException(const std::string &msg) : message(msg)
{}

BitcoinExchange::MyException::~MyException() throw() {}

const char *BitcoinExchange::MyException::what() const throw() {
	return message.c_str();
}
