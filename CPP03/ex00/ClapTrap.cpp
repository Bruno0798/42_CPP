#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor Called." << std::endl;
	_name = "empty";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor with name called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "Copy constructor" << std::endl;
	*this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment Called" << std::endl;
	this->_name = obj._name;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	this->_hitPoints = obj._hitPoints;

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called." << std::endl;
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
