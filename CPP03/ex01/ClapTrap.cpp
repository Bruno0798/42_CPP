#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor Called." << std::endl;
	_name = "empty";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Constructor with name called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called." << std::endl;
}

void ClapTrap::attack(const std::string &target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " received " << amount << " of damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " healed for " << amount << std::endl;
}
