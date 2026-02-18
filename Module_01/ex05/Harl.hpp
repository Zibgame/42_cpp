/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:55:00 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/18 10:52:32 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl();
		void complain(std::string level);
		~Harl();

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
    std::string levels[4];
    void (Harl::*functions[4])();
};
