#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _cont;
	public:
		Span();
		Span(unsigned int size);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		addNumber(unsigned int nb);
		shortestSpan(unsigned int nb);
		longestSpan
};

#endif
