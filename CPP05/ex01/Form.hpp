#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int reqSign;
	const int execSign;

public:
	Form();
	Form(const std::string& name, int reqSign, int execSign);
	Form(const Form &other);
	~Form();
	Form &operator=(const Form &other);

	std::string getName() const;
	bool getIsSigned() const;
	int getReqSign() const;
	int getExecSign() const;
	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &output, const Form& form);

#endif