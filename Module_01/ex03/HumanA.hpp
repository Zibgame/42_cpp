/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:39:55 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/16 13:55:00 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(const std::string& name, Weapon& weapon);
		void attack();
		~HumanA();

	private:
		std::string _name;
		Weapon& _weapon;
};
