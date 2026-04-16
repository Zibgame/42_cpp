/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:09:15 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 16:12:15 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) const
{
    double val = std::atof(value.c_str());
    if (val < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }

    getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;

        getline(ss, date, ',');
        getline(ss, value);

        _data[date] = std::atof(value.c_str());
    }
}

double BitcoinExchange::getRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date)
        return it->second;

    if (it == _data.begin())
        throw std::runtime_error("Error: no valid date.");

    it--;
    return it->second;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;

        if (!getline(ss, date, '|') || !getline(ss, value))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = trim(date);
        value = trim(value);

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidValue(value))
            continue;

        double val = std::atof(value.c_str());

        try
        {
            double rate = getRate(date);
            std::cout << date << " => " << val << " = " << val * rate << std::endl;
        }
        catch (...)
        {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
}
