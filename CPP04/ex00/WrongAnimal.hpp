/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:02:07 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/28 15:12:17 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &obj);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &obj);

	std::string getType() const;
	void setType(std::string type);

	void makeSound() const;
};


#endif
