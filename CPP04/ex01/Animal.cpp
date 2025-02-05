#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default Constructor Called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = obj;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Animal Assign Operator Called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal: Animal makes a sound!" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::setType(std::string &type)
{
	this->_type = type;
}