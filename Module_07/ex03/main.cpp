/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:43:54 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 13:12:37 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 10

void printArray(const Array<int>& arr)
{
    unsigned int i = 0;
    while (i < arr.size())
    {
        std::cout << arr[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

int main(void)
{
    Array<int> numbers(MAX_VAL);

    srand(time(NULL));

    std::cout << "Filling array:" << std::endl;
    int i = 0;
    while (i < MAX_VAL)
    {
        numbers[i] = rand() % 100;
        i++;
    }
    printArray(numbers);

    std::cout << "\nTesting copy constructor:" << std::endl;
    Array<int> copy(numbers);
    printArray(copy);

    std::cout << "\nModify original:" << std::endl;
    numbers[0] = 999;
    printArray(numbers);

    std::cout << "Copy should NOT change:" << std::endl;
    printArray(copy);

    std::cout << "\nTesting assignment operator:" << std::endl;
    Array<int> assign;
    assign = numbers;
    printArray(assign);

    std::cout << "\nTesting out of bounds:" << std::endl;

    try
    {
        std::cout << numbers[MAX_VAL] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << numbers[-1] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
