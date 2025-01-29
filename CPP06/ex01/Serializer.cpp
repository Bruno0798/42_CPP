#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor Called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Serializer Copy Constructor Called" << std::endl;
	(void)other;
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destructor Called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << "Serializer Assignment Operator Called" << std::endl;
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}