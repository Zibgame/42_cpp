/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:54:28 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 13:10:15 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;

public:
    Array() : _data(0), _size(0) {}

    Array(unsigned int n) : _data(0), _size(n)
    {
        if (_size > 0)
            _data = new T[_size]();
    }

    Array(const Array& other) : _data(0), _size(other._size)
    {
        if (_size > 0)
        {
            _data = new T[_size];
            unsigned int i = 0;
            while (i < _size)
            {
                _data[i] = other._data[i];
                i++;
            }
        }
    }

    ~Array()
    {
        delete[] _data;
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _data;
            _size = other._size;
            _data = 0;
            if (_size > 0)
            {
                _data = new T[_size];
                unsigned int i = 0;
                while (i < _size)
                {
                    _data[i] = other._data[i];
                    i++;
                }
            }
        }
        return *this;
    }

    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    const T& operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    unsigned int size() const
    {
        return _size;
    }
};

#endif
