/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:55:48 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/28 12:42:56 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	Animal::operator=(obj);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat: meow meow" << std::endl;
}