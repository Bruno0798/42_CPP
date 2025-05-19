#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <sstream>

class PmergeMe {
private:
    std::vector<int > _vec;
    size_t _pairSize;
public:
    PmergeMe();
    PmergeMe(char **argv, int argc);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void merge();
    void organizePairs();
    void swapPairs(size_t start);
    void splitAndInsert();
    std::vector<std::pair<std::vector<int>, std::string> > assignTags();
    std::vector<int> bufferOddPair();
    void retreiveBuffer(std::vector<int> buffer);
    void split(std::vector<std::pair<std::vector<int>,
    std::string> >& main, std::vector<std::pair<std::vector<int>,
    std::string> >& pend, std::vector<std::pair<std::vector<int>, std::string> >& assign);
    std::pair<std::vector<int>, std::string> getThePair(
    std::vector<std::pair<std::vector<int>, std::string> >& pend,
    const std::string& target);
    void compare(std::vector<std::pair<std::vector<int>, std::string> >& main, std::pair<std::vector<int>, std::string>& target_pair, int i);

    //UTILS
    void printVector() const;
    std::string to_string(int value);
    int getJacobsthal(int k);
};

#endif
