/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:25:32 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 18:52:35 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _Weapon(weapon), _name(name)
{}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}
