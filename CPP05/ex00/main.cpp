
#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"

int main()
{

	std::cout << green << "\nSmall texts of = and Copy Constructor" << reset << std::endl;
	{
		Bureaucrat tommy;
		Bureaucrat a(tommy);


		std::cout << cyan << "Must copy the name and grade" << reset << std::endl;
		std::cout << tommy << std::endl;
		std::cout << a << std::endl;

		std::cout <<std::endl;

		std::cout << cyan << "Now will only do the = to the grade" << reset << std::endl;
		Bureaucrat men("men", 25);
		a = men;
		std::cout << a << std::endl;
	}

	std::cout << magenta << "--- Bureaucrat Testing Suite ---" << reset << std::endl;

	try
	{
		std::cout << cyan << "\n[TEST 1] Default Constructor" << reset << std::endl;
		Bureaucrat tommy;
		std::cout << green << "Created: " << reset << tommy << std::endl;

		std::cout << cyan << "\n[TEST 2] Parameterized Constructor" << reset << std::endl;
		Bureaucrat smith("Smith", 20);
		std::cout << green << "Created: " << reset << smith << std::endl;

		std::cout << yellow << "\nIncrementing Smith's grade by 19..." << reset << std::endl;
		smith.incrementGrade();
		std::cout << green << "Updated: " << reset << smith << std::endl;

		std::cout << yellow << "\nAttempting to increment Smith's grade beyond limit..." << reset << std::endl;
		smith.incrementGrade(); // This should throw GradeTooHighException
	}
	catch (const std::exception &e)
	{
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	std::cout << magenta << "\n--- Additional Tests ---" << reset << std::endl;

	try
	{
		std::cout << cyan << "\n[TEST 3] Creating Bureaucrat with Grade 1" << reset << std::endl;
		Bureaucrat elite("Elite", 1);
		std::cout << green << "Created: " << reset << elite << std::endl;

		std::cout << yellow << "Attempting to increment Elite's grade..." << reset << std::endl;
		elite.incrementGrade(); // This should throw GradeTooHighException
	}
	catch (const std::exception &e)
	{
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	try
	{
		std::cout << cyan << "\n[TEST 4] Creating Bureaucrat with Grade 150" << reset << std::endl;
		Bureaucrat newbie("Newbie", 150);
		std::cout << green << "Created: " << reset << newbie << std::endl;

		std::cout << yellow << "Attempting to decrement Newbie's grade..." << reset << std::endl;
		newbie.decrementGrade(); // This should throw GradeTooLowException
	}
	catch (const std::exception &e)
	{
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	try
	{
		std::cout << cyan << "\n[TEST 5] Creating Bureaucrat with Invalid Grade (too high)" << reset << std::endl;
		Bureaucrat invalidHigh("TooHigh", 0); // Invalid grade
	}
	catch (const std::exception &e)
	{
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	try
	{
		std::cout << cyan << "\n[TEST 6] Creating Bureaucrat with Invalid Grade (too low)" << reset << std::endl;
		Bureaucrat invalidLow("TooLow", 151); // Invalid grade
	}
	catch (const std::exception &e)
	{
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	std::cout << magenta << "\n--- End of Tests ---" << reset << std::endl;

	return 0;
}


