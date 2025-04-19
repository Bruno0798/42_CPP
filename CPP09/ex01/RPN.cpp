#include "RPN.hpp"

RPN::RPN()
{
//	std::cout << "RPN Default Constructor Called" << std::endl;
}

RPN::RPN(const RPN &other)
{
	(void) other;
//	std::cout << "RPN Copy Constructor Called" << std::endl;
}

RPN::~RPN()
{
//	std::cout << "RPN Destructor Called" << std::endl;
}

RPN &RPN::operator=(const RPN &other)
{
//	std::cout << "RPN Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		// Copy assignment operator implementation
	}
	return *this;
}

void RPN::polish(const std::string& expression)
{
	int result = 0;
	for (std::string::const_iterator it = expression.begin(); it != expression.end(); ++it)
	{
		if (std::isdigit(*it))
			_rpn.push(*it - '0'); // Convert char to int before pushing
		else
		{
			size_t n1 = _rpn.top();
			_rpn.pop();
			size_t n2 = _rpn.top();
			_rpn.pop();
			if (*it == '+')
				_rpn.push(n1 + n2);
			else if (*it == '-')
				_rpn.push(n2 - n1);
			else if (*it == '*')
				_rpn.push(n1 * n2);
			else if (*it == '/')
			{
				if(n1 == 0)
					throw MyException("inf");
				_rpn.push(n2 / n1);
			}
		}
	}
	result = _rpn.top();
	std::cout << result;
}


RPN::MyException::MyException(const std::string &msg) : message(msg)
{}

RPN::MyException::~MyException() throw() {}

const char *RPN::MyException::what() const throw()
{
	return message.c_str();
}
