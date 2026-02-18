/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:54:58 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/18 10:53:55 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "---- DEBUG ----" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\n---- INFO ----" << std::endl;
    harl.complain("INFO");

    std::cout << "\n---- WARNING ----" << std::endl;
    harl.complain("WARNING");

    std::cout << "\n---- UNKNOWN ----" << std::endl;
    harl.complain("UNKNOWN");

    std::cout << "\n---- ERROR ----" << std::endl;
    harl.complain("ERROR");
    return 0;
}

