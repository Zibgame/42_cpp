/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:28:13 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/07 13:56:26 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);

	ShrubberyCreationForm s("home");
	RobotomyRequestForm r("Bender");
	PresidentialPardonForm p("Arthur");

	boss.signForm(s);
	boss.executeForm(s);

	boss.signForm(r);
	boss.executeForm(r);

	boss.signForm(p);
	boss.executeForm(p);
}
