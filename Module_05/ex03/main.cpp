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
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Intern intern;
	AForm* form;
	std::srand(std::time(NULL));

	form = intern.makeForm("robotomy request", "Bender");

	if (form)
	{
		Bureaucrat boss("Boss", 1);

		boss.signForm(*form);
		boss.executeForm(*form);

		delete form;
	}
}