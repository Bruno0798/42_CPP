#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

bool checkArguments(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
        for (int j = 0; argv[i][j]; ++j)
            if(!std::isdigit(argv[i][j]))
                return false;
    return true;
}
int main(int argc, char **argv)
{
    if(argc < 3)
        return std::cout << "Not enough numbers" << std::endl, 1;
    if(!checkArguments(argc,argv))
        return std::cout << "Invalid Arguments\n", 1;
    PmergeMe merge(argv, argc);
    merge.printVector();
    merge.merge();

    return 0;
}
