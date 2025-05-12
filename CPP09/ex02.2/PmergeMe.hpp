#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>

class PmergeMe
{
private:
	std::vector<int> _vec;
	size_t _pairSize;
public:
	PmergeMe();
	PmergeMe(int argc, char **numbers);
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	//UTILS
	void printVector() const;
	void merge();
	void organizePair();
};

#endif
