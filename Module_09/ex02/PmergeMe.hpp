/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:50:13 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 17:50:15 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();

    void process(char **argv);

private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    void parseInput(char **argv);

    void sortVector();
    void sortDeque();

    void mergeInsertVector(std::vector<int>& arr);
    void mergeInsertDeque(std::deque<int>& arr);

    int binarySearchVector(std::vector<int>& arr, int value, int high);
    int binarySearchDeque(std::deque<int>& arr, int value, int high);
};

#endif
