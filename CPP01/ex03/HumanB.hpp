/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:25:57 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 18:43:45 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <string>
#include "Weapon.hpp"

class HumanB {
private:
	Weapon *_Weapon;
	std::string _name;
public:
	HumanB();
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack();
};

#endif // HUMANB_HPP
