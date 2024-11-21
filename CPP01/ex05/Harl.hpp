/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:39:35 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/20 20:39:35 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
public:
    Harl();
    ~Harl();

    void complain(std::string level);
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
//    void notfound(void);
};