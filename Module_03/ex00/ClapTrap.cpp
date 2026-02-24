/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:08:24 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/24 16:43:05 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " created" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " is dead and cannot attack."
                  << std::endl;
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " has no energy left."
                  << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " is already dead."
                  << std::endl;
        return;
    }
    if (amount >= (unsigned int)_hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage! Remaining HP: "
              << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " is dead and cannot be repaired."
                  << std::endl;
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " has no energy left."
                  << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name
              << " repairs itself for " << amount
              << " hit points! Current HP: "
              << _hitPoints << std::endl;
}
