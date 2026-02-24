/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:57:15 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/24 16:43:54 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Bob");

    a.attack("Target");
    a.takeDamage(5);
    a.beRepaired(3);

    a.takeDamage(20);
    a.attack("Enemy");
    a.beRepaired(5);

    ClapTrap b("Max");

    b.attack("Dummy");
    b.attack("Dummy");
    b.attack("Dummy");
    b.attack("Dummy");
    b.attack("Dummy");
    b.attack("Dummy");
    b.attack("Dummy");
    b.attack("Dummy");
    b.attack("Dummy");
    b.attack("Dummy");
    b.attack("Dummy");

    return 0;
}
