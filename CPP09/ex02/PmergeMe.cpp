#include "PmergeMe.hpp"

int PmergeMe::comparisons = 0;

PmergeMe::PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe& pm)
{
	(void)pm;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& pm)
{
	(void)pm;
	return *this;
}
PmergeMe::~PmergeMe()
{

}

long jacobsthalNumber(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }

void PmergeMe::sort_vec(std::vector<int>& vec)
{
        mergeInsertion(vec, 1);
}

void PmergeMe::sort_deque(std::deque<int>& deque)
{
	mergeInsertion<std::deque<int> >(deque, 1);
}
