#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

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

	std::vector<int> getVec() const;
};

#endif
