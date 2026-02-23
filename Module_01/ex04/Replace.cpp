/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:24:33 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/23 14:24:35 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>
#include <iostream>

Replace::Replace(const std::string& filename,
                 const std::string& s1,
                 const std::string& s2)
	: _filename(filename), _s1(s1), _s2(s2)
{
}

std::string Replace::readFile(void) const
{
	std::ifstream file(_filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open file." << std::endl;
		return "";
	}

	std::string content;
	std::string line;

	while (std::getline(file, line))
	{
		content += line;
		if (!file.eof())
			content += "\n";
	}
	file.close();
	return content;
}

std::string Replace::replaceAll(const std::string& content) const
{
	if (_s1.empty())
		return content;

	std::string result;
	std::size_t pos = 0;
	std::size_t found;

	while ((found = content.find(_s1, pos)) != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result += _s2;
		pos = found + _s1.length();
	}
	result.append(content, pos, content.length() - pos);
	return result;
}

bool Replace::writeFile(const std::string& content) const
{
	std::ofstream file((_filename + ".replace").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: cannot create output file." << std::endl;
		return false;
	}

	file << content;
	file.close();
	return true;
}

bool Replace::process(void) const
{
	std::string content = readFile();
	if (content.empty() && !_s1.empty())
	{
		std::ifstream check(_filename.c_str());
		if (!check.good())
			return false;
		check.close();
	}
	std::string replaced = replaceAll(content);
	return writeFile(replaced);
}
