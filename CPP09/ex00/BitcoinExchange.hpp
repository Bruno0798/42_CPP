#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

class BitcoinExchange
{
private:
	std::map<std::string, float> dataBase;
	std::map<int, int> mapMonths;
	std::string line;
	int year;
	int month;
	int day;
	float value;
public:
	/**
	 * Default constructor - Initializes an empty BitcoinExchange object
	 */
	BitcoinExchange();
	
	/**
	 * Parametrized constructor - Creates a BitcoinExchange object with predefined data
	 * @param data Map of date strings to exchange rate values
	 */
	BitcoinExchange(std::map<std::string, float> data);
	
	/**
	 * Destructor - Cleans up resources
	 */
	~BitcoinExchange();
	/**
	 * Copy constructor - Creates a deep copy of another BitcoinExchange object
	 * @param other The BitcoinExchange object to copy from
	 */
	BitcoinExchange(const BitcoinExchange &other);

	/**
	 * Assignment operator - Assigns data from another BitcoinExchange object
	 * @param other The BitcoinExchange object to assign from
	 * @return Reference to this object after assignment
	 */
	BitcoinExchange &operator=(const BitcoinExchange &other);

	/**
	 * Get the database of exchange rates
	 * @return Constant reference to the map of exchange rates
	 */
	const std::map<std::string, float> &getDataBase() const;

	/**
	 * Set the database of exchange rates
	 * @param dataBase Map of date strings to exchange rate values
	 */
	void setDataBase(const std::map<std::string, float> &dataBase);
	/**
	 * Get the year component
	 * @return The year as an integer
	 */
	int getYear() const;

	/**
	 * Set the year component with validation
	 * @param year The year to set (must be between 2009 and 2025)
	 * @throw MyException if year is out of valid range
	 */
	void setYear(int year);

	/**
	 * Get the month component
	 * @return The month as an integer (1-12)
	 */
	int getMonth() const;

	/**
	 * Set the month component with validation
	 * @param month The month to set (must be between 1 and 12)
	 * @throw MyException if month is out of valid range
	 */
	void setMonth(int month);

	/**
	 * Get the day component
	 * @return The day as an integer
	 */
	int getDay() const;

	/**
	 * Set the day component with validation
	 * @param dayString The day to set as a string (will be converted to int)
	 * @throw MyException if day is invalid for the month/year or contains non-digit characters
	 */
	void setDay(std::string dayString);

	/**
	 * Checks if a given year is a leap year
	 * @param year The year to check
	 * @return true if the year is a leap year, false otherwise
	 */
	bool isLeapYear(int year);

	/**
	 * Formats a date as YYYY-MM-DD with proper padding for month and day
	 * @param year The year component
	 * @param month The month component
	 * @param day The day component
	 * @return A formatted date string in YYYY-MM-DD format
	 */
	std::string formatDate(int year, int month, int day) const;

	/**
	 * Gets the current date formatted as YYYY-MM-DD
	 * @return The current date as a string
	 */
	std::string getCurrentDate() const;

	/**
	 * Performs the exchange calculation based on the nearest available exchange rate
	 * @throw MyException if the database is empty or if no suitable rate is found
	 */
	void exchange();

	/**
	 * Gets the current value
	 * @return The current value as a float
	 */
	float getValue() const;

	/**
	 * Sets the value, validating it's within acceptable range
	 * @param value The value to set (must be between 0 and 1000)
	 * @throw MyException if the value is out of range
	 */
	void setValue(float value);
	/**
	 * Get the current line being processed
	 * @return Constant reference to the line string
	 */
	const std::string &getLine() const;

	/**
	 * Set the current line being processed
	 * @param line The line to set
	 */
	void setLine(const std::string &line);

	/**
	 * Custom exception class for Bitcoin Exchange errors
	 */
	class MyException : public std::exception
	{
	private:
		std::string message;

	public:
		/**
		 * Constructor with error message
		 * @param msg The error message
		 */
		MyException(const std::string &msg);
		
		/**
		 * Destructor
		 */
		virtual ~MyException() throw();
		
		/**
		 * Get the error message
		 * @return C-string containing the error message
		 */
		virtual const char *what() const throw();
	};

};

#endif
