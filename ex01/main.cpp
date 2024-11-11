/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:40 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:14:58 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string input;


	while (input != "EXIT" && !std::cin.eof())
	{
		std::cout << CLEAR;
		std::cout << "***** Welcome to the PhoneBook *****" << std::endl;
		std::cout << "OPTIONS: ADD SEARCH EXIT" << std::endl;
		std::getline(std::cin, input);
		if(std::cin.eof())
			std::cout << "Exiting...", exit(1);
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if(input != "EXIT")
		{
			std::cout << CLEAR << "Wrong Command!" << std::endl << "Press Enter to Continue!" << std::endl;
			std::cin.ignore();
		}
	}
	return 0;
}
