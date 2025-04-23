#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
//	std::cout << "PmergeMe Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **numbers)
{
	for (int i = 1; i < argc ; ++i)
		vec.push_back(atoi(numbers[i]));
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
//	std::cout << "PmergeMe Copy Constructor Called" << std::endl;
}

PmergeMe::~PmergeMe()
{
//	std::cout << "PmergeMe Destructor Called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
//	std::cout << "PmergeMe Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		// Copy assignment operator implementation
	}
	return *this;
}

std::vector<int> PmergeMe::getVec() const
{
	return vec;
}


std::vector<int> PmergeMe::merge(std::vector<int> vec, int level)
{
	int buffer = 0;
	std::vector<int> firstElements;
	std::vector<std::vector<int> > vecPairs;

	if (vec.size() < 2)
		return vec;

	if(vec.size() % 2)
	{
		buffer = vec.back();
		vec.pop_back();
	}
	for (size_t i = 0; i < vec.size(); i += level * 2)
	{
		for (int j = 0; j < level * 2 && i + j < vec.size(); ++j)
			firstElements.push_back(vec[i + j]);
		sort(firstElements.begin(), firstElements.end());
		vecPairs.push_back(firstElements);
		firstElements.clear();
	}

	if(buffer)
		vec.push_back(buffer);

	std::cout << "First Elements: ";
	for (size_t i = 0; i < firstElements.size(); ++i)
		std::cout << firstElements[i] << " ";
	std::cout << std::endl;
	for (size_t i = 0; i < vecPairs.size(); ++i)
	{
		std::cout << "Pair " << i + 1 << ": ";
		for (size_t j = 0; j < vecPairs[i].size(); ++j)
			std::cout << vecPairs[i][j] << " ";
		std::cout << std::endl;
	}

	return vec;
}
