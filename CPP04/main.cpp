/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:48:34 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/28 15:28:35 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "Animal class test\n" << std::endl;
	std::cout << "Animal type: " << dog->getType() << " " << std::endl;
	std::cout << "Animal type: " << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animal->makeSound();

	std::cout << std::endl;
	delete dog;
	delete cat;
	delete animal;

	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;

	const	WrongAnimal* wrongAnimal = new WrongAnimal();
	const	WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "WrongAnimal class test\n" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound(); // will output the wrong cat sound
	wrongAnimal->makeSound();

	std::cout << std::endl;
	delete wrongCat;
	delete wrongAnimal;

	return (0);
}