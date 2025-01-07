#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &obj) : AAnimal(obj), _brain(new Brain(*obj._brain))
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
		AAnimal::operator=(obj);
		*_brain = *obj._brain;
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