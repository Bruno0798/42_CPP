#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", reqSign, execSign, "Default")
{
	std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", reqSign, execSign, target)
{
	std::cout << "Data Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Assignment Operator Called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::executor() const
{
	std::srand(std::time(0));
	if((rand() % 2) == 0)
		std::cout << getTarget() << " has been Robotomized Successfully" << std::endl;
	else
		std::cout << getTarget() << " Robotomized Failed!" << std::endl;
}