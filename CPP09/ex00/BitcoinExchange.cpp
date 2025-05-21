#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
//	std::cout << "BitcoinExchange Default Constructor Called" << std::endl;

}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> data)
{
	dataBase = data;
	mapMonths.insert(std::make_pair(1, 31));
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
	// Create deep copies of all the data
	this->dataBase = other.dataBase;
	this->mapMonths = other.mapMonths;
	this->line = other.line;
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
	this->value = other.value;
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
		// Clear existing data
		this->dataBase.clear();
		this->mapMonths.clear();
		
		// Copy data from the other object
		this->dataBase = other.dataBase;
		this->mapMonths = other.mapMonths;
		this->line = other.line;
		this->year = other.year;
		this->month = other.month;
		this->day = other.day;
		this->value = other.value;
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
		oss << cyan << getLine() << reset << " Year cant be lower than 2009";
		throw MyException(oss.str());
	}
	else if (year > 2025)
	{
		oss << cyan << getLine() << reset << " Year cant be bigger than 2025";
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
	std::ostringstream oss;

	if(month < 1)
	{
		oss << cyan << getLine() << reset << " Month cant be lower than 1";
		throw MyException(oss.str());
	}
	else if (month > 12)
	{
		oss << cyan << getLine() << reset << " Month cant be bigger than 12";
		throw MyException( oss.str());
	}
	BitcoinExchange::month = month;
}

int BitcoinExchange::getDay() const
{
	return day;
}

const std::string &BitcoinExchange::getLine() const
{
	return line;
}

void BitcoinExchange::setLine(const std::string &line)
{
	BitcoinExchange::line = line;
}

void BitcoinExchange::setDay(std::string dayString)
{
	std::ostringstream oss;
	for (size_t i = 0; i < dayString.size(); ++i)
	{
		if (!std::isdigit(dayString[i]) && dayString[i] != 32)
		{
			oss << cyan << getLine() << reset << " Day cant have non-digit characters";
			throw MyException(oss.str());
		}
	}

	int day = std::atoi(dayString.c_str());
	if(day == 29 && getMonth() == 2 && !isLeapYear(year))
	{
		oss << cyan << getLine() << reset << " Impossible day, this year is not a leap year";
		throw MyException(oss.str());
	}
	if(day > mapMonths.at(getMonth()) || day < 1)
	{
		oss << cyan << getLine() << reset << " Invalid day for this month";
		throw MyException(oss.str());
	}

	BitcoinExchange::day = day;
}

bool BitcoinExchange::isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

std::string BitcoinExchange::formatDate(int year, int month, int day) const
{
	std::ostringstream oss;
	
	// Format the date as YYYY-MM-DD with leading zeros for month and day
	oss << year << "-";
	if (month < 10)
		oss << "0";
	oss << month << "-";
	if (day < 10)
		oss << "0";
	oss << day;
	
	return oss.str();
}

std::string BitcoinExchange::getCurrentDate() const
{
	return formatDate(year, month, day);
}
void BitcoinExchange::exchange()
{
	// Check if database is empty
	if (dataBase.empty())
	{
		throw MyException("Error: Database is empty");
	}
	
	// Format the current date with proper padding
	std::string formattedDate = getCurrentDate();
	
	// Find the closest date equal to or before the current date
	std::map<std::string, float>::iterator it = dataBase.upper_bound(formattedDate);
	
	// If we're past the upper bound, use the last element
	if (it == dataBase.end())
	{
		if (dataBase.size() > 0)
		{
			it = dataBase.end();
			--it; // Go to the last element
		}
		else
		{
			throw MyException("Error: No exchange rate data available");
		}
	}
	// If we're at the beginning and the date is before the first entry
	else if (it == dataBase.begin() && formattedDate < it->first)
	{
		throw MyException("Error: No exchange rate data available for date " + formattedDate);
	}
	// Otherwise, move back one to get the closest date before or equal to our date
	else if (it != dataBase.begin() && formattedDate < it->first)
	{
		--it;
	}
	
	// Print the result with proper formatting
	std::cout << formattedDate << " => " << value << " * " << it->second << " = " << (value * it->second) << std::endl;
}

float BitcoinExchange::getValue() const
{
	return value;
}

void BitcoinExchange::setValue(float value)
{
	std::ostringstream oss;
	if(value < 0)
	{
		oss << cyan << getLine() << reset << " Value cant be lower than 0";
		throw MyException(oss.str());
	}
	else if (value > 1000)
	{
		oss << cyan << getLine() << reset << " Value cant be bigger than 1000";
		throw MyException(oss.str());
	}
	BitcoinExchange::value = value;
}

BitcoinExchange::MyException::MyException(const std::string &msg) : message(msg)
{}

BitcoinExchange::MyException::~MyException() throw() {}

const char *BitcoinExchange::MyException::what() const throw() {
	return message.c_str();
}
