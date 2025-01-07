#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const int size = 10;
		Animal *animals[size];

		for (int i = 0; i < size / 2; ++i)
			std::cout << i + 1 << " ", animals[i] = new Dog(), std::cout << std::endl;

		for (int i = size / 2; i < size; ++i)
			std::cout << i + 1 << " ", animals[i] = new Cat(), std::cout << std::endl;

		for (int i = 0; i < size; ++i)
			delete animals[i], std::cout << std::endl;
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
		std::cout << "Copy Cat Brain: " << dogCopy->getBrain() << std::endl;

		std::cout << std::endl;
		delete cat;
		delete dog;
		delete catCopy;
		delete dogCopy;
	}
	return 0;
}