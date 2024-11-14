/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:25:57 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 18:42:38 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : _Weapon(nullptr) {}

HumanB::HumanB(std::string name) : _Weapon(nullptr), _name(name) {}

HumanB::HumanB(std::string name, Weapon &weapon) : _Weapon(&weapon), _name(name) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
	_Weapon = &weapon;
}

void HumanB::attack() {
	if (_Weapon) {
		std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
	} else {
		std::cout << _name << " has no weapon to attack with!" << std::endl;
	}
}
