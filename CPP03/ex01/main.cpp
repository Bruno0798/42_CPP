#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot1("robot1");
	ClapTrap robot2("robot2");

	robot1.attack("robot2");
	robot2.takeDamage(5);
	robot2.beRepaired(3);

    return 0;
}