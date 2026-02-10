/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:37:27 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 15:14:28 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string name)
{
	Zombie::setName(name);
}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

std::string	Zombie::getName()
{
	return _name;
}

std::string Zombie::setName(const std::string name)
{
	_name = name;
	return _name;
}

void Zombie::announce(void)
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
