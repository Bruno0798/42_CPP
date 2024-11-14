/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:25:32 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 18:43:41 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>

#include "Weapon.hpp"


class HumanA {
private:
	Weapon &_Weapon;
	std::string _name;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};



#endif //HUMANA_HPP
