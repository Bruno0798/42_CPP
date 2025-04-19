#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include "BitcoinExchange.hpp"

// ANSI color definitions for terminal output
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

// Program version
#define VERSION "1.0.0"
/**
 * Display usage information for the program
 */
void displayUsage()
{
	std::cout << yellow << "Bitcoin Exchange Rate Calculator v" << VERSION << reset << std::endl;
	std::cout << "Usage: " << cyan << "./btc <input_file>" << reset << std::endl;
	std::cout << "  <input_file>: A file containing date and value pairs in the format: YYYY-MM-DD | value" << std::endl;
	std::cout << std::endl;
	std::cout << "Example input file format:" << std::endl;
	std::cout << "  date | value" << std::endl;
	std::cout << "  2020-01-01 | 5" << std::endl;
	std::cout << "  2020-01-02 | 10.5" << std::endl;
}

/**
 * Validate command-line arguments
 * @param argc Number of arguments
 * @param argv Array of argument strings
 * @throw BitcoinExchange::MyException if arguments are invalid
 */
void checkArguments(int argc, char **argv)
{
	if(argc != 2)
	{
		displayUsage();
		throw BitcoinExchange::MyException("Error: Invalid number of arguments");
	}
	
	if (!argv[1] || strlen(argv[1]) == 0)
	{
		displayUsage();
		throw BitcoinExchange::MyException("Error: Empty filename provided");
	}
}

/**
 * Trim whitespace from beginning and end of a string
 * @param str String to trim
 * @return Trimmed string
 */
std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	size_t last = str.find_last_not_of(" \t\n\r");
	if (first == std::string::npos || last == std::string::npos)
		return "";
	return str.substr(first, last - first + 1);
}

/**
 * Split a line by delimiter and add to database
 * @param line Line to split
 * @param delimiter Character to split by
 * @param dataBase Map to store results
 * @param lineNumber Current line number for error reporting
 * @throw BitcoinExchange::MyException for malformed input
 */
void splitLine(const std::string &line, char delimiter, std::map<std::string, float> &dataBase, int lineNumber)
{
	if (line.empty() || line[0] == '#' || line == "date,exchange_rate")
		return; // Skip empty lines, comments, or header
		
	std::stringstream ss(line);
	std::string key;
	std::string value;

	if (std::getline(ss, key, delimiter) && std::getline(ss, value))
	{
		key = trim(key);
		value = trim(value);
		
		if (key.empty())
		{
			std::ostringstream oss;
			oss << "Warning: Line " << lineNumber << " - Empty date field: " << line;
			std::cerr << yellow << oss.str() << reset << std::endl;
			return;
		}
		
		// Validate date format (YYYY-MM-DD)
		if (key.length() < 8 || count(key.begin(), key.end(), '-') != 2)
		{
			std::ostringstream oss;
			oss << "Warning: Line " << lineNumber << " - Invalid date format: " << key;
			std::cerr << yellow << oss.str() << reset << std::endl;
			return;
		}
		
		// Convert value to float
		char* endptr;
		float floatValue = strtof(value.c_str(), &endptr);
		
		if (*endptr != '\0' || floatValue < 0)
		{
			std::ostringstream oss;
			oss << "Warning: Line " << lineNumber << " - Invalid value: " << value;
			std::cerr << yellow << oss.str() << reset << std::endl;
			return;
		}
		
		// Store valid data
		dataBase[key] = floatValue;
	}
	else
	{
		std::ostringstream oss;
		oss << "Warning: Line " << lineNumber << " - Malformed line: " << line;
		std::cerr << yellow << oss.str() << reset << std::endl;
	}
}

/**
 * Read the database file and populate the exchange rate database
 * @return Map of dates to exchange rates
 * @throw BitcoinExchange::MyException if database file cannot be opened or is empty
 */
std::map<std::string, float> readDataBase()
{
	const std::string file_name = "data.csv";
	std::ifstream file(file_name.c_str());
	
	if(!file.is_open())
	{
		std::ostringstream oss;
		oss << "Error: could not open database file '" << file_name << "'";
		throw BitcoinExchange::MyException(oss.str());
	}
	
	std::string line;
	std::map<std::string, float> dataBase;
	int lineNumber = 0;
	
	while(std::getline(file, line))
	{
		lineNumber++;
		splitLine(line, ',', dataBase, lineNumber);
	}
	
	if (dataBase.empty())
	{
		throw BitcoinExchange::MyException("Error: Database is empty or contains no valid data");
	}
	
	std::cout << green << "Successfully loaded " << dataBase.size() << " exchange rate entries" << reset << std::endl;
	return dataBase;
}
/**
 * Print the database contents (for debugging)
 * @param dataBase Map of dates to exchange rates
 */
void printDataBase(const std::map<std::string, float> &dataBase)
{
	std::cout << cyan << "Database Contents (" << dataBase.size() << " entries):" << reset << std::endl;
	for (std::map<std::string, float>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it)
		std::cout << "  " << it->first << " => " << it->second << std::endl;
}

/**
 * Validate and parse a date string into the BitcoinExchange object
 * @param bitcoin BitcoinExchange object to update
 * @param date Date string to parse in format YYYY-MM-DD
 * @throw BitcoinExchange::MyException if date is invalid
 */
void checkDate(BitcoinExchange &bitcoin, const std::string &date)
{
	std::ostringstream oss;
	size_t dashCount = std::count(date.begin(), date.end(), '-');
	
	// Validate date format
	if(dashCount < 2)
	{
		oss << cyan << bitcoin.getLine() << reset << " Missing fields from date";
		throw BitcoinExchange::MyException(oss.str());
	}
	else if(dashCount > 2)
	{
		oss << cyan << bitcoin.getLine() << reset << " Too many fields for a date";
		throw BitcoinExchange::MyException(oss.str());
	}
	
	// Extract date components
	size_t firstDash = date.find('-');
	size_t secondDash = date.find('-', firstDash + 1);
	
	std::string yearStr = date.substr(0, firstDash);
	std::string monthStr = date.substr(firstDash + 1, secondDash - firstDash - 1);
	std::string dayStr = date.substr(secondDash + 1);
	
	// Validate all components are numeric
	for (size_t i = 0; i < yearStr.length(); i++) {
		if (!isdigit(yearStr[i])) {
			oss << cyan << bitcoin.getLine() << reset << " Year must contain only digits: " << yearStr;
			throw BitcoinExchange::MyException(oss.str());
		}
	}
	
	for (size_t i = 0; i < monthStr.length(); i++) {
		if (!isdigit(monthStr[i])) {
			oss << cyan << bitcoin.getLine() << reset << " Month must contain only digits: " << monthStr;
			throw BitcoinExchange::MyException(oss.str());
		}
	}
	
	// Set the date components with validation
	try {
		bitcoin.setYear(std::atoi(yearStr.c_str()));
		bitcoin.setMonth(std::atoi(monthStr.c_str()));
		bitcoin.setDay(dayStr);
	} catch (BitcoinExchange::MyException &e) {
		throw; // Rethrow the exception as it's already properly formatted
	} catch (std::exception &e) {
		oss << cyan << bitcoin.getLine() << reset << " Invalid date: " << e.what();
		throw BitcoinExchange::MyException(oss.str());
	}
}
/**
 * Process a single line from the input file
 * @param bitcoin BitcoinExchange object to use for processing
 * @param line The line to process
 */
void checkLine(BitcoinExchange &bitcoin, const std::string& line)
{
	try
	{
		bitcoin.setLine(line);
		
		// Skip empty lines or comment lines
		if (line.empty() || line[0] == '#') {
			return;
		}
		
		// Skip header line
		if (line.find("date | value") != std::string::npos) {
			return;
		}
		
		std::stringstream ss(line);
		std::string date;
		std::string value;

		if (std::getline(ss, date, '|') && std::getline(ss, value))
		{
			date = trim(date);
			value = trim(value);
			
			if (date.empty()) {
				throw BitcoinExchange::MyException("Empty date field");
			}
			
			checkDate(bitcoin, date);
			
			// Convert value to float with validation
			char* end;
			float amount = std::strtof(value.c_str(), &end);
			
			if (*end != '\0') {
				std::ostringstream oss;
				oss << cyan << bitcoin.getLine() << reset << " Error: invalid value => " << value;
				throw BitcoinExchange::MyException(oss.str());
			}
			
			bitcoin.setValue(amount);
			bitcoin.exchange();
		}
		else
		{
			std::ostringstream oss;
			oss << cyan << bitcoin.getLine() << reset << " Error: bad input => " << line;
			throw BitcoinExchange::MyException(oss.str());
		}
	}
	catch (BitcoinExchange::MyException &e)
	{
		std::cout << red << e.what() << reset << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << red << "Error: " << e.what() << reset << std::endl;
	}
}


/**
 * Open the input file and return the file stream
 * @param filename Name of the file to open
 * @return Pointer to an open ifstream
 * @throw BitcoinExchange::MyException if file cannot be opened
 */
std::ifstream* openFile(const char* filename)
{
	std::ifstream* file = new std::ifstream(filename);
	
	if (!file || !file->is_open())
	{
		delete file; // Clean up if file couldn't be opened
		
		std::ostringstream oss;
		oss << "Error: could not open file '" << filename << "'";
		throw BitcoinExchange::MyException(oss.str());
	}
	
	return file;
}


/**
 * Process all lines from the input file
 * @param bitcoin BitcoinExchange object to use for processing
 * @param file Input file stream to read from
 */
void processInputFile(BitcoinExchange &bitcoin, std::ifstream *file)
{
	if (!file) {
		throw BitcoinExchange::MyException("Error: Invalid file pointer");
	}
	
	std::string line;
	int lineCount = 0;
	
	// Skip header line if it exists
	std::getline(*file, line);
	
	// Process remaining lines
	while (std::getline(*file, line))
	{
		lineCount++;
		checkLine(bitcoin, line);
	}
	
	if (lineCount == 0) {
		std::cout << yellow << "Warning: Input file is empty or contains only a header" << reset << std::endl;
	}
}

/**
 * Main function - Entry point of the program
 * @param argc Argument count
 * @param argv Argument vector
 * @return Exit status
 */
int main(int argc, char **argv)
{
	try {
		// Validate command-line arguments
		checkArguments(argc, argv);
		
		// Load database
		std::map<std::string, float> dataBase = readDataBase();
		BitcoinExchange bitcoin(dataBase);
		
		// Open and process input file
		std::ifstream* file = openFile(argv[1]);
		processInputFile(bitcoin, file);
		
		// Clean up
		delete file;
		
		return 0;
	}
	catch (BitcoinExchange::MyException &e) {
		std::cerr << red << e.what() << reset << std::endl;
		return 1;
	}
	catch (std::exception &e) {
		std::cerr << red << "Error: " << e.what() << reset << std::endl;
		return 1;
	}
}
