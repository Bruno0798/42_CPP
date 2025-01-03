/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:15:21 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/12/24 20:34:56 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
#include <limits>
#include <cstdlib>

void displayTitle(const std::string &title)
{
	std::cout << "\033[1;36m\n=== " << title << " ===\033[0m\n" << std::endl;
}

void displaySubtitle(const std::string &subtitle)
{
	std::cout << "\033[1;33m\n" << subtitle << "\033[0m\n" << std::endl;
}

void pauseExecution()
{
	std::cout << "\033[1;35mPress Enter to continue...\033[0m" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("clear");
}

int main()
{
	system("clear");
	displayTitle("Constructors");
	ClapTrap defaultClap;
	std::cout << std::endl;
	ClapTrap clap("Clapy");
	std::cout << std::endl;
	ScavTrap scav("Scavy");
	std::cout << std::endl;
	ClapTrap copyClap(clap);
	std::cout << std::endl;
	ScavTrap copyScav(scav);
	std::cout << std::endl;
	pauseExecution();

	displayTitle("ClapTrap Class Tests");
	displaySubtitle("Basic Functionality");
	defaultClap.attack("target1");
	defaultClap.takeDamage(5);
	defaultClap.beRepaired(3);
	pauseExecution();

	displayTitle("ClapTrap Class Tests");
	displaySubtitle("Edge Cases");

	std::cout << "\033[1;31mTesting: Taking more damage than hit points.\033[0m \033[1;37m(Expected: HP should reduce to 0 but not go negative.)\033[0m\n";
	defaultClap.takeDamage(999);

	std::cout << "\033[1;31mTesting: Attempting to attack with zero hit points.\033[0m \033[1;37m(Expected: Attack should not be allowed.)\033[0m\n";
	defaultClap.attack("target2");

	std::cout << "\033[1;31mTesting: Repairing after reaching zero hit points.\033[0m \033[1;37m(Expected: HP should increase.)\033[0m\n";
	defaultClap.beRepaired(100);
	pauseExecution();

	displayTitle("Energy Depletion");
	std::cout << "\033[1;32mTesting: Attacking until energy points reach zero.\033[0m \033[1;37m(Expected: Energy decreases with each attack.)\033[0m\n";
	defaultClap.setEnergyPoints(5);
	while (defaultClap.getEnergyPoints() > 0)
	{
		std::cout << "\033[1;34mEnergy Points: " << defaultClap.getEnergyPoints() << "\033[0m ";
		defaultClap.attack("Energy Target");
	}

	std::cout << "\033[1;31mTesting: Attempting to attack with zero energy points.\033[0m \033[1;37m(Expected: Attack should not be allowed.)\033[0m\n";
	defaultClap.attack("Out of Energy");
	pauseExecution();

	displayTitle("ScavTrap Class Tests");
	displaySubtitle("Basic Functionality");
	scav.attack("target2");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();
	pauseExecution();

	displayTitle("ScavTrap Class Tests");
	displaySubtitle("Edge Cases");

	std::cout << "\033[1;31mTesting: Taking significant damage.\033[0m \033[1;37m(Expected: HP should reduce but not go negative.)\033[0m\n";
	scav.takeDamage(900);

	std::cout << "\033[1;31mTesting: Attempting to attack with low energy points.\033[0m \033[1;37m(Expected: Attack should succeed if energy > 0.)\033[0m\n";
	scav.attack("target3");

	std::cout << "\033[1;31mTesting: Repairing after low energy points.\033[0m \033[1;37m(Expected: HP should increase but not exceed max HP.)\033[0m\n";
	scav.beRepaired(50);
	pauseExecution();

	displayTitle("ScavTrap Class Tests");
	displaySubtitle("Energy Depletion");

	std::cout << "\033[1;32mTesting: Attacking until energy points reach zero.\033[0m \033[1;37m(Expected: Energy decreases with each attack.)\033[0m\n";
	scav.setEnergyPoints(5);
	while (scav.getEnergyPoints() > 0)
	{
		std::cout << "\033[1;34mEnergy Points: " << scav.getEnergyPoints() << "\033[0m ";
		scav.attack("Energy Target");
	}

	std::cout << "\033[1;31mTesting: Attempting to attack with zero energy points.\033[0m \033[1;37m(Expected: Attack should not be allowed.)\033[0m\n";
	scav.attack("Out of Energy");
	pauseExecution();

	displayTitle("Destructors");

	return (0);
}