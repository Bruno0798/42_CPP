#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
public:
	Dog();
	Dog(const Dog &obj);
	virtual ~Dog();

	Dog &operator=(const Dog &obj);
	Brain *getBrain() const;
	virtual void makeSound() const;
};

#endif
