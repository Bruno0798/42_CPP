#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << cyan << "\n►►►►►►  " << "Create Form With Valid Grades" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Form f("Form1", 5, 10);
		std::cout << "Name:\t\t\t" << f.getName() << std::endl;
		std::cout << "Required Sign Grade:\t" << f.getReqSign() << std::endl;
		std::cout << "Required Execute Grade:\t" << f.getExecSign() << std::endl;
		std::cout << "Is Signed:\t\t" << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Create Form With High Sign Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		try
		{
			Form f("Form2", 0, 10);
		} catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Create Form With Low Sign Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		try
		{
			Form f("Form3", 151, 10);
		} catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Create Form With High Execute Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		try
		{
			Form f("Form4", 10, 0);
		} catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Create Form With Low Execute Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		try
		{
			Form f("Form5", 10, 151);
		} catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Signing Form" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 5);
		Form f("Form6", 10, 10);
		std::cout << "Before Signing:\t" << (f.getIsSigned() ? "Yes" : "No") << std::endl;
		f.beSigned(b);
		std::cout << "After Signing:\t" << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Signing Form With Low Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 15);
		Form f("Form7", 10, 10);
		try
		{
			f.beSigned(b);
		} catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Testing signForm Function" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 5);
		Form f("Form9", 10, 10);
		std::cout << "Before Signing:\t" << (f.getIsSigned() ? "Yes" : "No") << std::endl;
		b.signForm(f);
		std::cout << "After Signing:\t" << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Testing signForm Function with Low Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("Jane Doe", 15);
		Form f("Form10", 10, 10);
		std::cout << "Before Signing:\t" << (f.getIsSigned() ? "Yes" : "No") << std::endl;
		b.signForm(f);
		std::cout << "After Signing:\t" << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  Testing << Operator Overload  ◄◄◄◄◄◄" << reset << std::endl;
		Form f("Form8", 5, 10);
		std::cout << f << std::endl;
	}

	{
		std::cout << cyan << "\n►►►►►►  Testing << Operator Overload After Signing  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 1);
		Form f("Form8", 5, 10);
		std::cout << f << std::endl;
		try
		{
			f.beSigned(b);
		} catch (std::exception &e)
		{
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
		std::cout << f << std::endl;
	}
	std::cout << green << "All tests passed!" << reset << std::endl;
	return 0;
}