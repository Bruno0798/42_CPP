#include "templates.hpp"
#include <cstdlib>
#include <vector>
#include <iostream>

void printVector(const std::vector<int> &vct)
{
	std::cout << "Generated sequence: ";
	for (size_t i = 0; i < vct.size(); i++)
		std::cout << vct.at(i) << " ";
	std::cout << std::endl;
}

std::vector<int> createVector(size_t max)
{
	std::vector<int> number;
	for (size_t i = 0; i < max; i++)
		number.push_back(i + 1);
	return number;
}

bool checkInput(int &max)
{
	if (!(std::cin >> max))
		return std::cerr << std::endl << "Invalid input. (Ctrl + D or non-numeric value)." << std::endl, false;
	else if (max <= 0)
		return std::cout << "Input must be greater than 0." << std::endl, max = 0, false;
	return true;
}

int main()
{
	int max;
	std::cout << "Enter the maximum number for the sequence: ";
	if (!checkInput(max))
		std::exit(1);
	std::vector<int> numbers = createVector(max);
	printVector(numbers);
	try
	{
		int toFind;
		std::cout << "\nEnter a number to search for: ";
		if (!checkInput(toFind))
			std::exit(1);
		std::vector<int>::iterator it = easyFind(numbers, toFind);
		std::cout << "Success! Number " << toFind << " is located at index " << std::distance(numbers.begin(), it) << "." << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Error: " << e.what() << " Please try again with a valid number.\n";
	}
	return 0;
}
