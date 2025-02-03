#include "Array.hpp"
#include <iostream>
#include <stdexcept>

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

#include "Array.hpp"
#include <iostream>
#include <stdexcept>

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

void testDefaultConstructor() {
	std::cout << cyan << "\n►►►►►►  " << "Testing Default Constructor" << "  ◄◄◄◄◄◄" << reset << std::endl;

	Array<int> arr;

	std::cout << "Array size: " << arr.size() << std::endl;
}

void testParameterizedConstructor() {
	std::cout << cyan << "\n►►►►►►  " << "Testing Parameterized Constructor" << "  ◄◄◄◄◄◄" << reset << std::endl;

	Array<int> arr(5);

	std::cout << "Array size: " << arr.size() << std::endl;
	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
}

void testCopyConstructor() {
	std::cout << cyan << "\n►►►►►►  " << "Testing Copy Constructor" << "  ◄◄◄◄◄◄" << reset << std::endl;

	Array<int> arr1(5);

	for (unsigned int i = 0; i < arr1.size(); ++i)\
			arr1[i] = i * 2;

	Array<int> arr2(arr1);
	std::cout << "Array size: " << arr2.size() << std::endl;

	for (unsigned int i = 0; i < arr2.size(); ++i)
		std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
}

void testAssignmentOperator() {
	std::cout << cyan << "\n►►►►►►  " << "Testing Assignment Operator" << "  ◄◄◄◄◄◄" << reset << std::endl;

	Array<int> arr1(5);

	for (unsigned int i = 0; i < arr1.size(); ++i)
		arr1[i] = i * 2;

	Array<int> arr2;
	arr2 = arr1;

	std::cout << "Array size: " << arr2.size() << std::endl;

	for (unsigned int i = 0; i < arr2.size(); ++i)
		std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
}

void testOutOfBounds() {
	std::cout << cyan << "\n►►►►►►  " << "Testing Out of Bounds Access" << "  ◄◄◄◄◄◄" << reset << std::endl;
	Array<int> arr(5);

	try
	{
		std::cout << arr[10] << std::endl;
	} catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	testDefaultConstructor();
	testParameterizedConstructor();
	testCopyConstructor();
	testAssignmentOperator();
	testOutOfBounds();
	return 0;
}