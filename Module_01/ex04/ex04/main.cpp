/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:16:37 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/16 15:49:46 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:16:37 by zcadinot          #+#    #+#             */
/*   Updated: 2026/02/16                                     +#+#+#+#+#+   */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << BRED
		          << "❌ Error: Invalid number of arguments.\n"
		          << "Usage: ./replace <filename> <s1> <s2>"
		          << RESET << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << BRED
		          << "❌ Error: s1 cannot be empty."
		          << RESET << std::endl;
		return (1);
	}

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << BRED
		          << "❌ Error: Cannot open file -> "
		          << RESET << filename << std::endl;
		return (1);
	}

	std::ostringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();
	infile.close();

	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content.substr(pos, found - pos));
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content.substr(pos));

	std::string newname = filename + ".replace";
	std::ofstream outfile(newname.c_str());
	if (!outfile.is_open())
	{
		std::cerr << BRED
		          << "❌ Error: Cannot create output file."
		          << RESET << std::endl;
		return (1);
	}

	outfile << result;
	outfile.close();

	return (0);
}
