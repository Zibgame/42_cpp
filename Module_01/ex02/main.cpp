/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:38:14 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 16:47:22 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strptr = &str;
	std::string &stref = str;
	std::cout << &str << std::endl;
	std::cout << strptr << std::endl;
	std::cout << &stref << std::endl;


	std::cout << str << std::endl;
	std::cout << *strptr << std::endl;
	std::cout << str << std::endl;
	return (0);
}
