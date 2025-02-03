#include <iostream>
#include "Templates.hpp" // Assuming your template definitions are in templates.hpp

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

int main()
{
	std::cout << cyan << "\n►►►►►►  " << "Testing Swap With Ints" << "  ◄◄◄◄◄◄" << reset << std::endl;
	int a = 5, b = 10;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

	std::cout << cyan << "\n►►►►►►  " << "Testing Swap With Double" << "  ◄◄◄◄◄◄" << reset << std::endl;
	double x = 3.14, y = 2.71;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

	std::cout << cyan << "\n►►►►►►  " << "Testing Swap With Strings" << "  ◄◄◄◄◄◄" << reset << std::endl;
	std::string str1 = "hello", str2 = "world";
	std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;

	std::cout << cyan << "\n►►►►►►  " << "Testing Min and Max With Ints" << "  ◄◄◄◄◄◄" << reset << std::endl;
	int c = 7, d = 2;
	std::cout << "Min of c and d: " << min(c, d) << std::endl;
	std::cout << "Max of c and d: " << max(c, d) << std::endl;

	std::cout << cyan << "\n►►►►►►  " << "Testing Min and Max With Chars" << "  ◄◄◄◄◄◄" << reset << std::endl;
	char p = 'p', q = 'q';
	std::cout << "Min of p and q: " << min(p, q) << std::endl;
	std::cout << "Max of p and q: " << max(p, q) << std::endl;

	std::cout << cyan << "\n►►►►►►  " << "Testing Min and Max With Strings" << "  ◄◄◄◄◄◄" << reset << std::endl;
	std::string str3 = "apple", str4 = "banana";
	std::cout << "Min of str3 and str4: " << min(str3, str4) << std::endl;
	std::cout << "Max of str3 and str4: " << max(str3, str4) << std::endl;

	std::cout << cyan << "\n►►►►►►  " << "Testing Swap With Chars" << "  ◄◄◄◄◄◄" << reset << std::endl;
	char char1 = 'A', char2 = 'B';
	std::cout << "Before swap: char1 = " << char1 << ", char2 = " << char2 << std::endl;
	swap(char1, char2);
	std::cout << "After swap: char1 = " << char1 << ", char2 = " << char2 << std::endl;

	return 0;
}