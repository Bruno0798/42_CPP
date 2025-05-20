#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <climits>

class PmergeMe {
private:
	template <typename T> void mergeInsertion(T& container, int pair_level);
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	void sortVec(<std::vector<int>& vec);
};

template <typename T> void PmergeMe::mergeInsertion(T& container, int pair_level)
{
	typedef typename T::iterator iterator;

	if((container.size() / 2 ) < 2)
		return;
	
	if(!(container.size() % 2))
	{

	}
}

#endif
