/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:27:57 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/07 13:55:09 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm& form);
	void executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

#endif
