#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <climits>

// Text colors
const std::string red = "\033[31m";
const std::string green = "\033[32m";
const std::string yellow = "\033[33m";
const std::string blue = "\033[34m";
const std::string magenta = "\033[35m";
const std::string cyan = "\033[36m";
const std::string white = "\033[37m";
const std::string bright_black = "\033[90m";
const std::string bright_red = "\033[91m";
const std::string bright_green = "\033[92m";
const std::string bright_yellow = "\033[93m";
const std::string bright_blue = "\033[94m";
const std::string bright_magenta = "\033[95m";
const std::string bright_cyan = "\033[96m";
const std::string bright_white = "\033[97m";
const std::string reset = "\033[0m";

class PmergeMe {
private:
    std::vector<int > _vec;
	std::list<int > _list;
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
