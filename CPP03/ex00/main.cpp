#include "clapTrap.hpp"

int main()
{
	clapTrap robot1("robot1");
	clapTrap robot2("robot2");

	robot1.attack("robot2");
	robot2.takeDamage(5);
	robot2.beRepaired(3);

    return 0;
}