/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:54:28 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/13 15:02:13 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    private:
        T* _data;
        unsigned int _size;

    public:
        Array() : _data(0), _size(0) {}

        Array(unsigned int n) : _size(n)
        {
            _data = new T[n];
        }

        Array(const Array& other) : _size(other._size)
        {
            unsigned int i = 0;
            _data = new T[_size];
            while (i < _size)
            {
                _data[i] = other._data[i];
                i++;
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
                _data = new T[_size];
                unsigned int i = 0;
                while (i < _size)
                {
                    _data[i] = other._data[i];
                    i++;
                }
            }
            return *this;
        }

        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::exception();
            return _data[index];
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::exception();
            return _data[index];
        }

        unsigned int size() const
        {
            return _size;
        }
};

#endif
