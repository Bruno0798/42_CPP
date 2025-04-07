#include <cstdlib>
#include "Span.hpp"
#include <vector>

void fillContainer(Span& container)
{
	std::vector<unsigned int> numbers;
	for (size_t i = 0; i < container.getSize(); ++i)
		numbers.push_back(rand() % 1000 + 1);

	container.addNumbers(numbers.begin(), numbers.end());

	std::cout << "Container filled with: " << std::endl;
	container.printNumbers();
}

void testEmptyContainer()
{
	std::cout << "\nTEST: Empty Container" << std::endl << std::endl;
	try
	{
		Span container(5);

		std::cout << "Shortest Span: " << container.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Span container(5);

		std::cout << "Longest Span: " <<  container.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testOverflowContainer()
{
	std::cout << "\nTEST: Overflow Container" << std::endl << std::endl;
	try
	{
		Span container(5);
		fillContainer(container);
		container.addNumber(10);
		std::cout << "Shortest Span: " << container.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Span container(5);
		fillContainer(container);
		container.addNumber(10);
		std::cout << "Longest Span: " <<  container.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testSingleElement()
{
	std::cout << "TEST: Single Element" << std::endl << std::endl;
	try
	{
		Span container(5);
		container.addNumber(1);
		std::cout << "Shortest Span: " << container.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Span container(5);
		container.addNumber(1);
		std::cout << "Longest Span: " <<  container.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testFullContainer()
{
	try
	{
		std::cout << "\nTEST: Full Container" << std::endl << std::endl;
		Span container(20000);
		fillContainer(container);

		std::cout << "Shortest Span: " << container.shortestSpan() << std::endl;
		std::cout << "Longest Span: " <<  container.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testDuplicateNumbers()
{
	std::cout << "\nTEST: Duplicate Numbers" << std::endl << std::endl;
	try
	{
		Span container(3);
		container.addNumber(10);
		container.addNumber(10);
		container.addNumber(10);
		std::cout << "Shortest Span: " << container.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << container.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testMixedNumbers()
{
	std::cout << "\nTEST: Mixed Numbers" << std::endl << std::endl;
	try
	{
		Span container(5);
		container.addNumber(-10);
		container.addNumber(20);
		container.addNumber(-30);
		container.addNumber(40);
		std::cout << "Shortest Span: " << container.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << container.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	srand(time(0));
	testSingleElement();
	testOverflowContainer();
	testEmptyContainer();
	testFullContainer();
	testDuplicateNumbers();
	testMixedNumbers();
	return 0;
}
