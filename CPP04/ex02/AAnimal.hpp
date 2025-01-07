#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal &obj);
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &obj);

	virtual void makeSound() const = 0;

	std::string getType() const;
	void setType(std::string &type);
};

#endif
