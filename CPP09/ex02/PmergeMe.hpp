#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

class PmergeMe
{
private:
	std::vector<int> vec;
public:
	PmergeMe();
	PmergeMe(int argc, char **numbers);
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	std::vector<int> merge(std::vector<int> vec, int level);

	std::vector<int> swapPairs(std::vector<int> number, int pairSize);

	std::vector<int> comparePairs(std::vector<int> numbers, int pairSize);

	int getJacobsthal(int k);

	std::vector<int> getVec() const;
};

#endif
