#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
public:
	static int const reqSign = 72;
	static int const execSign = 45;

	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();
	void executor() const;
};

#endif