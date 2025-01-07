#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = "Default idea";

}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = obj.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	if (this != &obj)
		for (int i = 0; i < 100; ++i)
			ideas[i] = obj.ideas[i];
	return *this;
}