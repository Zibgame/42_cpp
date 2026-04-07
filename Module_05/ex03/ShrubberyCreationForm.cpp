/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:55:38 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/07 13:55:39 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
		return;
	file << "  /\\\n";
	file << " /**\\\n";
	file << "/****\\\n";
	file << "  ||\n";
}
