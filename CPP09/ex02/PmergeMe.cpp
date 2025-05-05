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
	if (vec.size() < static_cast<size_t>(((level * 2) * 2)))
		return vec;


	if(vec.size() % 2)
	{
		buffer = vec.back();
		vec.pop_back();
	}

	for (size_t i = 0; i < vec.size(); i += level * 2)
	{
		if (vec.size() - i < static_cast<size_t>(level * 2))
			break;
		for (int j = 0; j < (level * 2) && i + j < vec.size(); ++j)
			firstElements.push_back(vec[i + j]);
		if(level == 1)
			std::sort(firstElements.begin(), firstElements.end());
		vecPairs.push_back(firstElements);
		firstElements.clear();
	}

	vec.clear();
	for (size_t i = 0; i < vecPairs.size(); ++i)
	{
		for (size_t j = 0; j < vecPairs[i].size(); ++j)
			vec.push_back(vecPairs[i][j]);
	}
	if (level != 1)
		vec = swapPairs(vec, level);

	if(buffer)
		vec.push_back(buffer);

	vec = merge(vec,level * 2);

	std::cout << "Level: " << level << std::endl;
	std::cout << "Vector Size: " << vec.size() << std::endl;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	if(level != 4)
		vec = comparePairs(vec, level);

	return vec;
}

std::vector<int> PmergeMe::comparePairs(std::vector<int> numbers, int pairSize)
{
	bool flag = false;
	std::vector<int> main;
	std::vector<int> pend;

	std::cout << "PairSize: " << pairSize << std::endl << std::endl;
	for (size_t i = 0; i + pairSize * 2 - 1 < numbers.size(); i += pairSize)
	{
		if(flag || i == 0)
		{
			for(int j = 0; j < pairSize; ++j)
			{
				main.push_back(numbers[i + j]);
				std::cout << "Number for main: " << numbers[i + j] << std::endl;
			}
		}
		else
		{
			for(int j = 0; j < pairSize; ++j)
			{
				pend.push_back(numbers[i + j]);
				std::cout << "Number for pend: " << numbers[i + j] << std::endl;
			}
		}
		flag = !flag;
	}
	
	return numbers;
}

std::vector<int> PmergeMe::swapPairs(std::vector<int> number, int pairSize)
{
	std::cout << "\nPair Size: " << pairSize << std::endl;
	std::cout << "Vector Size: " << number.size() << std::endl;

	for (size_t i = 0; i + pairSize * 2 - 1 < number.size(); i += pairSize * 2)
	{
		std::cout << "Is " << number[i + pairSize - 1] << " bigger than " << number[i + pairSize * 2 - 1] << std::endl;
		if (number[i + pairSize - 1] > number[i + pairSize * 2 - 1])
		{
			for (int j = 0; j < pairSize; ++j)
			{
				std::cout << "Swaping : " << number[i + j] << " for " << number[i + pairSize + j] << std::endl;
				std::swap(number[i + j], number[i + pairSize + j]);
			}
		}
	}
	return number;
}
