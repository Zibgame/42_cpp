/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:45:43 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/13 13:50:45 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void print(const int &x)
{
    std::cout << x << std::endl;
}

int main(void)
{
    int arr[] = {1, 2, 3};

    iter(arr, 3, print);

    return 0;
}
