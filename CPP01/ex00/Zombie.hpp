/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:51:20 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/14 13:09:14 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;
    
public:
    Zombie(std::string name);
	~Zombie();
    void announce();
    static Zombie* newZombie(std::string name);
};

void randomChump(std::string name);
#endif
