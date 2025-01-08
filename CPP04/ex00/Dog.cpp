#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	_type = obj._type;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	Animal::operator=(obj);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog: bark bark" << std::endl;
}
