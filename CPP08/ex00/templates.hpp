#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template<typename T>
typename T::iterator easyFind(T &a, int b)
{
	typename T::iterator it = a.begin();
	while(it != a.end())
	{
		if (*it == b)
			return it;
		++it;
	}
	throw std::invalid_argument("No such number\n");
}

#endif
