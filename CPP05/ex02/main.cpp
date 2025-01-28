#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{

//	{
//		AForm* form = new ShrubberyCreationForm("Garden");
//		delete form; // This will cause undefined behavior if AForm's destructor is not virtual
//	}
	{
		std::cout << cyan << "\n►►►►►►  " << "Executing Signed Form" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 1);
		ShrubberyCreationForm form(b.getName());
		b.signForm(form);
		b.executeForm(form);
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Executing Unsigned Form" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 1);
		ShrubberyCreationForm form(b.getName());
		try {
			b.executeForm(form);
		} catch (const std::exception &e) {
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Executing Form With Insufficient Grade" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 150);
		ShrubberyCreationForm form(b.getName());
		b.signForm(form);
		try {
			b.executeForm(form);
		} catch (const std::exception &e) {
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Creating and Executing RobotomyRequestForm" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 1);
		RobotomyRequestForm form(b.getName());
		b.signForm(form);
		b.executeForm(form);
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Creating and Executing PresidentialPardonForm" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 1);
		PresidentialPardonForm form(b.getName());
		b.signForm(form);
		b.executeForm(form);
	}

	std::cout << green << "All tests passed!" << reset << std::endl;
	return 0;
}



