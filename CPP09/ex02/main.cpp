#include <iomanip>
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
	result.reserve(argc);
	for(int i = 1; i < argc; i++)
		result.push_back(std::atoi(argv[i]));
	return result;
}

static std::deque<int> argvToDeque(int argc, char** argv)
{
	std::deque<int> res;
	for (int i = 1; i < argc; i++)
	{
		res.push_back(std::atoi(argv[i]));
	}
	return res;
}

static int F(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(std::ceil(log2(value)));
	}
	return sum;
}

int main(int argc, char **argv)
{
	PmergeMe pm;
	if(argc < 3)
		return std::cout << "Not enough numbers" << std::endl, 1;
	if(!checkArguments(argc,argv))
		return std::cout << "Invalid Arguments\n", 1;

	std::cout << RED << "Before: " << RESET;
	printContainer(argvToVector(argc, argv));
	clock_t startTimeVec = clock();
	std::vector<int > vector = argvToVector(argc, argv);
	pm.sort_vec(vector);
	clock_t endTimeVec = clock();
	std::cout << GREEN << "After: " << RESET;
	printContainer(vector);
	std::cout << std::endl;
	std::cout << "Number of comparisons: " << GREEN << PmergeMe::comparisons << RESET << std::endl;
	std::cout << "Number of maximum comparisons using Ford Jonhson: " << F(argc - 1) << std::endl;
	double timeVec = static_cast<double>(endTimeVec - startTimeVec) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(6) << "Time to process a range of " << vector.size() << ": " << GREEN << timeVec << RESET << std::endl << std::endl;

	PmergeMe::comparisons = 0;
	std::cout << RED << "Before: " << RESET;
	printContainer(argvToDeque(argc, argv));
	clock_t startTimeDeque = clock();
	std::deque<int > deque = argvToDeque(argc, argv);
	pm.sort_deque(deque);
	clock_t endTimeDeque = clock();
	std::cout << GREEN << "After: " << RESET;
	printContainer(deque);
	std::cout << std::endl;
	std::cout << "Number of comparisons: " << GREEN << PmergeMe::comparisons << RESET << std::endl;
	std::cout << "Number of maximum comparisons using Ford Jonhson: " << F(argc - 1) << std::endl;
	double timeDeque = static_cast<double>(endTimeDeque - startTimeDeque) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(6) << "Time to process a range of " << deque.size() << ": " << GREEN << timeDeque << RESET << std::endl;

    return 0;
}
