#include "Array.hpp"
#include <iostream>
#include <stdexcept>

int main() {
	try
	{
		Array<int> intArray(5);
		for (unsigned int i = 0; i < intArray.size(); ++i)
		{
			intArray[i] = i * 5;
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;

		Array<int> intArray2 = intArray;
		intArray2[0] = 100;
		std::cout << intArray[0] << " " << intArray2[0] << std::endl;

		Array<char> charArray(3);
		charArray[0] = 'a';
		charArray[1] = 'b';
		charArray[2] = 'c';

		std::cout << charArray[1] << std::endl;

		std::cout << "Size of intArray: " << intArray.size() << std::endl;

//		 Test out-of-bounds access
		 intArray[10] = 5;

	} catch (const std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}