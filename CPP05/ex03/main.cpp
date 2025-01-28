#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{

//	{
//		AForm* form = new ShrubberyCreationForm("Garden");
//		delete form; // This will cause undefined behavior if AForm's destructor is not virtual
//	}
	{
		std::cout << cyan << "\n►►►►►►  " << "Testing Intern creating valid forms" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Bureaucrat b("John Doe", 5);
		Intern intern;

		try {
			AForm* shrubberyForm = intern.makeForm("shrubbery creation", "garden");
			b.signForm(*shrubberyForm);
			b.executeForm(*shrubberyForm);
			delete shrubberyForm;

			AForm* robotomyForm = intern.makeForm("robotomy request", "Alice");
			b.signForm(*robotomyForm);
			b.executeForm(*robotomyForm);
			delete robotomyForm;

			AForm* pardonForm = intern.makeForm("presidential pardon", "Bob");
			b.signForm(*pardonForm);
			b.executeForm(*pardonForm);
			delete pardonForm;
		} catch (const std::exception &e) {
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	{
		std::cout << cyan << "\n►►►►►►  " << "Testing Intern creating invalid form" << "  ◄◄◄◄◄◄" << reset << std::endl;
		Intern intern;

		try {
			AForm* invalidForm = intern.makeForm("unknown form", "nowhere");
			delete invalidForm;
		} catch (const std::exception &e) {
			std::cerr << red << "Exception: " << reset << e.what() << std::endl;
		}
	}

	std::cout << green << "All tests passed!" << reset << std::endl;
	return 0;
}