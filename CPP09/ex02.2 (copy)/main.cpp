#include <iostream>
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
    if(argc == 1)
		return std::cout << "No Numbers Found" << std::endl, 1;
	if(!checkArguments(argc,argv))
		return std::cout << "Invalid Arguments\n", 1;
//	double time = clock();
	PmergeMe merge(argc, argv);
//	merge.printVector();
	merge.merge();
	merge.printVector();
	return 0;
}
