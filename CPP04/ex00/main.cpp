#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal *animal = new Animal();
		const Animal *dog = new Dog();
		const Cat *cat = new Cat();
		const Animal *catCopy = new Cat(*cat);

		std::cout << catCopy->getType();
		std::cout << std::endl;
		std::cout << "Animal class test\n" << std::endl;
		std::cout << "Animal type: " << dog->getType() << " " << std::endl;
		std::cout << "Animal type: " << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		animal->makeSound();
		std::cout << std::endl;

		delete dog;
		delete cat;
		delete animal;
	}
	{
		std::cout << std::endl;
		std::cout << "-----------------------------" << std::endl;
		std::cout << std::endl;

		const WrongAnimal *wrongAnimal = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();

		std::cout << std::endl;
		std::cout << "WrongAnimal class test\n" << std::endl;
		std::cout << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound();
		wrongAnimal->makeSound();
		std::cout << std::endl;

		delete wrongCat;
		delete wrongAnimal;
	}
	{
		std::cout << std::endl;
		std::cout << "-----------------------------" << std::endl;
		std::cout << std::endl;
		const WrongAnimal *wrongAnimal = new WrongAnimal();
		const WrongAnimal *wrongAnimalCat = new WrongCat();
		const WrongCat wrongCat;
		std::cout << std::endl;

		std::cout << "WrongCat class test\n" << std::endl;
		std::cout << wrongCat.getType() << " " << std::endl;
		wrongCat.makeSound();
		wrongAnimal->makeSound();
		wrongAnimalCat->makeSound();
		std::cout << std::endl;

		delete wrongAnimalCat;
		delete wrongAnimal;
	}
	return (0);
}