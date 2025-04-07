#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int _size;
		std::vector<unsigned int> _cont;
	public:
		Span();
		Span(unsigned int size);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		void addNumber(unsigned int nb);
		long shortestSpan();
		long longestSpan();
		void printNumbers();

		template<typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end)
		{
			if (static_cast<unsigned long>(std::distance(begin, end)) > _size - _cont.size())
				throw NoSpaceRange();
			_cont.insert(_cont.end(), begin, end);
		}

		void setSize(unsigned int size);

		unsigned int getSize() const;

		const std::vector<unsigned int> &getCont() const;

		void setCont(const std::vector<unsigned int> &cont);

		class NoSpaceException : public std::exception
		{
			const char * what() const throw();
		};

		class NoNumbers : public std::exception
		{
			const char * what() const throw();
		};

		class NoSpaceRange : public std::exception
		{
			const char * what() const throw();
		};
};

#endif
