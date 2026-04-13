/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:43:54 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/13 15:02:22 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#include "Array.hpp"
#include <iostream>

int main(void)
{
    Array<int> a(3);

    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    std::cout << "Array content:" << std::endl;

    unsigned int i = 0;
    while (i < a.size())
    {
        std::cout << a[i] << std::endl;
        i++;
    }

    std::cout << "\nCopy test:" << std::endl;

    Array<int> b = a;
    b[0] = 99;

    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    std::cout << "\nOut of bounds test:" << std::endl;

    try
    {
        std::cout << a[10] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught" << std::endl;
    }

    return 0;
}
