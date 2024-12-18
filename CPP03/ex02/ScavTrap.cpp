#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor with name Called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap Copy constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " cant attack, because it has no energy Points!" << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " cant attack, because it has no hitPoints!" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << _name << " is now on Gate Keeper Mode." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	if(this == &obj)
		return *this;
	std::cout << "Copy assignment called" << std::endl;
	ClapTrap::operator=(obj);
	return *this;
}