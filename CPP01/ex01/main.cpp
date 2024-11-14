/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:34:33 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 16:00:03 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "Zombie.hpp"
#include <cstdlib>

// Function to get a positive number of zombies from the user
int getPositiveNumberOfZombies() {
    int numberZombies = 0;
    while (numberZombies <= 0) {
        std::cout << CLEAR;
        std::cout << "Enter a positive number of zombies for the Horde: ";
        std::cin >> numberZombies;

        // Check if the input failed or if it's not positive
        if (std::cin.eof()) {
            std::cerr << "\nEOF detected. Exiting program." << std::endl;
            std::exit(1);
        } else if (std::cin.fail() || numberZombies <= 0) {
            std::cin.clear(); // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            numberZombies = 0; // Reset numberZombies to keep the loop going
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
    }
    return numberZombies;
}

int main(void) {
    int numberZombies = getPositiveNumberOfZombies();
    std::string name;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "What name should we call them: ";
    std::getline(std::cin, name);

    if (std::cin.eof()) {
        std::cerr << "\nEOF detected. Exiting program." << std::endl;
        exit(1);
    }

    Zombie *horde = zombieHorde(numberZombies, name);

    for (int i = 0; i < numberZombies; ++i) {
        horde[i].announce();
    }
    delete[] horde;

    return 0;
}
