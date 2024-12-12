#include "clapTrap.hpp"


clapTrap::clapTrap()
{
	std::cout << "Default Constructor Called." << std::endl;
	_name = "empty";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

clapTrap::clapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor with name called." << std::endl;
}

clapTrap::clapTrap(const clapTrap &obj)
{
	std::cout << "Copy constructor" << std::endl;
	*this = obj;
}

clapTrap::~clapTrap()
{
	std::cout << "Destructor Called." << std::endl;
}

void clapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
	    std::cout << "ClapTrap " << _name << " cant attack, because it has no energy Points!" << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
	    std::cout << "ClapTrap " << _name << " cant attack, because it has no hitPoints!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;

	_energyPoints -= 1;
}

void clapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " received " << amount << " of damage." << std::endl;
}

void clapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " healed for " << amount << std::endl;
}
