/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:26:08 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 10:55:44 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::setFirstName(const std::string &value)
{
	_firstName = value;
}

void Contact::setLastName(const std::string &value)
{
	_lastName = value;
}

void Contact::setNickName(const std::string &value)
{
	_nickname = value;
}

void Contact::setPhoneNumber(const std::string &value)
{
	_phoneNumber = value;
}

void Contact::setDarkestSecret(const std::string &value)
{
	_darkestSecret = value;
}

const std::string &Contact::getFirstName() const
{
	return _firstName;
}

const std::string &Contact::getLastName() const
{
	return _lastName;
}

const std::string &Contact::getNickName() const
{
	return _nickname;
}

const std::string &Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

const std::string &Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

void Contact::print() const
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
