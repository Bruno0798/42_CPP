#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
//	std::cout << "PmergeMe Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **numbers) : _pairSize(1)
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

int PmergeMe::getJacobsthal(int k)
{
	return (static_cast<int>(pow(2, k + 1)) + (k % 2 == 0 ? 1 : -1)) / 3;
}


void PmergeMe::printVector() const
{
	std::cout << std::endl << "Current Vector with pairs" << std::endl;
	for (size_t i = 0; i < _vec.size(); i += _pairSize)
	{
		for (size_t j = 0; j < _pairSize && (i + j) < _vec.size(); ++j)
			std::cout << _vec[i + j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}


void PmergeMe::swapPairs(size_t start)
{
	if (start + (_pairSize + 1) * 2 >= _vec.size())
	{
		if(_pairSize != 1)
			return;
		else
		{
			std::vector<int	> aux;
			aux.push_back(_vec[start]);
			_vec[start] = _vec[start + 1];
			_vec[start + 1] = aux[0];
			aux.pop_back();
			return;
		}
	}
	std::vector<int	> aux;
	for (size_t i = start; i != start + _pairSize; ++i)
	{
		aux.push_back(_vec[i]);
		_vec[i] = _vec[i + _pairSize];
		_vec[i + _pairSize] = aux[0];
		aux.pop_back();
	}
	std::cout << std::endl;
}

void PmergeMe::organizePair()
{

	for (size_t i = _pairSize - 1; i < _vec.size() || i + i + _pairSize * 2 < _vec.size(); i += (_pairSize * 2))
	{
		if (_vec[i] > _vec[i + _pairSize])
			swapPairs((i + 1) - _pairSize);
	}
}

std::vector<std::pair<std::vector<int>, std::string> > PmergeMe::assignTags()
{
	std::vector<std::pair<std::vector<int>, std::string> > result;
	int bCount = 1;
	int aCount = 1;
	size_t i = 0;

	while (i < _vec.size())
	{
		std::vector<int> pair;
		for (size_t j = 0; j < _pairSize && i < _vec.size(); ++j, ++i)
			pair.push_back(_vec[i]);

		std::string label = (result.size() % 2 == 0)
			? "b" + to_string(bCount++)
			: "a" + to_string(aCount++);

		result.push_back(std::make_pair(pair, label));
	}
	return result;
}

void PmergeMe::split(std::vector<std::pair<std::vector<int>,
	std::string> >& main, std::vector<std::pair<std::vector<int>,
	std::string> >& pend, std::vector<std::pair<std::vector<int>, std::string> >& assign)
{
	for (size_t i = 0; i < assign.size(); ++i) {
		const std::pair<std::vector<int>, std::string>& pair = assign[i];
		const std::string& label = pair.second;

		if (label == "b1" || label == "a1" || label[0] == 'a')
			main.push_back(pair);
		else
			pend.push_back(pair);
	}
}

std::pair<std::vector<int>, std::string> PmergeMe::getThePair(
	std::vector<std::pair<std::vector<int>, std::string> >& pend,
	const std::string& target)
{
	std::pair<std::vector<int>, std::string> target_pair;
	size_t index_to_remove = pend.size();
	std::string closest_lower = "";

	for (size_t i = 0; i < pend.size(); ++i)
	{
		const std::string& current = pend[i].second;

		if (current == target)
		{
			target_pair = pend[i];
			index_to_remove = i;
			break;
		}
		if (current < target && (closest_lower == "" || current > closest_lower))
		{
			closest_lower = current;
			target_pair = pend[i];
			index_to_remove = i;
		}
	}

	if (index_to_remove < pend.size())
		pend.erase(pend.begin() + index_to_remove);

//	for (size_t j = 0; j < target_pair.first.size(); ++j)
//		std::cout << target_pair.first[j] << " ";
//	std::cout << std::endl;

	return target_pair;
}

std::string PmergeMe::to_string(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

void PmergeMe::compare(std::vector<std::pair<std::vector<int>, std::string> > &main,std::pair<std::vector<int>, std::string>& target_pair, int i)
{
	std::cout << "Compare function received i in position :" << main[i].second << std::endl;
	for (int j = i; j >= 0 && target_pair.first.back() < main[i].first.back(); --j)
	{
		std::cout << "Looking for numbers lower than target, currently :" << main[i].second << std::endl;
		i--;
	}
	std::cout << "After looking for closes number found :" << main[i + 1].second << std::endl;
	main.insert(main.begin() + i + 1,target_pair);
	std::cout << "\nMAIN AFTER INSERTION:\n";
	for (size_t i = 0; i < main.size(); ++i)
	{
		std::cout << main[i].second << ": ";
		for (size_t j = 0; j < main[i].first.size(); ++j)
			std::cout << main[i].first[j] << " ";
		std::cout << "\n";
	}
}

void PmergeMe::insertion()
{
	std::vector<std::pair<std::vector<int>, std::string> > main;
	std::vector<std::pair<std::vector<int>, std::string> > pend;
	std::vector<std::pair<std::vector<int>, std::string> > assign = assignTags();

	split(main, pend, assign);

	std::cout << "MAIN:\n";
	for (size_t i = 0; i < main.size(); ++i)
	{
		std::cout << main[i].second << ": ";
		for (size_t j = 0; j < main[i].first.size(); ++j)
			std::cout << main[i].first[j] << " ";
		std::cout << "\n";
	}

	std::cout << "\nPEND:\n";
	for (size_t i = 0; i < pend.size(); ++i)
	{
		std::cout << pend[i].second << ": ";
		for (size_t j = 0; j < pend[i].first.size(); ++j)
			std::cout << pend[i].first[j] << " ";
		std::cout << "\n";
	}
	std::cout << std::endl;

	int jacobsthal = 2;
	size_t current_jacobsthal = getJacobsthal(jacobsthal);
	size_t previous_jacobsthal = getJacobsthal(jacobsthal - 1);
	std::pair<std::vector<int>, std::string> target_pair;

	while (current_jacobsthal - previous_jacobsthal <= pend.size())
	{
		for (size_t j = current_jacobsthal - previous_jacobsthal; j != 0; --j)
		{
			std::cout << "Number of movements left " << j << std::endl;
			std::string target = "b" + to_string(current_jacobsthal);
			target_pair = getThePair(pend, target);
			std::cout << "Current target is " << target_pair.second << std::endl << std::endl;
			for (size_t i = 0; i < main.size(); ++i)
			{
				std::cout << "Currently searching " << main[i].second << std::endl << std::endl;
				std::cout << "Target comparing is: " << target_pair.second[target_pair.second.size() - 1] - 1 << std::endl << std::endl;
				if (main[i].second[main[i].second.size() - 1] == target_pair.second[target_pair.second.size() - 1] - 1)
				{
					if (main[i + 1].second.empty())
					{
						std::cout << "No a" << target_pair.second[target_pair.second.size()] << " found" << std::endl;
						compare(main, target_pair, i);
					}
					else
					{
						std::cout << "Found a" << target_pair.second[target_pair.second.size() - 1] << std::endl;
						compare(main,target_pair, i + 1);
					}
					break;
				}
			}
		}
		jacobsthal++;
		previous_jacobsthal = current_jacobsthal;
		current_jacobsthal = getJacobsthal(jacobsthal);
		std::cout << "Jacobsthal: " << current_jacobsthal << std::endl;
	}
	while(!pend.empty())
	{
		std::pair<std::vector<int>, std::string> target_pair = pend.back();
		pend.pop_back();
		compare(main, target_pair, main.size() - 1);
	}
	_vec.clear();
	for (size_t i = 0; i < main.size(); ++i)
	{
		for (size_t j = 0; j < main[i].first.size(); ++j)
			_vec.push_back(main[i].first[j]);
	}

	std::cout << "MAIN AFTER FINISHING WITH THESE PAIRS" << std::endl;
	for (size_t i = 0; i < main.size(); ++i)
	{
		std::cout << main[i].second << ": ";
		for (size_t j = 0; j < main[i].first.size(); ++j)
			std::cout << main[i].first[j] << " ";
		std::cout << "\n";
	}

}

size_t PmergeMe::countPairs() const
{
	size_t count = 0;
	for (size_t i = 0; i < _vec.size();i += _pairSize)
		count++;
	return count;
}

std::vector<int> PmergeMe::bufferOddPair()
{
	size_t remainder = _vec.size() % _pairSize;

	std::vector<int > buffer;
	if (remainder > 0)
	{
		buffer.insert(buffer.end(), _vec.end() - remainder, _vec.end());
		_vec.erase(_vec.end() - remainder, _vec.end());
	}
	return buffer;
}

void PmergeMe::retreiveBuffer(std::vector<int> buffer)
{
	for (size_t i = 0; i < buffer.size(); ++i)
	{
		_vec.push_back(buffer[i]);
	}
}


void PmergeMe::merge()
{
	if(_vec.size() <= (_pairSize * 2))
		return ;

	printVector();
	organizePair();
	std::vector<int> buffer = bufferOddPair();
	_pairSize *= 2;
	merge();
	_pairSize /= 2;
	insertion();
	if (!buffer.empty())
		retreiveBuffer(buffer);
	printVector();
}
