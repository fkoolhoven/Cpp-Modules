/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:02:46 by felicia           #+#    #+#             */
/*   Updated: 2024/02/12 13:54:49 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << GREEN << "RobotomyRequestForm created\n" OFF;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), target(src.target)
{
	std::cout << GREEN << "RobotomyRequestForm copied\n" OFF;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED << "RobotomyRequestForm destroyed\n" OFF;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	AForm::operator=(src);
	this->target = src.target;
	return (*this);
}

void RobotomyRequestForm::Execute(const Bureaucrat& executor) const
{
	try
	{
		AForm::Execute(executor);
		std::cout << "DRILL.\nDRILL..\nDRILL...\n";
		std::srand(time(NULL));
		if (std::rand() % 2)
			std::cout << this->target << " has been robotomized successfully\n";
		else
			std::cout << "Too bad! " << this->target << " has not been robotomized\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
	}
}
