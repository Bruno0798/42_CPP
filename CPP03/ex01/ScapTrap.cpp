#include "ScapTrap.hpp"

#include <iostream>

ScapTrap::ScapTrap() : ClapTrap()
{
	std::cout << "ScapTrap Default Constructor Called" << std::endl;
	this->_hitPoints = 100;
}

ScapTrap::ScapTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScapTrap Constructor with name Called" << std::endl;
	this->_hitPoints = 100;
}

ScapTrap::ScapTrap(const ScapTrap &obj)
{
	std::cout << "ScapTrap Copy constructor" << std::endl;
	*this = obj;
}

ScapTrap::~ScapTrap()
{
	std::cout << "ScapTrap Destructor Called" << std::endl;
}