/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:09:01 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/12 13:01:08 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
	std::cout << GREEN "Bureaucrat " << this->name << " created\n" OFF;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name)
{
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	this->grade = src.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED "Bureaucrat " << this->name << " destroyed\n" OFF;
}

int Bureaucrat::GetGrade(void) const
{
	return (this->grade);
}

std::string Bureaucrat::GetName(void) const
{
	return (this->name);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void Bureaucrat::IncrementGrade(void)
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::DecrementGrade(void)
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

void Bureaucrat::SignForm(AForm& form)
{
	try
	{
		form.BeSigned(*this);
		std::cout << this->name << " signed " << form.GetName() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cout << this->name << " could not sign " << form.GetName() << " because: " << exception.what() << std::endl;
	}
}

void Bureaucrat::ExecuteForm(const AForm& form) const
{
	std::cout << this->name << " executed " << form.GetName() << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& instance)
{
	stream << instance.GetName() << ", bureaucrat grade " << instance.GetGrade() << std::endl;
	return (stream);
}