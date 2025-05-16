#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>

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
	size_t countPairs() const;
	std::vector<int> bufferOddPair();
	void retreiveBuffer(std::vector<int >);
	void merge();
	void organizePair();
	void swapPairs(size_t i);
	std::vector<std::pair<std::vector<int>, std::string> > assignTags();
	void insertion();
	void split(std::vector<std::pair<std::vector<int>, std::string> >& main, std::vector<std::pair<std::vector<int>, std::string> >& pend, std::vector<std::pair<std::vector<int>, std::string> >& assign);
	std::pair<std::vector<int>, std::string> getThePair(std::vector<std::pair<std::vector<int>, std::string> >& pend, const std::string& target);
	int getJacobsthal(int k);
	std::string to_string(int value);
	void compare(std::vector<std::pair<std::vector<int>, std::string> >& main, std::pair<std::vector<int>, std::string>& target_pair, int i);
};

#endif
