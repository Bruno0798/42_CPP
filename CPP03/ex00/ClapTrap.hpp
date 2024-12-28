#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	~ClapTrap();

	//Member Functions
	void attack(const std::string& target);
	void takeDamage(int amount);
	void beRepaired(unsigned int amount);

	//Getters
	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;

	//Setters
	void setName(const std::string& name);
	void setHitPoints(int hitPoints);
	void setEnergyPoints(int energyPoints);
	void setAttackDamage(int attackDamage);
};


#endif
