#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	AAnimal test;
	{
		const int size = 10;
		AAnimal *animals[size];

		for (int i = 0; i < size / 2; ++i)
			animals[i] = new Dog();

		for (int i = size / 2; i < size; ++i)
			animals[i] = new Cat();

		for (int i = 0; i < size; ++i)
			delete animals[i];
	}
	{
		Cat* cat = new Cat();
		Cat* catCopy = new Cat(*cat);
		Dog* dog = new Dog();
		Dog* dogCopy = new Dog(*dog);

		std::cout << std::endl;
		std::cout << "Deep Copies Test" << std::endl;
		std::cout << std::endl;

		std::cout << "Cat Brain: " << cat->getBrain() << std::endl;
		std::cout << dog->getBrain() << std::endl;
		std::cout << "Copy Cat Brain: " << catCopy->getBrain() << std::endl;
		std::cout << "Copy Dog Brain: " << dogCopy->getBrain() << std::endl;

		std::cout << std::endl;
		delete cat;
		delete dog;
		delete catCopy;
		delete dogCopy;
	}
	return 0;
}