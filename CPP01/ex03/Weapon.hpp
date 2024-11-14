/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:21:46 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 18:25:06 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>


class Weapon {
private:
	std::string _type;
public:
	Weapon(std::string type);
	~Weapon();
	std::string getType();
	void setType(std::string type);
};



#endif
