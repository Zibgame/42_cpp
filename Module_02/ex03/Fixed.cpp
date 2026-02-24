/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:46:07 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/24 13:46:40 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const int value)
{
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}

Fixed::~Fixed(void) {}

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (_rawBits > other._rawBits);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (_rawBits < other._rawBits);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (_rawBits >= other._rawBits);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (_rawBits <= other._rawBits);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (_rawBits != other._rawBits);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result._rawBits = _rawBits + other._rawBits;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result._rawBits = _rawBits - other._rawBits;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result._rawBits = (_rawBits * other._rawBits) >> _fractionalBits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result._rawBits = (_rawBits << _fractionalBits) / other._rawBits;
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	_rawBits++;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	_rawBits--;
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
