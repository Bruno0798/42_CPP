#include "Intern.hpp"


Intern::Intern()
{
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern Copy Constructor Called" << std::endl;
	*this = other;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern Assignment Operator Called" << std::endl;
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string name, const std::string target)
{
	const std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*functions[])(const std::string) = {
			&Intern::makeShrubberyForm,
			&Intern::makeRobotomyForm,
			&Intern::makePresidentialForm
	};

	for (int i = 0; i < 3; ++i) {
		if (forms[i] == name) {
			AForm *form = (this->*functions[i])(target);
			std::cout << "Intern creates " << *form << std::endl;
			return form;
		}
	}
	throw FormDoesntExist();
}

AForm* Intern::makePresidentialForm(std::string form)
{
	return new PresidentialPardonForm(form);
}


AForm* Intern::makeRobotomyForm(std::string form)
{
	return new RobotomyRequestForm(form);
}

AForm* Intern::makeShrubberyForm(std::string form)
{
	return new ShrubberyCreationForm(form);
}

const char* Intern::FormDoesntExist::what() const throw()
{
	return "Form does not exist!\n";
}