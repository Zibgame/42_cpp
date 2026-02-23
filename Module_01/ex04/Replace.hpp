/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:24:36 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/23 14:24:38 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

class Replace
{
private:
	std::string _filename;
	std::string _s1;
	std::string _s2;

	std::string readFile(void) const;
	std::string replaceAll(const std::string& content) const;
	bool writeFile(const std::string& content) const;

public:
	Replace(const std::string& filename,
	        const std::string& s1,
	        const std::string& s2);

	bool process(void) const;
};

#endif
