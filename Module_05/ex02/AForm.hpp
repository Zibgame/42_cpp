/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:54:48 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/07 13:54:50 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeSign;
	const int _gradeExec;

public:
	AForm(const std::string name, int gradeSign, int gradeExec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string getName() const;
	bool isSigned() const;
	int getGradeSign() const;
	int getGradeExec() const;

	void beSigned(const Bureaucrat& b);
	void execute(Bureaucrat const & executor) const;

	virtual void executeAction() const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const AForm& f);

#endif
