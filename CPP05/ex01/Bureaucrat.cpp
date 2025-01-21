#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if(grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Assignment Operator Called" << std::endl;
	if (this != &other)
		{
			_grade = other._grade;
	}
	return *this;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::incrementGrade()
{
		if (this->getGrade() <= 1)
			throw GradeTooHighException();
		_grade--;
}
void Bureaucrat::decrementGrade()
{
	if(this->getGrade() >= 150)
		throw GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}

std::ostream& operator<<(std::ostream &ouput, const Bureaucrat& show)
{
	ouput << show.getName() << ", bureaucrat grade " << show.getGrade();
	return ouput;
}