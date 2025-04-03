#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(MutantStack& other);
	MutantStack &operator=(MutantStack& other);

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin();
	iterator end();
};
#endif
