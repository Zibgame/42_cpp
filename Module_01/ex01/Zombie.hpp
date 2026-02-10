/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:37:32 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 16:20:19 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		Zombie(const std::string name);
		std::string getName();
		std::string setName(const std::string name);
		void announce(void);
		~Zombie();

	private:
		std::string _name;
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif
