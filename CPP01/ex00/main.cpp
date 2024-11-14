/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:32:06 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 13:09:14 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string zombieName;
    Zombie *zombie = NULL;

    std::cout << "Enter name:";
    std::cin >> zombieName;

    zombie = zombie->newZombie(zombieName);
    randomChump(zombieName);
    zombie->announce();

    delete zombie;
    return 0;
}
