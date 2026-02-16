/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:40:12 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/16 14:56:39 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type)
{
}

Weapon::~Weapon()
{
	std::cout << "Weapon destroyed" << std::endl;
}

const std::string Weapon::getType() 
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}
