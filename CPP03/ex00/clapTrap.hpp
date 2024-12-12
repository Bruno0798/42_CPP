#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class clapTrap
{
private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
public:
	clapTrap();
	clapTrap(const std::string& name);
	clapTrap(const clapTrap& obj);
	~clapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif
