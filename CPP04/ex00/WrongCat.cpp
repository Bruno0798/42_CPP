/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:20:09 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/28 15:27:45 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor Called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat Operator Assign Called" << std::endl;
	WrongAnimal::operator=(obj);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat: meow meow" << std::endl;
}