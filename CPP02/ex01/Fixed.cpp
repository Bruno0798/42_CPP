/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:21:07 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/03 17:07:40 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(const int number) : _value(number << _value)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(number * (1 << _bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	if (this == &obj)
		return *this;

	std::cout << "Copy assignment called" << std::endl;
	_value = obj.getRawBits();
	return *this;
}


void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _bits);
}

int Fixed::toInt() const
{
	return _value >> _bits;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}