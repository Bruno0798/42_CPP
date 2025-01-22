#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
	// Test default constructors, copy constructors, and assignment
	{
		std::cout << cyan << "\n[TEST 0] Constructors and Copy Mechanics" << reset << std::endl;
		AForm form;
		std::cout << form << std::endl;
		std::cout << std::endl;

		AForm form2("Crazy Stuff", 120, 50);
		std::cout << form2 << std::endl;
		std::cout << std::endl;
		Bureaucrat tommy("Tommy", 1);
		tommy.signForm(form2);

		AForm form3;
		form3 = form2;
		std::cout << magenta << "Form3 (after assignment from Form2):" << reset << std::endl;
		std::cout << form3 << std::endl;

		std::cout << std::endl;
		AForm form4(form2);
		std::cout << magenta << "Form4 (copy constructed from Form2):" << reset << std::endl;
		std::cout << form4 << std::endl;
		std::cout << std::endl;
	}

	std::cout << magenta << "\n--- Form Testing Suite ---" << reset << std::endl;
	try {
		std::cout << cyan << "\n[TEST 1] Signing Form Successfully" << reset << std::endl;
		AForm form2("Top Secret", 149, 1);
		Bureaucrat tommy("Tommy", 1);

		std::cout << blue << "Before signing:" << reset << std::endl;
		std::cout << tommy << std::endl;
		std::cout << form2 << std::endl;

		tommy.signForm(form2);

		std::cout << green << "After signing:" << reset << std::endl;
		std::cout << form2 << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	// Test signing a form with insufficient grade
	try {
		std::cout << cyan << "\n[TEST 2] Signing Form With Insufficient Grade" << reset << std::endl;
		AForm form2("Confidential", 149, 1);
		Bureaucrat tommy("Tommy", 150);

		std::cout << blue << "Before signing:" << reset << std::endl;
		std::cout << tommy << std::endl;
		std::cout << form2 << std::endl;

		tommy.signForm(form2);

		std::cout << green << "After signing:" << reset << std::endl;
		std::cout << form2 << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	// Test creating a form with an invalid grade
	try {
		std::cout << cyan << "\n[TEST 3] Creating Form With Invalid Grade (Too High)" << reset << std::endl;
		AForm form("Impossible Form", 0, 10);
	}
	catch (const std::exception &e) {
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	try {
		std::cout << cyan << "\n[TEST 4] Creating Form With Invalid Grade (Too Low)" << reset << std::endl;
		AForm form("Impossible Form", 151, 10);
	}
	catch (const std::exception &e) {
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	try {
		std::cout << cyan << "\n[TEST 5] Trying to sign again" << reset << std::endl;
		AForm form("Signed Form", 100, 10);
		Bureaucrat tommy("Tommy", 1);
		Bureaucrat fred("Fred", 1);
		tommy.signForm(form);
		fred.signForm(form);
	}
	catch (const std::exception &e) {
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}

	return 0;
}



