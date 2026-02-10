/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:25:10 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 10:55:54 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();

		void addContact();
		void search() const;

	private:
		Contact _contacts[8];
		int     _count;
		int     _nextIndex;

		void displayContacts() const;
		int  readIndex() const;
};

#endif
