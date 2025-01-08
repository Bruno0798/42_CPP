#ifndef CAT_HPP
#define CAT_HPP

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


#endif
