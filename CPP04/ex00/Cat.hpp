/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:55:48 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/28 12:37:46 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_CAT_HPP
#define CPP04_CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &obbj);
	virtual ~Cat();

	Cat &operator=(const Cat &obj);

	virtual void makeSound() const;
};


#endif //CPP04_CAT_HPP
