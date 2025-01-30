#include <iostream>
#include <ctime>
#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate()
{
	int random_value = std::rand() % 3;
	if (random_value == 1)
		return new A();
	else if (random_value == 2)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (const std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (const std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (const std::exception &e)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL))); // Seed the random number generator

	Base* obj = generate();

	std::cout << "Identifying using pointer: ";
	identify(obj);

	std::cout << "Identifying using reference: ";
	identify(*obj);

	delete obj;

	return 0;
}