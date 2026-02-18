/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:55:03 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/18 10:56:22 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

    functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;
}

Harl::~Harl()
{
	std::cout << "Harl has been delete" << std::endl;
}

void Harl::complain(std::string level)
{
	for(int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
		std::cout << "UNKNOWN MESSAGE" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "DEBUG MESSAGE" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO MESSAGE" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING MESSAGE" << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR MESSAGE" << std::endl;
}
