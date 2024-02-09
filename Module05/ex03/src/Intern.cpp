/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:24:12 by felicia           #+#    #+#             */
/*   Updated: 2024/02/09 14:07:52 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << GREEN "An intern was created\n" OFF;
}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern::~Intern(void)
{
	std::cout << RED "An intern was destroyed\n" OFF;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

AForm* Intern::MakeForm(std::string formName, std::string target)
{
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int type;

	for (type = 0; type < 3; type++)
	{
		if (formName == forms[type])
		{
			std::cout << GREEN "Intern creates " << formName << " form\n" OFF;
			break ;
		}
	}
	
	switch (type)
	{
		case SHRUBBERY_CREATION:
			return (new ShrubberyCreationForm(target));
		case ROBOTOMY_REQUEST:
			return (new RobotomyRequestForm(target));
		case PRESIDENTIAL_PARDON:
			return (new PresidentialPardonForm(target));
		default:
			throw FormDoesNotExist();
	}
}

const char* Intern::FormDoesNotExist::what() const throw()
{
	return ("Form does not exist\n");
}
