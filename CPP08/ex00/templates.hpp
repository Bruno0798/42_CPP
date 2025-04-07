#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyFind(T &a, int b)
{
	typename T::iterator it = std::find(a.begin(), a.end(), b);
	if (it != a.end())
		return it;
	throw std::invalid_argument("No such number\n");
}

#endif
