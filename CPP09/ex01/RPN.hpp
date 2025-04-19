#ifndef RPN_H
#define RPN_H

#include <iostream>

class RPN
{
private:
	std::stack<int> _rpn;
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	void polish(const std::string& expression);

	class MyException : public std::exception
	{
	private:
		std::string message;
	public:
		MyException(const std::string &msg);
		virtual ~MyException() throw();
		virtual const char *what() const throw();
	};
};

#endif
