/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:04:41 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/13 14:33:50 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int grade_to_sign, int grade_to_execute) : name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	else
		this->is_signed = false;
	std::cout << GREEN "Form " << this->name << " created" OFF << std::endl;
}

AForm::AForm(const AForm& src) : name(src.name + "_copy"), is_signed(src.is_signed), grade_to_sign(src.grade_to_sign), grade_to_execute(src.grade_to_execute)
{
	*this = src;
}

AForm& AForm::operator=(const AForm& src)
{
	this->is_signed = src.is_signed;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << RED "Form " << this->name << " destroyed" OFF << std::endl;
}

std::string AForm::GetName(void) const
{
	return (this->name);
}

bool AForm::GetIsSigned(void) const
{
	return (this->is_signed);
}

int AForm::GetGradeToSign(void) const
{
	return (this->grade_to_sign);
}

int AForm::GetGradeToExecute(void) const
{
	return (this->grade_to_execute);
}

void AForm::BeSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.GetGrade() > this->grade_to_sign)
		throw AForm::GradeTooLowException();
	else
		this->is_signed = true;
}

void AForm::Execute(const Bureaucrat& executor) const
{
	if (!this->is_signed)
		throw AForm::FormNotSignedException();
	else if (executor.GetGrade() > this->grade_to_execute)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low\n");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed\n");
}

std::ostream& operator<<(std::ostream& stream, const AForm& instance)
{
	std::string is_signed = instance.GetIsSigned() ? "true" : "false";

	stream << "Form name: " << instance.GetName() << std::endl;
	stream << "Is signed: " << is_signed << std::endl;
	stream << "Grade to sign: " << instance.GetGradeToSign() << std::endl;
	stream << "Grade to exec: " << instance.GetGradeToExecute() << std::endl;
	return (stream);
}