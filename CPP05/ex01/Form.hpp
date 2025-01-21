#ifndef FORM_H
#define FORM_H

#include <iostream>

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int reqSign;
	const int execSign;
public:
	Form();
	Form(std::string name);
	Form(std::string name, bool  isSigned, int reqSign, int execSign);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	//Getters
	std::string getName() const;
	bool getIsSigned() const;
	int getReqSign() const;
	int getExecSign() const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	;class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream & operator<<(std::ostream &output, const Form& show);

#endif