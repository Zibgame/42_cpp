/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:50:21 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 17:52:48 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        int n = std::atoi(argv[i]);
        if (n < 0)
            throw std::runtime_error("Error");
        _vec.push_back(n);
        _deq.push_back(n);
    }
}

int PmergeMe::binarySearchVector(std::vector<int>& arr, int value, int high)
{
    int low = 0;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void PmergeMe::mergeInsertVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pending;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            mainChain.push_back(arr[i]);
            pending.push_back(arr[i + 1]);
        }
        else
        {
            mainChain.push_back(arr[i + 1]);
            pending.push_back(arr[i]);
        }
    }

    if (arr.size() % 2)
        pending.push_back(arr.back());

    mergeInsertVector(mainChain);

    arr = mainChain;

    for (size_t i = 0; i < pending.size(); i++)
    {
        int pos = binarySearchVector(arr, pending[i], arr.size() - 1);
        arr.insert(arr.begin() + pos, pending[i]);
    }
}

void PmergeMe::sortVector()
{
    clock_t start = clock();
    mergeInsertVector(_vec);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << time << " us" << std::endl;
}

int PmergeMe::binarySearchDeque(std::deque<int>& arr, int value, int high)
{
    int low = 0;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void PmergeMe::mergeInsertDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pending;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            mainChain.push_back(arr[i]);
            pending.push_back(arr[i + 1]);
        }
        else
        {
            mainChain.push_back(arr[i + 1]);
            pending.push_back(arr[i]);
        }
    }

    if (arr.size() % 2)
        pending.push_back(arr.back());

    mergeInsertDeque(mainChain);

    arr = mainChain;

    for (size_t i = 0; i < pending.size(); i++)
    {
        int pos = binarySearchDeque(arr, pending[i], arr.size() - 1);
        arr.insert(arr.begin() + pos, pending[i]);
    }
}

void PmergeMe::sortDeque()
{
    clock_t start = clock();
    mergeInsertDeque(_deq);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << time << " us" << std::endl;
}

void PmergeMe::process(char **argv)
{
    parseInput(argv);

    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    mergeInsertVector(_vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    mergeInsertDeque(_deq);
    clock_t endDeq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << timeDeq << " us" << std::endl;
}
