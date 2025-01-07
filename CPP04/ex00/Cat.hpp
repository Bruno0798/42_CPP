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