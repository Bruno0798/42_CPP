#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _reqSign;
	const int _execSign;
	const std::string _target;

public:
	AForm();
	AForm(const std::string& name, int reqSign, int execSign, const std::string& target);
	AForm(const AForm &other);
	~AForm();
	AForm &operator=(const AForm &other);

	std::string getName() const;
	bool getIsSigned() const;
	int getReqSign() const;
	int getExecSign() const;
	std::string getTarget() const;
	void execute(Bureaucrat const& executor) const;

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

std::ostream& operator<<(std::ostream &output, const AForm& form);

#endif