#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj), _brain(new Brain(*obj._brain))
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	if(this != &obj)
	{
		Animal::operator=(obj);
		if(_brain)
			delete _brain;
		_brain = new Brain(*obj._brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat: meow meow" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}