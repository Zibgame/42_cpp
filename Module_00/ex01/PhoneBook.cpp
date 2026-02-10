/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:26:05 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 10:56:05 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

static std::string formatField(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

PhoneBook::PhoneBook() : _count(0), _nextIndex(0)
{
}

void PhoneBook::addContact()
{
	Contact c;
	std::string input;

	do {
		std::cout << "First name: ";
		std::getline(std::cin, input);
	} while (input.empty());
	c.setFirstName(input);

	do {
		std::cout << "Last name: ";
		std::getline(std::cin, input);
	} while (input.empty());
	c.setLastName(input);

	do {
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
	} while (input.empty());
	c.setNickName(input);

	do {
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
	} while (input.empty());
	c.setPhoneNumber(input);

	do {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
	} while (input.empty());
	c.setDarkestSecret(input);

	_contacts[_nextIndex] = c;
	_nextIndex = (_nextIndex + 1) % 8;
	if (_count < 8)
		_count++;
}

void PhoneBook::displayContacts() const
{
	int i = 0;

	while (i < _count)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatField(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatField(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatField(_contacts[i].getNickName()) << std::endl;
		i++;
	}
}

int PhoneBook::readIndex() const
{
	std::string input;
	int index;

	std::cout << "Index: ";
	std::getline(std::cin, input);
	index = std::atoi(input.c_str());
	if (index < 0 || index >= _count)
		return (-1);
	return (index);
}

void PhoneBook::search() const
{
	int index;

	if (_count == 0)
	{
		std::cout << "PhoneBook empty" << std::endl;
		return;
	}
	displayContacts();
	index = readIndex();
	if (index == -1)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	_contacts[index].print();
}
