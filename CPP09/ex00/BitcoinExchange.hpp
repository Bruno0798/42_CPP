#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> dataBase;
	std::map<int, int> mapMonths;
	int year;
	int month;
	int day;
	float value;
public:
	BitcoinExchange();
	BitcoinExchange(std::map<std::string, float> data);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	const std::map<std::string, float> &getDataBase() const;

	void setDataBase(const std::map<std::string, float> &dataBase);
	int getYear() const;
	void setYear(int year);
	int getMonth() const;
	void setMonth(int month);
	int getDay() const;
	void setDay(std::string dayString);

	bool isLeapYear(int year);

	void exchange();

	int getValue() const;

	void setValue(int value);

	class MyException : public std::exception
	{
	private:
		std::string message;

	public:
		MyException(const std::string &msg);
		virtual ~MyException() throw();
		virtual const char *what() const throw();
	};

};

#endif
