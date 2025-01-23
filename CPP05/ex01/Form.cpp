#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
		: _name("Default"), _isSigned(false), reqSign(1), execSign(1)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(const std::string& name, int reqSign, int execSign)
		: _name(name), _isSigned(false), reqSign(reqSign), execSign(execSign)
{
	std::cout << "Full Form Constructor Called" << std::endl;
	if (getReqSign() < 1 || getExecSign() < 1)
		throw GradeTooHighException();
	if (getReqSign() > 150 || getExecSign() > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
		: _name(other._name), _isSigned(other._isSigned), reqSign(other.reqSign), execSign(other.execSign)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor Called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form Assignment Operator Called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getReqSign() const
{
	return reqSign;
}

int Form::getExecSign() const
{
	return execSign;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >= reqSign)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too High!\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too Low!\n";
}

std::ostream& operator<<(std::ostream &output, const Form& form)
{
	output << "Form: " << form.getName()
		   << " needs " << form.getReqSign()
		   << " to be signed and " << form.getExecSign()
		   << " to execute, status: "
		   << (form.getIsSigned() ? "Signed" : "Unsigned");
	return output;
}