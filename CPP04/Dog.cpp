/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:54:12 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/28 12:43:09 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj) {
	std::cout << "Dog Copy Constructor Called" << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	Animal::operator=(obj);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog: bark bark" << std::endl;
}
