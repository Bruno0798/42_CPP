#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <climits>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class PmergeMe
{
private:
	template <typename T> void mergeInsertion(T& container, int pairSize);
	template <typename T> void swapPair(T it, int pair_level);
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	static int comparisons;
	void sort_vec(std::vector<int>& vec);
	void sort_deque(std::deque<int>& deque);
};

long jacobsthalNumber(long n);

template <typename T> bool comparePairs(T pairOne, T pairTwo)
{
	PmergeMe::comparisons++;
	return *pairOne < *pairTwo;
}

template <typename T> T next(T it, int steps)
{
	std::advance(it, steps);
	return it;
}

template <typename T> void PmergeMe::swapPair(T it, int pair_level)
{
	T start = next(it, -pair_level + 1);
	T end = next(start, pair_level);
	while (start != end)
	{
		std::iter_swap(start, next(start, pair_level));
		start++;
	}
}

template <typename Iterator, typename T, typename Compare>
Iterator binarySearch(Iterator first, Iterator last, const T& value, Compare comp)
{
	while (first < last)
	{
		Iterator mid = first + (last - first) / 2;
		if (!comp(value, *mid))
			first = mid + 1;
		else
			last = mid;
	}
	return first;
}

template <typename T>
void printContainer(const T& container)
{
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T> void PmergeMe::mergeInsertion(T& container, int pairSize)
{
	typedef typename T::iterator Iterator;

	int numberPairs = container.size() / pairSize;
	if (numberPairs < 2)
		return;

	bool oddPair = numberPairs % 2 == 1;
	Iterator start = container.begin();
	Iterator last = next(container.begin(), pairSize * (numberPairs));
	Iterator end = next(last, -(oddPair * pairSize));

	int increment = 2 * pairSize;
	for (Iterator it = start; it != end; std::advance(it, increment))
	{
		Iterator this_pair = next(it, pairSize - 1);
		Iterator next_pair = next(it, pairSize * 2 - 1);
		if (comparePairs(next_pair, this_pair))
			swapPair(this_pair, pairSize);
	}
	mergeInsertion(container, pairSize * 2);

	std::vector<Iterator > main;
	std::vector<Iterator > pend;

	main.insert(main.end(), next(container.begin(), pairSize - 1));
	main.insert(main.end(), next(container.begin(), pairSize * 2 - 1));

	for (int i = 4; i <= numberPairs; i += 2)
	{
		pend.insert(pend.end(), next(container.begin(), pairSize * (i - 1) - 1));
		main.insert(main.end(), next(container.begin(), pairSize * i - 1));
	}

	if(oddPair)
		pend.insert(pend.end(), next(end,pairSize - 1));

	int prev_jacobsthal = jacobsthalNumber(1);
	int inserted_numbers = 0;
	for (int k = 2;; k++)
	{
		int curr_jacobsthal = jacobsthalNumber(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;
		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break;
		int nbr_of_times = jacobsthal_diff;
		typename std::vector<Iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
		typename std::vector<Iterator>::iterator bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers);
		while (nbr_of_times)
		{
			typename std::vector<Iterator>::iterator idx = binarySearch(main.begin(), bound_it, *pend_it, comparePairs<Iterator>);
			typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
			nbr_of_times--;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);
			offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
		}
		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
	}

	for (ssize_t i = pend.size() - 1; i >= 0; i--)
	{
		typename std::vector<Iterator>::iterator curr_pend = next(pend.begin(), i);
		typename std::vector<Iterator>::iterator curr_bound = next(main.begin(), main.size() - pend.size() + i + oddPair);
		typename std::vector<Iterator>::iterator idx = binarySearch(main.begin(), curr_bound, *curr_pend, comparePairs<Iterator>);
		main.insert(idx, *curr_pend);
	}

	std::vector<int> copy;
	copy.reserve(container.size());
	for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (int i = 0; i < pairSize; i++)
		{
			Iterator pair_start = *it;
			std::advance(pair_start, -pairSize + i + 1);
			copy.insert(copy.end(), *pair_start);
		}
	}

	//REPLACING ORIGINAL VECTOR WITH THE NEW ORDER
	Iterator container_it = container.begin();
	std::vector<int>::iterator copy_it = copy.begin();
	while (copy_it != copy.end())
	{
		*container_it = *copy_it;
		container_it++;
		copy_it++;
	}

}

#endif
