/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:37:32 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 15:13:09 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		~Zombie();
		Zombie(const std::string name);
		std::string getName();
		std::string setName(const std::string name);
		void announce(void);

	private:
		std::string _name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
