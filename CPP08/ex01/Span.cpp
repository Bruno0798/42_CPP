#include "Span.hpp"

Span::Span()
{
	std::cout << "Span Default Constructor Called" << std::endl;
}

Span::Span(unsigned int size) : _size(size)
{
	std::cout << "Span Constructor with value called" << std::endl;
}

Span::Span(const Span &other) : _size(other._size)
{
	std::cout << "Span Copy Constructor Called" << std::endl;
	*this = other;
}

Span::~Span()
{
	std::cout << "Span Destructor Called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
	std::cout << "Span Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		this->_cont = other._cont;
	}
	return *this;
}
