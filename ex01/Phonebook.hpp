/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:28:58 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/12 14:11:54 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define CLEAR "\033c"
#include <iomanip>
#include "Contact.hpp"
#include <cstdlib>


class Phonebook {
private:
	Contact contacts[8];
	int	id;
public:
	Phonebook();

	void add();
	static void printContacts(const std::string &text) ;
	void printIndex(int index) const;
	void promptUser(std::string prompt, std::string &variable);
	void printTable() const;
	void search() const;
};



#endif //PHONEBOOK_HPP
