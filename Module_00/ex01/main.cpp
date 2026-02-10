/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:19:17 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 10:49:46 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook pb;
	std::string input;

	while (true)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD")
			pb.addContact();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
			break;
	}
	return (0);
}

