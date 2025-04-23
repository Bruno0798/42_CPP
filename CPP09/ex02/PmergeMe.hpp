#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>

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

	std::vector<int> mergeSort(std::vector<int> a);
	std::vector<int> merge(std::vector<int> a, std::vector<int> b);

	std::vector<int> getVec() const;
};

#endif
