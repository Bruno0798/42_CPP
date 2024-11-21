/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:32:06 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/21 22:08:54 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string zombieName;
    Zombie *zombie = NULL;

    std::cout << "Enter name:";
    std::cin >> zombieName;

    zombie = Zombie::newZombie(zombieName);
    randomChump(zombieName);
	if (zombie != NULL)
	{
    	zombie->announce();
    	delete zombie;
	}

    return 0;
}
