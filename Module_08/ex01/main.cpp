/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:54:51 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 14:58:51 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "Span.hpp"

int main()
{
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------" << std::endl;

    try
    {
        Span big(10000);
        std::vector<int> v;
        std::srand(std::time(NULL));

        size_t i = 0;
        while (i < 10000)
        {
            v.push_back(std::rand());
            i++;
        }

        big.addRange(v.begin(), v.end());

        std::cout << "Shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Longest: " << big.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------" << std::endl;

    try
    {
        Span test(2);
        test.addNumber(1);
        test.addNumber(2);
        test.addNumber(3);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
