#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main() {
	try {
		std::cout << cyan << "\n[TEST 1: ShrubberyCreationForm with Sufficient Grade]" << reset << std::endl;
		ShrubberyCreationForm shrubForm("Garden");
		Bureaucrat Bob("Bob", 137); // Exact grade needed for execution
		std::cout << shrubForm << std::endl;
		Bob.signForm(shrubForm);
		Bob.executeForm(shrubForm);

		std::cout << cyan << "\n[TEST 2: ShrubberyCreationForm with Insufficient Grade]" << reset << std::endl;
		Bureaucrat Alice("Alice", 150); // Too low to execute
		std::cout << shrubForm << std::endl;
		Alice.signForm(shrubForm);
		Alice.executeForm(shrubForm);
	}
	catch (const std::exception &e) {
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	try {
		std::cout << cyan << "\n[TEST 3: RobotomyRequestForm with Sufficient Grade]" << reset << std::endl;
		RobotomyRequestForm robotForm("Robot");
		Bureaucrat Charlie("Charlie", 45); // Exact grade needed for execution
		std::cout << robotForm << std::endl;
		Charlie.signForm(robotForm);
		Charlie.executeForm(robotForm);

		std::cout << cyan << "\n[TEST 4: RobotomyRequestForm with Insufficient Grade]" << reset << std::endl;
		Bureaucrat Diana("Diana", 50); // Too low to execute
		std::cout << robotForm << std::endl;
		Diana.signForm(robotForm);
		Diana.executeForm(robotForm);
	}
	catch (const std::exception &e) {
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	try {
		std::cout << cyan << "\n[TEST 5: PresidentialPardonForm with Sufficient Grade]" << reset << std::endl;
		PresidentialPardonForm pardonForm("Alice");
		Bureaucrat Eric("Eric", 5); // Exact grade needed for execution
		std::cout << pardonForm << std::endl;
		Eric.signForm(pardonForm);
		Eric.executeForm(pardonForm);

		std::cout << cyan << "\n[TEST 6: PresidentialPardonForm with Insufficient Grade]" << reset << std::endl;
		Bureaucrat Frank("Frank", 10); // Too low to execute
		std::cout << pardonForm << std::endl;
		Frank.signForm(pardonForm);
		Frank.executeForm(pardonForm);
	}
	catch (const std::exception &e) {
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	return 0;
}



