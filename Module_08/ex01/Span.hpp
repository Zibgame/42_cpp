/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:54:48 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 14:59:03 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <stdexcept>

class Span
{
private:
    unsigned int _max;
    std::vector<int> _data;

public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        while (begin != end)
        {
            if (_data.size() >= _max)
                throw std::runtime_error("Span is full");
            _data.push_back(*begin);
            ++begin;
        }
    }

    int shortestSpan();
    int longestSpan();
};

#endif
