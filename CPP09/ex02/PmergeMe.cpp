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


std::vector<int> PmergeMe::mergeSort(std::vector<int> a)
{
	if (a.size() == 1)
		return a;

	size_t mid = a.size() / 2;
	std::vector<int> left(a.begin(), a.begin() + mid);
	std::vector<int> right(a.begin() + mid, a.end());

	left = mergeSort(left);
	right = mergeSort(right);

	vec = merge(left, right);
	return merge(left, right);
}


std::vector<int> PmergeMe::merge(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> c;
	while (!a.empty() && !b.empty())
	{
		if (a.front() <= b.front())
		{
			c.push_back(a.front());
			a.erase(a.begin());
		}
		else
		{
			c.push_back(b.front());
			b.erase(b.begin());
		}
	}
	c.insert(c.end(), a.begin(), a.end());
	c.insert(c.end(), b.begin(), b.end());

	return c;
}
