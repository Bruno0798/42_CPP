#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span()
{
//	std::cout << "Span Default Constructor Called" << std::endl;
}

Span::Span(unsigned int size) : _size(size)
{
//	std::cout << "Span Constructor with value called" << std::endl;
}

Span::Span(const Span &other) : _size(other._size)
{
//	std::cout << "Span Copy Constructor Called" << std::endl;
	*this = other;
}

Span::~Span()
{
//	std::cout << "Span Destructor Called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
//	std::cout << "Span Assignment Operator Called" << std::endl;
	if (this != &other)
		this->_cont = other._cont;
	return *this;
}

void Span::addNumber(unsigned int nb)
{
	if(_cont.size() == _size)
		throw NoSpaceException();
	_cont.push_back(nb);
}

long Span::shortestSpan()
{
	if(_cont.size() < 2)
		throw NoNumbers();
	std::vector<unsigned int> numbers = _cont;
	std::sort(numbers.begin(), numbers.end());

	long minSpan = LONG_MAX;
	for (size_t i = 1; i < numbers.size(); ++i)
	{
		long span = numbers.at(i) - numbers.at(i - 1);
		if(span < minSpan)
			minSpan = span;
	}

	return minSpan;
}

long Span::longestSpan()
{
	if(_cont.size() < 2)
		throw NoNumbers();

	std::vector<unsigned int> numbers = _cont;
	std::sort(numbers.begin(), numbers.end());

	long maxSpan = 0;
	for (unsigned int i = 1; i < numbers.size(); ++i)
	{
		long span = numbers.at(i) - numbers.at(i - 1);
		if(span > maxSpan)
			maxSpan = span;
	}
	return maxSpan;
}

void Span::setSize(unsigned int size)
{
	_size = size;
}

unsigned int Span::getSize() const
{
	return _size;
}

void Span::printNumbers()
{
	for (size_t i = 0; i < _cont.size(); ++i)
		std::cout << _cont[i] << " ";
	std::cout << std::endl;
}

const std::vector<unsigned int> &Span::getCont() const
{
	return _cont;
}

void Span::setCont(const std::vector<unsigned int> &cont)
{
	_cont = cont;
}

const char *Span::NoSpaceException::what() const throw()
{
	return "No Space left";
}

const char *Span::NoNumbers::what() const throw()
{
	return "Not enough numbers";
}

const char *Span::NoSpaceRange::what() const throw()
{
	return "Not enough numbers to perform this action";
}
