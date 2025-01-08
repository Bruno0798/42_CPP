#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal Default Constructor Called" << std::endl;
	this->_type = "Animal";
}

AAnimal::AAnimal(const AAnimal &obj)
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = obj;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
	std::cout << "Animal Assign Operator Called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << "Animal: Animal makes a sound!" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->_type;
}

void AAnimal::setType(std::string &type)
{
	this->_type = type;
}
