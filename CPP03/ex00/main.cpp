/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:15:21 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/24 20:25:09 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "\033[1;31mTesting: \033[1;37mattack\033[0m Function\033[0m" << std::endl;
	defaultClap.attack("target");
	std::cout << "\n\033[1;31mTesting: \033[1;37mtakeDamage\033[0m Function\033[0m" << std::endl;
	defaultClap.takeDamage(5);
	std::cout << "\n\033[1;31mTesting: \033[1;37mbeRepaired\033[0m Function\033[0m" << std::endl;
	defaultClap.beRepaired(3);
	pauseExecution();

	displayTitle("Edge Cases");
	std::cout << "\033[1;31mTesting: Taking more damage than hit points.\033[0m \033[1;37m(Expected: HP should reduce to 0 but not go negative.)\033[0m\n";
	defaultClap.takeDamage(15);
	std::cout << std::endl;

	std::cout << "\033[1;31mTesting: Attempting to attack with zero hit points.\033[0m \033[1;37m(Expected: Attack should not be allowed.)\033[0m\n";
	defaultClap.attack("target");
	std::cout << std::endl;

	std::cout << "\033[1;31mTesting: Repairing after reaching zero hit points.\033[0m \033[1;37m(Expected: HP should increase.)\033[0m\n";
	defaultClap.beRepaired(5);
	std::cout << std::endl;

	std::cout << "\033[1;31mTesting: Attempting to attack after recovering hit points.\033[0m \033[1;37m(Expected: It should be able to attack)\033[0m\n";
	defaultClap.attack("target");
	std::cout << std::endl;
	pauseExecution();

	displayTitle("Energy Depletion");
	std::cout << "\033[1;32mTesting: Attacking until energy points reach zero.\033[0m \033[1;37m(Expected: Energy decreases with each attack.)\033[0m\n";
	defaultClap.setEnergyPoints(5);
	while (defaultClap.getEnergyPoints() > 0)
	{
		std::cout << "\033[1;34mEnergy Points: " << defaultClap.getEnergyPoints() << "\033[0m ";
		defaultClap.attack("Energy Target");
	}

	std::cout << "\n\033[1;31mTesting: Attempting to attack with zero energy points.\033[0m \033[1;37m(Expected: Attack should not be allowed.)\033[0m\n";
	defaultClap.attack("target");
	pauseExecution();

	displayTitle("Destructors");
	return 0;
}