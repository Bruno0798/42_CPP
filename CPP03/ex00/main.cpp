#include "ClapTrap.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

void displayTitle(const std::string &title)
{
	std::cout << "\033[1;36m\n=== " << title << " ===\033[0m\n" << std::endl;
}

void pauseExecution()
{
	std::cout << "\033[1;35mPress Enter to continue...\033[0m" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("clear");
}

int main() {
	system("clear");
	displayTitle("Constructors");
	ClapTrap defaultClap;
	std::cout << std::endl;
	ClapTrap namedClap("Clappy");
	std::cout << std::endl;
	ClapTrap copyClap(namedClap);
	std::cout << std::endl;
	pauseExecution();

	displayTitle("Basic Functionality");
	defaultClap.attack("target1");
	defaultClap.takeDamage(5);
	defaultClap.beRepaired(3);
	pauseExecution();

	displayTitle("Edge Cases");
	std::cout << "\033[1;31mTesting: Taking more damage than hit points.\033[0m \033[1;37m(Expected: HP should reduce to 0 but not go negative.)\033[0m\n";
	defaultClap.takeDamage(15);

	std::cout << "\033[1;31mTesting: Attempting to attack with zero hit points.\033[0m \033[1;37m(Expected: Attack should not be allowed.)\033[0m\n";
	defaultClap.attack("target2");

	std::cout << "\033[1;31mTesting: Repairing after reaching zero hit points.\033[0m \033[1;37m(Expected: HP should increase.)\033[0m\n";
	defaultClap.beRepaired(5);
	pauseExecution();

	displayTitle("Energy Depletion");
	std::cout << "\033[1;32mTesting: Attacking until energy points reach zero.\033[0m \033[1;37m(Expected: Energy decreases with each attack.)\033[0m\n";
	while (defaultClap.getEnergyPoints() > 0)
	{
		std::cout << "\033[1;34mEnergy Points: " << defaultClap.getEnergyPoints() << "\033[0m ";
		defaultClap.attack("Energy Target");
	}

	std::cout << "\033[1;31mTesting: Attempting to attack with zero energy points.\033[0m \033[1;37m(Expected: Attack should not be allowed.)\033[0m\n";
	defaultClap.attack("Out of Energy");
	pauseExecution();

	displayTitle("Destructors");
	return 0;
}