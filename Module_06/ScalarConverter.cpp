/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:09:19 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/07 16:37:18 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <iomanip>

static int isPseudo(const std::string& s)
{
    if (s == "nan" || s == "nanf"
        || s == "+inf" || s == "+inff"
        || s == "-inf" || s == "-inff")
        return (1);
    return (0);
}

static void printPseudo(const std::string& s)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (s[s.length() - 1] == 'f')
    {
        std::cout << "float: " << s << std::endl;
        std::cout << "double: " << s.substr(0, s.length() - 1) << std::endl;
    }
    else
    {
        std::cout << "float: " << s << "f" << std::endl;
        std::cout << "double: " << s << std::endl;
    }
}

static int isChar(const std::string& s)
{
    if (s.length() == 1 && !isdigit(s[0]))
        return (1);
    return (0);
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudo(literal))
    {
        printPseudo(literal);
        return;
    }

    std::cout << std::fixed << std::setprecision(1);

    double value;

    if (isChar(literal))
        value = static_cast<double>(literal[0]);
    else
        value = std::strtod(literal.c_str(), NULL);

    if (value < 32 || value > 126)
        std::cout << "char: Non displayable" << std::endl;
    else if (value != value)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (value > std::numeric_limits<int>::max()
        || value < std::numeric_limits<int>::min()
        || value != value)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}
