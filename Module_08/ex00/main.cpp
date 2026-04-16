/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:25:17 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 13:37:01 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;

    int i = 0;
    while (i < 5)
    {
        v.push_back(i * 10);
        l.push_back(i * 10);
        d.push_back(i * 10);
        i++;
    }

    try
    {
        std::vector<int>::iterator it_v = easyfind(v, 20);
        std::cout << "Vector found: " << *it_v << std::endl;

        std::list<int>::iterator it_l = easyfind(l, 30);
        std::cout << "List found: " << *it_l << std::endl;

        std::deque<int>::iterator it_d = easyfind(d, 40);
        std::cout << "Deque found: " << *it_d << std::endl;

        easyfind(v, 100);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
