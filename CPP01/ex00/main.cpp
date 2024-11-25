/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:32:06 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/25 13:55:35 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
    std::string zombieName;
    Zombie *zombie = NULL;

    std::cout << "Enter name:";
    std::cin >> zombieName;

    zombie = Zombie::newZombie(zombieName);
	if (zombie != NULL)
	{
    	zombie->announce();
    	delete zombie;
	}
	std::cout << "Using the randomChump now!" << std::endl;
	randomChump(zombieName);
    return 0;
}
