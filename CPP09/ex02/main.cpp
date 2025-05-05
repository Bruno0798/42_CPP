#include <iostream>
#include <vector>
#include "PmergeMe.hpp"


void printVector(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

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
	if (argc == 1)
		return std::cout << "No Numbers" << std::endl, 1;
	if(!checkArguments(argc, argv))
		return std::cout << "Invalid Arguments\n", 1;
	double time = clock();
	PmergeMe merge(argc,argv);
	printVector(merge.getVec());
	merge.merge(merge.getVec(), 1);
//	printVector(merge.getVec());
	time = (clock() - time) / CLOCKS_PER_SEC;
	std::cout << "Time: " << time << std::endl;


    return 0;
}
