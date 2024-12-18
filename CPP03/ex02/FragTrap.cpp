#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "FragTrap Constructor with name Called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap Copy Constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap: " << this->_name << " Can I get an High Five?" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	if(this == &obj)
		return *this;
	std::cout << "Copy assignment called" << std::endl;
	ClapTrap::operator=(obj);
	return *this;
}
