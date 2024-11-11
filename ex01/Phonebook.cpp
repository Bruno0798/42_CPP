/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:28:58 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:16:39 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

#include <iostream>

Phonebook::Phonebook()
{
	id = 0;
}

bool isOnlyLetters(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isalpha(str[i])) // Check if the character is not a letter
			return false;
	}
	return true;
}

// Function to check if the string contains only numbers
bool isOnlyNumbers(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i])) // Check if the character is not a digit
			return false;
	}
	return true;
}

void Phonebook::promtUser(std::string promt, std::string &variable)
{
	while (variable.empty() && !std::cin.eof())
	{
		std::cout << CLEAR;
		std::cout << "Creating Contact" << std::endl;
		std::cout << promt << std::endl;
		std::getline(std::cin, variable);
		if((promt == "First Name: " || promt == "Last Name: ") && !isOnlyLetters(variable))
			variable.clear();
		if((promt == "Phone Number: ") && !isOnlyNumbers(variable))
			variable.clear();
	}
}

void Phonebook::add()
{
	std::string firstName, lastName, nickName, phoneNumber, secret;

	promtUser("First Name: ", firstName);
	promtUser("Last Name: ", lastName);
	promtUser("NickName: ", nickName);
	promtUser("Phone Number: ", phoneNumber);
	promtUser("Secret: ", secret);
	if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || secret.empty())
		std::cout << CLEAR << "Contact creation failed!" << std::endl;
	else
	{
		contacts[id++ % 8] = Contact(firstName, lastName, nickName, phoneNumber, secret);
		std::cout << "\nContact Added Successfully" << std::endl;
	}
	if(std::cin.eof())
		std::cout << "Exiting...", exit(1);
	std::cout << "Press Enter to Continue!" << std::endl;
	std::cin.ignore();
}

void Phonebook::search() const
{
	int index;

	std::cout << CLEAR << "Searching Contact" << std::endl;
	if (this->id == 0)
	{
		std::cout << "No contacts!" << std::endl;
		std::cout << "Press Enter to continue" << std::endl;
		std::cin.ignore();
		return ;
	}
	printTable();
	std::cout << "Input the Index of the Contact:" << std::endl;
	std::cin >> index;
	if(std::cin.eof())
		std::cout << "Exiting...", exit(1);
	std::cin.ignore();
	if (index > 8 || index < 0 || index > id)
	{
		std::cout << "Invalid Index" << std::endl;
		std::cout << "Press Enter to continue" << std::endl;
		std::cin.ignore();
		return ;
	}
	printIndex(index -1);
	std::cin.ignore();
}

void Phonebook::printTable() const
{
	int n_contacts;

	if(this->id > 8)
		n_contacts = 8;
	else
		n_contacts = id;
	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|";

	for (int i = 0; i < n_contacts; ++i) {
		std::cout << std::endl;
		std::cout << "|     " << i + 1 << "    |";
		printContacts(contacts[i].getFirstName());
		printContacts(contacts[i].getLastName());
		printContacts(contacts[i].getNickName());
	}
	std::cout << std::endl;
}

void Phonebook::printContacts(const std::string &text)
{
	if (text.length() > 10)
		std::cout << text.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << text;
	std::cout << "|";
}

void Phonebook::printIndex(const int index) const
{
	std::cout << CLEAR;
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nick Name: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Phone Number:	" << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	std::cout << "Press Enter to continue...";
}
