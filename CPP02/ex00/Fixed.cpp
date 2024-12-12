/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:34:16 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/10 18:06:27 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default Constructor Called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &other) : _value()
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits Member Function Called" << std::endl;
	this->_value = raw;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits Member Function Called" << std::endl;
	return _value;
}
