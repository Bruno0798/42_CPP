/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:15:21 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/24 20:31:21 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("empty"), _hitPoints(200), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ClapTrap Default Constructor Called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Constructor with name called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : _name(obj._name), _hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints), _attackDamage(obj._attackDamage)
{
	std::cout << "ClapTrap Copy constructor" << std::endl;
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

void ClapTrap::takeDamage(int amount)
{
	if (_hitPoints > amount)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " received " << amount << " of damage. Current hit points: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " healed for " << amount << ". Current hit points: " << _hitPoints << std::endl;
}

std::string ClapTrap::getName() const
{
	return _name;
}

int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void ClapTrap::setName(const std::string& name)
{
	_name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
}