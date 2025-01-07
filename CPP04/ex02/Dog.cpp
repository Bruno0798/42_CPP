#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &obj) : AAnimal(obj), _brain(new Brain(*obj._brain))
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	if(this != &obj)
	{
		AAnimal::operator=(obj);
		*_brain = *obj._brain;
	}
	return *this;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "Dog: bark bark" << std::endl;
}
