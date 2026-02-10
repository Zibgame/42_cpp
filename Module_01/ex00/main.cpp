/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:37:43 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 15:10:58 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Zombie *z = newZombie("Arthure");
	z->announce();
	delete z;

	randomChump("Billy");
	return (0);
}
