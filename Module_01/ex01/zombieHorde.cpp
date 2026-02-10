/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:10:27 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 16:18:07 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	int		i;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];
	i = 0;
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}
