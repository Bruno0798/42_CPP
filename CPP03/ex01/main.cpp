#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap Clap("ClapTrap");
	ScavTrap Scav("ScavTrap");

	std::cout << "\033[32m\nScavTrap class Test\033[0m" << std::endl;
	Scav.attack("test");

	Scav.takeDamage(900);

	Scav.beRepaired(12);

	Scav.guardGate();

	std::cout << "\033[32mOperator = Test\033[0m" << std::endl;
	ScavTrap ScavCopy;

	ScavCopy = Scav;

	return (0);
}