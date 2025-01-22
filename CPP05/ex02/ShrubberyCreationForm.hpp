#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
public:
	static int const reqSign = 145;
	static int const execSign = 137;

	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
};

#endif