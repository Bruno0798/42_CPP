#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	// std::cout << "PmergeMe Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
	// std::cout << "PmergeMe Copy Constructor Called" << std::endl;
	*this = other;
}

PmergeMe::~PmergeMe()
{
	// std::cout << "PmergeMe Destructor Called" << std::endl;
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

void PmergeMe::sortVec()
{
	void PmergeMe::sort_vec(std::vector<int>& vec) { _merge_insertion_sort<std::vector<int> >(vec, 1); }
}
