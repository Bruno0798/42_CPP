/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:51:51 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/28 12:46:28 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string _type;
public:
	Animal();
	Animal(const Animal &obj);
	virtual ~Animal();

	Animal &operator=(const Animal &obj);

	virtual void makeSound() const;

	std::string getType() const;
	void setType(std::string &type);
};


#endif
