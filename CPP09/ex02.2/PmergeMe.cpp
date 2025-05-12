#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
//	std::cout << "PmergeMe Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **numbers) : _pairSize(2)
{
	for(int i = 1; i < argc; ++i)
		_vec.push_back(atoi(numbers[i]));
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other; //TODO: dont forget to do this
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

void PmergeMe::printVector() const
{
	std::cout << std::endl <<"Current Vector with pairs" << std::endl;
	for(size_t i = 0; i < _vec.size(); i += _pairSize)
	{
		for(size_t j = 0; j < _pairSize; ++j)
			std::cout << _vec[i + j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void PmergeMe::organizePair()
{
	std::cout << "Pair Size: " << _pairSize << std::endl;
	std::cout << "Original vector: ";
	for (size_t k = 0; k < _vec.size(); ++k)
		std::cout << _vec[k] << " ";
	std::cout << std::endl;

	for (size_t i = 0; i < _vec.size(); i += _pairSize)
	{
		for (size_t j = i + 1; j < i + _pairSize && j < _vec.size(); ++j)
		{
			size_t k = j;
			while (k > i && _vec[k - 1] > _vec[k])
			{
				std::swap(_vec[k], _vec[k - 1]);
				--k;
			}
		}
	}
}

void PmergeMe::merge()
{
	if(_vec.size() < _pairSize)
		return ;

	int buffer = 0;
	if(_vec.size() % 2)
	{
		buffer = _vec.back();
		_vec.pop_back();
	}
	organizePair();
	printVector();
	_pairSize *= 2;
	merge();
	_vec.push_back(buffer);
}
