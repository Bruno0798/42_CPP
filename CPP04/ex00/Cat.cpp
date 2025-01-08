#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
//	_type = obj._type;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	Animal::operator=(obj);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat: meow meow" << std::endl;
}