#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	//std::cout << "MutantStack Default Constructor Called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> &other)
{
//	std::cout << "MutantStack Copy Constructor Called" << std::endl;
	*this = other;
}
template <typename T>
MutantStack<T>::~MutantStack()
{
//	std::cout << "MutantStack Destructor Called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> &other)
{
//	std::cout << "MutantStack Assignment Operator Overload" << std::endl;
	if(this != other)
		std::stack<T>::operator=(other);
	return *this;
}
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->c.end();
}
