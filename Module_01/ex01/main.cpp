/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:37:43 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 16:33:24 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*horde;
	int		i;
	int		n;

	n = 3;
	horde = zombieHorde(n, "TestZombie");
	if (!horde)
		return (1);

	i = 0;
	while (i < n)
	{
		horde[i].announce();
		i++;
	}

	delete[] horde;
	return (0);
}

