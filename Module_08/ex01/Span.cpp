/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:54:39 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 15:12:24 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int n) : _max(n)
{
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _max = other._max;
        _data = other._data;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_data.size() >= _max)
        throw std::runtime_error("Span is full");
    _data.push_back(n);
}

int Span::shortestSpan()
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements");

    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());

    int min = std::numeric_limits<int>::max();
    size_t i = 1;

    while (i < tmp.size())
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < min)
            min = diff;
        i++;
    }
    return min;
}

int Span::longestSpan()
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements");

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());

    return max - min;
}

typedef typename std::stack<T>::container_type::const_iterator const_iterator;

const_iterator begin() const
{
    return this->c.begin();
}

const_iterator end() const
{
    return this->c.end();
}
