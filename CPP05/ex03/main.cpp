#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

	Bureaucrat boss("Boss", 1);
	Intern intern;

	// Intern creates different forms
	std::cout << cyan << "Testing Intern creating forms:" << reset << std::endl;

	AForm* shrubberyForm = NULL;
	AForm* robotomyForm = NULL;
	AForm* pardonForm = NULL;
	AForm* invalidForm = NULL;

	try {

		// Intern creates different forms
		std::cout << cyan << "Testing Intern creating forms:" << reset << std::endl;

		shrubberyForm = intern.makeForm("shrubbery creation", "garden");
		robotomyForm = intern.makeForm("robotomy request", "Alice");
		pardonForm = intern.makeForm("presidential pardon", "Bob");

		// Test form creation and execution
		std::cout << "\nShrubbery Creation Form:" << std::endl;
		boss.signForm(*shrubberyForm);
		boss.executeForm(*shrubberyForm);

		std::cout << "\nRobotomy Request Form:" << std::endl;
		boss.signForm(*robotomyForm);
		boss.executeForm(*robotomyForm);

		std::cout << "\nPresidential Pardon Form:" << std::endl;
		boss.signForm(*pardonForm);
		boss.executeForm(*pardonForm);

		// Test invalid form creation
		std::cout << "\nTesting invalid form creation by Intern:" << std::endl;
		invalidForm = intern.makeForm("unknown form", "nowhere");

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		// Clean up memory
	}

	delete shrubberyForm;
	delete robotomyForm;
	delete pardonForm;
	delete invalidForm;

	return 0;
}
