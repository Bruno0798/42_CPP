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
            // std::cout << "Comparing " << _vec[i] << " bigger than " << _vec[i + _pairSize] << std::endl;
            if (_vec[i] > _vec[i + _pairSize])
            {
                // std::cout << "Yes, switching numbers" << std::endl << std::endl;
                swapPairs((i + 1) - _pairSize);
            }
            // else
                // std::cout << "No, keeping the same" << std::endl << std::endl;
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

void PmergeMe::splitAndInsert()
{
    std::vector<std::pair<std::vector<int>, std::string> > assign = assignTags();
    std::vector<std::pair<std::vector<int>, std::string> > main;
    std::vector<std::pair<std::vector<int>, std::string> > pend;

    std::cout << "Printing vector before spliting " << std::endl << std::endl;
    printVector();

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
    size_t curr_jacob = getJacobsthal(jacobsthal);
    size_t prev_jacob = getJacobsthal(jacobsthal - 1);
    std::pair<std::vector<int>, std::string> target_pair;

    while (curr_jacob - prev_jacob <= pend.size())
    {
        for (size_t j = curr_jacob - prev_jacob; j != 0; --j)
        {
            std::cout << "Number of movements left " << j << std::endl;
            std::string target = "b" + to_string(curr_jacob);
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
        prev_jacob = curr_jacob;
        curr_jacob = getJacobsthal(jacobsthal);
        std::cout << "Jacobsthal: " << curr_jacob << std::endl;
    }

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
    std::cout << "Starting Recursion Level: " << recursion_level++ << std::endl;
    std::cout << "Current Pair Size: " << _pairSize * 2 << std::endl;
    organizePairs();
    _pairSize *= 2;
    std::vector<int > buffer = bufferOddPair();
    printVector();
    if(_vec.size() <= _pairSize * 2)
    {
        if (!buffer.empty())
            retreiveBuffer(buffer);
        return ;
    }
    merge();
    _pairSize /=2;
    // std::cout << "TESTING......" << std::endl;
    // printVector();
    // std::cout << "More testeting ....." << std::endl;
    splitAndInsert();
    // if (!buffer.empty())
    //     retreiveBuffer(buffer);

}
