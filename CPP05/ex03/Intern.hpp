#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	AForm* makeShrubberyForm(std::string form);
	AForm* makeRobotomyForm(std::string form);
	AForm* makePresidentialForm(std::string form);
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	AForm *makeForm(std::string name, const std::string target);

	class FormDoesntExist : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif