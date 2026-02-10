/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:25:29 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/10 10:55:33 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	public:
		Contact();

		void setFirstName(const std::string &value);
		void setLastName(const std::string &value);
		void setNickName(const std::string &value);
		void setPhoneNumber(const std::string &value);
		void setDarkestSecret(const std::string &value);

		const std::string &getFirstName() const;
		const std::string &getLastName() const;
		const std::string &getNickName() const;
		const std::string &getPhoneNumber() const;
		const std::string &getDarkestSecret() const;

		void print() const;

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
