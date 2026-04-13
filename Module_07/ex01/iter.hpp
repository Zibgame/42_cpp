/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:45:35 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/13 13:54:10 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void iter(T *tab, const size_t len, void (*f)(T &))
{
    if (!tab || !f)
        return;
    size_t i = 0;

    while (i < len)
    {
        f(tab[i]);
        i++;
    }
    return ;
}

template <typename T>
void iter(T *tab, const size_t len, void (*f)(const T &))
{
    if (!tab || !f)
        return;
    size_t i = 0;

    while (i < len)
    {
        f(tab[i]);
        i++;
    }
}
