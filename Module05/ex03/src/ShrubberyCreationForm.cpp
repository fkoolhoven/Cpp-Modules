/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:02:53 by felicia           #+#    #+#             */
/*   Updated: 2024/02/13 14:41:53 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm created\n" OFF;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.target)
{
	std::cout << GREEN << "ShrubberyCreationForm copied\n" OFF;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED << "ShrubberyCreationForm destroyed\n" OFF;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	AForm::operator=(src);
	this->target = src.target;
	return (*this);
}

void ShrubberyCreationForm::Execute(const Bureaucrat& executor) const
{
	AForm::Execute(executor);
	std::ofstream file(this->target + "_shrubbery");
	file << "      /\\      \n";
	file << "     /\\*\\     \n";
	file << "    /\\O\\*\\    \n";
	file << "   /*/\\/\\/\\   \n";
	file << "  /\\O\\/\\*\\/\\  \n";
	file << " /\\*\\/\\*\\/\\/\\ \n";
	file << "/\\O\\/\\/*/\\/O/\\ \n";
	file << "      ||      \n";
	file << "      ||      \n";
	file << "      ||      ";
	file.close();
	std::cout << "Shrubbery has been created in " << this->target << "_shrubbery\n";
}
