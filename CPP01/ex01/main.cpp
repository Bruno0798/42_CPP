/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:34:33 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 20:37:12 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "Zombie.hpp"
#include <cstdlib>

int getPositiveNumberOfZombies()
{
    int numberZombies = 0;
    while (numberZombies <= 0)
    {
        std::cout << CLEAR;
        std::cout << "Enter a positive number of zombies for the Horde: ";
        std::cin >> numberZombies;

        if (std::cin.eof())
        {
            std::cerr << "\nEOF detected. Exiting program." << std::endl;
            return 1;
        } else if (std::cin.fail() || numberZombies <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            numberZombies = 0;
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
    }
    return numberZombies;
}

int main(int argc, char **argv)
{
    (void)argv;
    if(argc != 1)
    {
        std::cout << "You dont need arguments for this one!";
        return (1);
    }

    int numberZombies = getPositiveNumberOfZombies();
    std::string name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "What name should we call them: ";
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << "Name cannot be empty. Please enter a valid name: ";
        std::getline(std::cin, name);
    }
    if (std::cin.fail() || std::cin.eof())
    {
        std::cerr << "\nInput error detected. Exiting program." << std::endl;
        return 1;
    }

    Zombie *horde = zombieHorde(numberZombies, name);

    for (int i = 0; i < numberZombies; ++i)
        horde[i].announce();
    delete[] horde;

    return 0;
}