#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.id = 1;
	data.name = "Test";

	// Serialize the data
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized data: " << raw << std::endl;

	// Deserialize the data
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized data: id = " << deserializedData->id << ", name = " << deserializedData->name << std::endl;

	return 0;
}