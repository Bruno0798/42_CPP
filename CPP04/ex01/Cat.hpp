#ifndef CPP04_CAT_HPP
#define CPP04_CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* _brain;
public:
	Cat();
	Cat(const Cat &obbj);
	virtual ~Cat();

	Cat &operator=(const Cat &obj);
	Brain* getBrain() const;

	virtual void makeSound() const;
};


#endif //CPP04_CAT_HPP
