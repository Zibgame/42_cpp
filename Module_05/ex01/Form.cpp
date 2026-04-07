/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:28:02 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/07 13:48:34 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int gradeSign, int gradeExec)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed),
	  _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form() {}

const std::string Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getGradeSign() const { return _gradeSign; }
int Form::getGradeExec() const { return _gradeExec; }

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

std::ostream& operator<<(std::ostream& o, const Form& f)
{
	o << f.getName()
	  << ", signed: " << f.isSigned()
	  << ", grade sign: " << f.getGradeSign()
	  << ", grade exec: " << f.getGradeExec();
	return o;
}
