/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:13:22 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/12 14:09:29 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	firstName = first;
	lastName = last;
	nickName = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

// Setters
void Contact::setFirstName(const std::string &first)
{
    this->firstName = first;
}

void Contact::setLastName(const std::string &last)
{
    this->lastName = last;
}

void Contact::setNickname(const std::string &nick)
{
    this->nickName = nick;
}

void Contact::setPhoneNumber(const std::string &phone)
{
    this->phoneNumber = phone;
}

void Contact::setDarkestSecret(const std::string &secret)
{
    this->darkestSecret = secret;
}

//Getters
std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickName() const
{
	return nickName;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}

