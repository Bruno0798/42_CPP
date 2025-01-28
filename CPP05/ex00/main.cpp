#include <iostream>
#include "Bureaucrat.hpp"

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

int main()
{
	{
		std::cout << cyan << "\n►►►►►►  " << "Create Bureaucrat With Valid Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 5);
		std::cout << "Name:\t" << b.getName() << std::endl;
		std::cout << "Grade:\t" << b.getGrade() << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Create Bureaucrat With High Grade" <<  "  ◄◄◄◄◄◄" << reset << std::endl;
		try
		{
			Bureaucrat b("John Doe", 0);
		} 	catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Create Bureaucrat With Low Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		try
		{
			Bureaucrat b("John Doe", 151);
		} catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Incrementing Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 2);
		std::cout <<"Before Incrementing:\t" << b.getGrade() << std::endl;
		b.incrementGrade();
		std::cout << "After Incrementing:\t" << b.getGrade() << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Incrementing Max Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 1);
		std::cout <<"Before Incrementing:\t" << b.getGrade() << std::endl;
		try {
			b.incrementGrade();
		} catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Decrementing Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 2);
		std::cout <<"Before Decrementing:\t" << b.getGrade() << std::endl;
		b.decrementGrade();
		std::cout << "After Decrementing:\t" << b.getGrade() << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Decrementing Lowest Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 150);
		std::cout <<"Before Decrementing:\t" << b.getGrade() << std::endl;
		try {
			b.decrementGrade();
		} catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Testing << Operator Overload" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 5);
		std::cout << b << std::endl;
	}

	std::cout << green << "All tests passed!" << reset << std::endl;
	return 0;
}