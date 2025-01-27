#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", reqSign, execSign, "Default")
{
	std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :  AForm("Presidential", reqSign, execSign, target)
{
	std::cout << "Data Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm Assignment Operator Called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void PresidentialPardonForm::executor() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}