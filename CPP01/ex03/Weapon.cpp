/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:21:46 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 18:30:48 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon()
{

}

std::string Weapon::getType()
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

