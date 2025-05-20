#include "PmergeMe.hpp"

bool checkArguments(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
		for (int j = 0; argv[i][j]; ++j)
			if(!std::isdigit(argv[i][j]))
				return false;
	return true;
}

static std::vector<int> argvToVector(int argc, char **argv)
{
	std::vector<int> result;
	result.reserve(argc - 1);
	for(int i = 1; i < argc; i++)
		result.push_back(std::atoi(argv[i]));
	return result;
}

int main(int argc, char **argv)
{
	if(argc < 3)
		return std::cout << "Not enough numbers" << std::endl, 1;
	if(!checkArguments(argc,argv))
		return std::cout << "Invalid Arguments\n", 1;
	clock_t startTimeVec = clock();
	std::vector<int > vector = argvToVector(argc, argv);
	clock_t endTimeVec = clock();
	double timeVec = static_cast<double>(endTimeVec - startTimeVec) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vector.size() << ": " << timeVec << std::endl;
    return 0;
}
