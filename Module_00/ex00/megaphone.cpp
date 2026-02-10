/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 07:56:50 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 08:15:54 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int megaphone(char **str)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			std::cout << static_cast<char>(std::toupper(str[i][j]));
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	megaphone(argv);
	return (0);
}
