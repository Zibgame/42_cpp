/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:20:52 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/01 17:03:31 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
std::cout << "=== VALID CREATION ===" << std::endl;
try
{
Bureaucrat a("Alice", 42);
std::cout << a << std::endl;
}
catch (std::exception &e)
{
std::cout << e.what() << std::endl;
}

std::cout << "\n=== INVALID HIGH (0) ===" << std::endl;
try
{
    Bureaucrat b("Bob", 0);
}
catch (std::exception &e)
{
    std::cout << e.what() << std::endl;
}

std::cout << "\n=== INVALID LOW (151) ===" << std::endl;
try
{
    Bureaucrat c("Charlie", 151);
}
catch (std::exception &e)
{
    std::cout << e.what() << std::endl;
}

std::cout << "\n=== INCREMENT TEST ===" << std::endl;
try
{
    Bureaucrat d("David", 2);
    std::cout << d << std::endl;
    d.incrementGrade();
    std::cout << d << std::endl;
    d.incrementGrade();
}
catch (std::exception &e)
{
    std::cout << e.what() << std::endl;
}

std::cout << "\n=== DECREMENT TEST ===" << std::endl;
try
{
    Bureaucrat e("Eve", 149);
    std::cout << e << std::endl;
    e.decrementGrade();
    std::cout << e << std::endl;
    e.decrementGrade();
}
catch (std::exception &e)
{
    std::cout << e.what() << std::endl;
}

return 0;
}
