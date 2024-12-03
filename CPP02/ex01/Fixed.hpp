/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:21:07 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/03 16:26:02 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _value;
	static const int _bits = 8;
public:
	Fixed();
	Fixed(Fixed &cpy);
	Fixed(int number);
	Fixed(float number);
	~Fixed();

	Fixed &operator=(const Fixed &obj);
	void setRawBits(int raw);
	int getRawBits() const;
	int toInt() const;
	float toFloat() const;

};


#endif
