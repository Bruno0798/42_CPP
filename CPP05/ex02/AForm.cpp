#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
		: _name("Default"), _isSigned(false), _reqSign(1), _execSign(1), _target("Default")
{
	std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(const std::string& name, int reqSign, int execSign, const std::string& target)
		: _name(name), _isSigned(false), _reqSign(reqSign), _execSign(execSign), _target(target)
{
	std::cout << "Full AForm Constructor Called" << std::endl;
	if (getReqSign() < 1 || getExecSign() < 1)
		throw GradeTooHighException();
	if (getReqSign() > 150 || getExecSign() > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
		: _name(other._name), _isSigned(other._isSigned), _reqSign(other._reqSign), _execSign(other._execSign)
{
	std::cout << "AForm Copy Constructor Called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm Assignment Operator Called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getReqSign() const
{
	return _reqSign;
}

int AForm::getExecSign() const
{
	return _execSign;
}

std::string AForm::getTarget() const
{
	return _target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >= _reqSign)
		throw GradeTooLowException();
	else
		_isSigned = true;
}
void AForm::execute(const Bureaucrat &executor) const
{

}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too High!\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too Low!\n";
}

std::ostream& operator<<(std::ostream &output, const AForm& form)
{
	output << "Form: " << form.getName()
		   << " needs " << form.getReqSign()
		   << " to be signed and " << form.getExecSign()
		   << " to execute, status: "
		   << (form.getIsSigned() ? "Signed" : "Unsigned");
	return output;
}