/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:02:46 by felicia           #+#    #+#             */
/*   Updated: 2024/02/13 14:27:21 by fkoolhov         ###   ########.fr       */
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
	AForm::Execute(executor);
	std::cout << "DRILL.\nDRILL..\nDRILL...\n";
	std::srand(time(NULL));
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully\n";
	else
		std::cout << "Too bad! " << this->target << " has not been robotomized\n";
}
