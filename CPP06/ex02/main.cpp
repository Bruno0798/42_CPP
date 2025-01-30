#include <iostream>
#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate() {
	int random_value = std::rand() % 3;
	if (random_value == 1)
		return new A();
	else if (random_value == 2)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (const std::bad_cast&) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (const std::bad_cast&) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (const std::bad_cast&) {
				// Handle error if needed
			}
		}
	}
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

	// Generate a random object
	Base* obj = generate();

	// Identify the type using pointer
	std::cout << "Identifying using pointer: ";
	identify(obj);

	// Identify the type using reference
	std::cout << "Identifying using reference: ";
	identify(*obj);

	// Clean up
	delete obj;

	return 0;
}