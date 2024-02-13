/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:02:30 by felicia           #+#    #+#             */
/*   Updated: 2024/02/12 14:12:53 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << GREEN << "PresidentialPardonForm created\n" OFF;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), target(src.target)
{
	std::cout << GREEN << "PresidentialPardonForm copied\n" OFF;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED << "PresidentialPardonForm destroyed\n" OFF;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	AForm::operator=(src);
	this->target = src.target;
	return (*this);
}

void PresidentialPardonForm::Execute(const Bureaucrat& executor) const
{
	try
	{
		AForm::Execute(executor);
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
	}
}
