/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:20:28 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/10 18:12:24 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

//int main()
//{
//	Fixed a;
//	Fixed b(a);
//	Fixed c;
//
//	c = b;
//
//	std::cout << a.getRawBits() << std::endl;
//	std::cout << b.getRawBits() << std::endl;
//	std::cout << c.getRawBits() << std::endl;
//
//    return 0;
//}

#include <iostream>
#include "Fixed.hpp"

int main()
{
	system("clear");
	std::cout << BLUE << "Creating a default Fixed object:" << RESET << std::endl;
	Fixed a;
	std::cout << GREEN << "a.getRawBits(): " << a.getRawBits() << RESET << std::endl;
	std::cout << BLUE << "\nPress Enter to continue..." << RESET << std::endl;
	std::cin.get();  // Waits for Enter key
	system("clear");

	std::cout << BLUE << "Creating a copy of Fixed object a:" << RESET << std::endl;
	Fixed b(a);
	std::cout << GREEN << "b.getRawBits(): " << b.getRawBits() << RESET << std::endl;
	std::cout << BLUE << "\nPress Enter to continue..." << RESET << std::endl;
	std::cin.get();  // Waits for Enter key
	system("clear");

	std::cout << BLUE << "Assigning Fixed object a to a new Fixed object c:" << RESET << std::endl;
	Fixed c;
	c = a;
	std::cout << GREEN << "c.getRawBits(): " << c.getRawBits() << RESET << std::endl;
	std::cout << BLUE << "\nPress Enter to continue..." << RESET << std::endl;
	std::cin.get();  // Waits for Enter key
	system("clear");

	std::cout << BLUE << "Setting raw bits of Fixed object a to 42:" << RESET << std::endl;
	a.setRawBits(42);
	std::cout << GREEN << "a.getRawBits(): " << a.getRawBits() << RESET << std::endl;
	std::cout << BLUE << "\nPress Enter to continue..." << RESET << std::endl;
	std::cin.get();  // Waits for Enter key
	system("clear");

	std::cout << BLUE << "Creating a new Fixed object d and setting its raw bits to 100:" << RESET << std::endl;
	Fixed d;
	d.setRawBits(100);
	std::cout << GREEN << "d.getRawBits(): " << d.getRawBits() << RESET << std::endl;
	std::cout << std::endl;

	return 0;
}