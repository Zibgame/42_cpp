/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:23:41 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/13 13:40:56 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
T max(T a, T b)
{
    if (a > b)
        return a;
    return b;
}
