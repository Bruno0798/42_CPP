#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
		: _name("Default"), _isSigned(false), reqSign(1), execSign(1)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

AForm::AForm(const std::string& name)
		: _name(name), _isSigned(false), reqSign(1), execSign(1)
{
	std::cout << "Form Constructor with Name Called" << std::endl;
}

AForm::AForm(const std::string& name, int reqSign, int execSign)
		: _name(name), _isSigned(false), reqSign(reqSign), execSign(execSign)
{
	std::cout << "Full Form Constructor Called" << std::endl;
}

AForm::AForm(const AForm &other)
		: _name(other._name), _isSigned(other._isSigned), reqSign(other.reqSign), execSign(other.execSign)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form Destructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "Form Assignment Operator Called" << std::endl;
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
	return reqSign;
}

int AForm::getExecSign() const
{
	return execSign;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >= reqSign)
		throw GradeTooLowException();
	else
		_isSigned = true;
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