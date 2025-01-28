#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
public:
	static int const reqSign = 25;
	static int const execSign = 5;

	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	void executor() const;
};

#endif