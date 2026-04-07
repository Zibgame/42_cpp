/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:55:46 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/07 13:56:05 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "BZZZZ...\n";
	if (rand() % 2)
		std::cout << _target << " robotomized\n";
	else
		std::cout << "robotomy failed\n";
}
