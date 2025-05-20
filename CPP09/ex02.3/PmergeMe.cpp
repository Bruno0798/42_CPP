#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // std::cout << "PmergeMe Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(char** argv, int argc) : _pairSize(1)
{
    for (int i = 1; i < argc; ++i)
        _vec.push_back(std::atoi(argv[i]));
}


PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
    // std::cout << "PmergeMe Copy Constructor Called" << std::endl;
    *this = other;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "PmergeMe Destructor Called" << std::endl;
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
    std::cout << std::endl << "Current Vector with pairs" << std::endl;
    for (size_t i = 0; i < _vec.size(); i += _pairSize)
    {
        for (size_t j = 0; j < _pairSize && (i + j) < _vec.size(); ++j)
            std::cout << _vec[i + j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

int PmergeMe::getJacobsthal(int k)
{
    return (static_cast<int>(pow(2, k + 1)) + (k % 2 == 0 ? 1 : -1)) / 3;
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
}

void PmergeMe::organizePairs()
{
    for (size_t i = _pairSize - 1; i < _vec.size() || i + i + _pairSize * 2 < _vec.size(); i += (_pairSize * 2))
    {
        if (!(i >= _vec.size() || i + _pairSize >= _vec.size()))
        {
            if (_vec[i] > _vec[i + _pairSize])
                swapPairs((i + 1) - _pairSize);
        }
    }
}

std::string PmergeMe::to_string(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
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
        std::string label = (result.size() % 2 == 0) ? "b" + to_string(bCount++) : "a" + to_string(aCount++);
        result.push_back(std::make_pair(pair, label));
    }
    return result;
}

void PmergeMe::split(std::vector<std::pair<std::vector<int>,
    std::string> >& main, std::vector<std::pair<std::vector<int>,
    std::string> >& pend, std::vector<std::pair<std::vector<int>, std::string> >& assign)
{
    for (size_t i = 0; i < assign.size(); ++i)
    {
        const std::pair<std::vector<int>, std::string>& pair = assign[i];
        const std::string& label = pair.second;

        if (label == "b1" || label == "a1" || label[0] == 'a')
            main.push_back(pair);
        else
            pend.push_back(pair);
    }
}

std::pair<std::vector<int>, std::string> PmergeMe::getThePair(std::vector<std::pair<std::vector<int>, std::string> >& pend, const std::string& target)
{
    std::pair<std::vector<int>, std::string> target_pair;
    size_t index_to_remove = pend.size();
    std::string closest_lower;

    for (size_t i = 0; i < pend.size(); ++i)
    {
        const std::string& current = pend[i].second;

        if (current == target)
        {
            target_pair = pend[i];
            index_to_remove = i;
            break;
        }
        if (current < target && (closest_lower.empty() || current > closest_lower))
        {
            closest_lower = current;
            target_pair = pend[i];
            index_to_remove = i;
        }
    }
    if (index_to_remove < pend.size())
        pend.erase(pend.begin() + index_to_remove);
    return target_pair;
}

void PmergeMe::splitAndInsert()
{
    std::vector<std::pair<std::vector<int>, std::string> > assign = assignTags();
    std::vector<std::pair<std::vector<int>, std::string> > main;
    std::vector<std::pair<std::vector<int>, std::string> > pend;

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

    std::cout << std::endl;
    int jacobsthal = 2;
    size_t curr_jacob = getJacobsthal(jacobsthal);
    size_t prev_jacob = getJacobsthal(jacobsthal - 1);
    std::pair<std::vector<int>, std::string> target_pair;

    while (curr_jacob - prev_jacob <= pend.size())
    {
        for (size_t j = curr_jacob - prev_jacob; j != 0; --j)
        {
            std::string target = "b" + to_string(curr_jacob);
            target_pair = getThePair(pend, target);
            for (size_t i = 0; i < main.size(); ++i)
            {
                int target_num = 0;
                if (!target_pair.second.empty())
				{
                    size_t start_pos = 0;
                    while (start_pos < target_pair.second.size() && 
                           !isdigit(target_pair.second[start_pos]))
                        start_pos++;

                    if (start_pos < target_pair.second.size())
					{
                        std::string target_num_str = target_pair.second.substr(start_pos);
                        std::stringstream target_ss(target_num_str);
                        if (!(target_ss >> target_num))
                            target_num = 0;
                    }
                }

                // Extract the numerical part of main[i].second with robust safety checks
                int main_num = 0;
                if (!main[i].second.empty())
				{
                    size_t start_pos = 0;
                    while (start_pos < main[i].second.size() && !isdigit(main[i].second[start_pos]))
                        start_pos++;
                    
                    if (start_pos < main[i].second.size())
					{
                        std::string main_num_str = main[i].second.substr(start_pos);
                        std::stringstream main_ss(main_num_str);
                        if (!(main_ss >> main_num))
                            main_num = 0;
                    }
                }
				if (main_num == target_num - 1)
				{
					if (i + 1 >= main.size() || main[i + 1].second.empty())
						compare(main, target_pair, i);
					else
						compare(main,target_pair, i + 1);
					break;
				}
            }
        }
        jacobsthal++;
        prev_jacob = curr_jacob;
        curr_jacob = getJacobsthal(jacobsthal);
    }
	while(!pend.empty())
    {
	    size_t min_idx = 0;
	    int min_value = INT_MAX;

	    for (size_t i = 0; i < pend.size(); i++)
	    {
	        if (!pend[i].first.empty() && pend[i].first.back() < min_value)
		    {
	            min_value = pend[i].first.back();
	            min_idx = i;
	        }
	    }
	    std::pair<std::vector<int>, std::string> target_pair = pend[min_idx];
	    pend.erase(pend.begin() + min_idx);
	    compare(main, target_pair, main.size() - 1);
    }
	_vec.clear();
	for (size_t i = 0; i < main.size(); ++i) {
		for (size_t j = 0; j < main[i].first.size(); ++j)
			_vec.push_back(main[i].first[j]);
	}

	// // Final verification pass - perform an insertion sort to ensure everything is ordered
	// // This is a safety check that ensures we end with a completely sorted sequence
	// for (size_t i = 1; i < _vec.size(); ++i) {
	// 	int key = _vec[i];
	// 	int j = i - 1;
	//
	// 	// Move elements greater than key one position ahead
	// 	while (j >= 0 && _vec[j] > key) {
	// 		_vec[j + 1] = _vec[j];
	// 		j--;
	// 	}
	// 	_vec[j + 1] = key;
	// }
}

void PmergeMe::compare(std::vector<std::pair<std::vector<int>, std::string> > &main, std::pair<std::vector<int>, std::string>& target_pair, int i)
{
//    std::cout << "Compare function received i in position :" << main[i].second << std::endl;
    
    // If main vector is empty, just insert at the beginning
    if (main.empty())
    {
        main.push_back(target_pair);
        return;
    }
    
    // Make sure i is in bounds
    if (i < 0) i = 0;
    if (i >= static_cast<int>(main.size())) i = static_cast<int>(main.size()) - 1;
    
    // Get target value safely 
    int target_value = 0;
    if (!target_pair.first.empty()) {
        target_value = target_pair.first.back();
    }
    
    // Find the correct position to insert using binary search for better performance
    // Use the entire array for search to ensure proper sorting
    int left = 0;
    int right = main.size() - 1;
    
    // If i is specified and within range, use it as the upper bound
    // This helps with the original algorithm's insertion pattern
    if (i >= 0 && i < static_cast<int>(main.size())) {
        right = i;
    }
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Get the main value safely
        int main_value = 0;
        if (mid < static_cast<int>(main.size()) && !main[mid].first.empty()) {
            main_value = main[mid].first.back();
        }
        
        if (main_value <= target_value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // left now contains the correct insertion point
    int insert_pos = left;
    
    // Make sure insertion position is valid
    if (insert_pos < 0) insert_pos = 0;
    if (insert_pos > static_cast<int>(main.size())) insert_pos = static_cast<int>(main.size());
    
//    std::cout << "After looking for closest number, inserting at position: " << insert_pos << std::endl;
    main.insert(main.begin() + insert_pos, target_pair);
    
//    std::cout << "\nMAIN AFTER INSERTION:\n";
//    for (size_t i = 0; i < main.size(); ++i)
//    {
//        std::cout << main[i].second << ": ";
//        for (size_t j = 0; j < main[i].first.size(); ++j)
//            std::cout << main[i].first[j] << " ";
//        std::cout << "\n";
//    }
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

void PmergeMe::retreiveBuffer(const std::vector<int> buffer)
{
    for (size_t i = 0; i < buffer.size(); ++i)
        _vec.push_back(buffer[i]);
}

void PmergeMe::merge()
{
    static size_t recursion_level = 1;
    static const size_t MAX_RECURSION_DEPTH = 20;

    std::cout << "Starting Recursion Level: " << recursion_level++ << std::endl;
    std::cout << "Current Pair Size: " << _pairSize << std::endl;

    // Modified base case to only return for empty or single-element vectors or maximum recursion depth
	organizePairs();
    if (recursion_level > MAX_RECURSION_DEPTH || _vec.empty() || _vec.size() == 1 || _vec.size() > _pairSize)
        return;

    // Handle buffer (odd elements) before organizing pairs
    std::vector<int> buffer;
    if (_vec.size() % (_pairSize * 2) != 0)
        buffer = bufferOddPair();

    // Organize pairs at current size level
    printVector();

    // Double pair size for next recursion level
    _pairSize *= 2;

    // Continue recursion if we have enough elements for the next level
//    if (_vec.size() > _pairSize)
//    {
        merge();
        _pairSize = _pairSize / 2;
        std::cout << "Pair Size after recursion: " << _pairSize << std::endl;
//    }

    // Always perform split and insert operation, even at pair size 1
    splitAndInsert();

    // Restore buffer elements
    if (!buffer.empty())
        retreiveBuffer(buffer);

    std::cout << "Current vector state after merge level " << recursion_level << ":" << std::endl;
    printVector();
}
