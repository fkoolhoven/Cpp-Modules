/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:04:41 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/01/31 18:50:18 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string name, int grade_to_sign, int grade_to_execute) : name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
	else
		this->is_signed = false;
	std::cout << GREEN "Form " << this->name << " created" OFF << std::endl;
}

Form::Form(const Form& src) : name(src.name), grade_to_sign(src.grade_to_sign), grade_to_execute(src.grade_to_execute)
{
	*this = src;
}

Form& Form::operator=(const Form& src) // override const?
{
	this->is_signed = src.is_signed;
	return (*this);
}

Form::~Form(void)
{
	std::cout << RED "Form " << this->name << " destroyed" OFF << std::endl;
}

std::string Form::GetName(void) const
{
	return (this->name);
}

bool Form::GetIsSigned(void) const
{
	return (this->is_signed);
}

int Form::GetGradeToSign(void) const
{
	return (this->grade_to_sign);
}

int Form::GetGradeToExecute(void) const
{
	return (this->grade_to_execute);
}

void Form::BeSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.GetGrade() > this->grade_to_sign)
		throw Form::GradeTooLowException();
	else
		this->is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& stream, const Form& instance)
{
	std::string is_signed = instance.GetIsSigned() ? "true" : "false";

	stream << "Form name: " << instance.GetName() << std::endl;
	stream << "Is signed: " << is_signed << std::endl;
	stream << "Grade to sign: " << instance.GetGradeToSign() << std::endl;
	stream << "Grade to exec: " << instance.GetGradeToExecute() << std::endl;
	return (stream);
}