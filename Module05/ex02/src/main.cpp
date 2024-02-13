/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/13 14:34:36 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void TestPresidentialPardonForm()
{
	std::cout << YELLOW BOLD "Testing PresidentialPardonForm: grade too low\n" OFF;
	PresidentialPardonForm presidential("Felicia");
	Bureaucrat bureaucrat("Bureaucrat", 6);
	bureaucrat.SignForm(presidential);
	bureaucrat.ExecuteForm(presidential);

	std::cout << YELLOW BOLD "\nTesting PresidentialPardonForm: form not signed\n" OFF;
	{
		PresidentialPardonForm unsigned_form("Target");
		bureaucrat.IncrementGrade();
		bureaucrat.ExecuteForm(unsigned_form);
	}
	
	std::cout << YELLOW BOLD "\nTesting PresidentialPardonForm: succesful execute\n" OFF;
	bureaucrat.ExecuteForm(presidential);
}

void TestRobotomyRequestForm()
{
	std::cout << YELLOW BOLD "Testing RobotomyRequestForm: grade too low\n" OFF;
	RobotomyRequestForm robotomy("Yoda");
	Bureaucrat bureaucrat("Bureaucrat", 46);
	bureaucrat.SignForm(robotomy);
	bureaucrat.ExecuteForm(robotomy);

	std::cout << YELLOW BOLD "\nTesting RobotomyRequestForm: form not signed\n" OFF;
	{
		RobotomyRequestForm unsigned_form("Target");
		bureaucrat.IncrementGrade();
		bureaucrat.ExecuteForm(unsigned_form);
	}
	
	std::cout << YELLOW BOLD "\nTesting RobotomyRequestForm: succesful execute\n" OFF;
	bureaucrat.ExecuteForm(robotomy);
}

void TestShrubberyCreationForm()
{
	std::cout << YELLOW BOLD "Testing ShrubberyCreationForm: grade too low\n" OFF;
	ShrubberyCreationForm shrubbery("Tree");
	Bureaucrat bureaucrat("Bureaucrat", 138);
	bureaucrat.SignForm(shrubbery);
	bureaucrat.ExecuteForm(shrubbery);

	std::cout << YELLOW BOLD "\nTesting ShrubberyCreationForm: form not signed\n" OFF;
	{
		ShrubberyCreationForm unsigned_form("Target");
		bureaucrat.IncrementGrade();
		bureaucrat.ExecuteForm(unsigned_form);
	}
	
	std::cout << YELLOW BOLD "\nTesting ShrubberyCreationForm: succesful execute\n" OFF;
	bureaucrat.ExecuteForm(shrubbery);
}

void TestFormCopy()
{
	std::cout << YELLOW BOLD "Testing copy constructor and assignment operator" OFF << std::endl;
	
	ShrubberyCreationForm	shrubbery("Target");
	ShrubberyCreationForm	shrubbery_copy1 = shrubbery;
	ShrubberyCreationForm	shrubbery_copy2(shrubbery);
	
	std::cout << shrubbery << std::endl;
	std::cout << shrubbery_copy1 << std::endl;
	std::cout << shrubbery_copy2 << std::endl;
}

void TestFormConstructionDestruction(void)
{
	std::cout << YELLOW BOLD "Testing construction/destruction" OFF << std::endl;
	
	// AForm abstract_form("Abstract form", 100, 100); // This line will not compile
	ShrubberyCreationForm	shrubbery_creation("Target");
	RobotomyRequestForm		robotomy_request("Target");
	PresidentialPardonForm	presidential_pardon("Target");
	
	std::cout << shrubbery_creation << std::endl;
	std::cout << robotomy_request << std::endl;
	std::cout << presidential_pardon << std::endl;
}

int main(void)
{
	TestFormConstructionDestruction();
	std::cout << std::endl;
	TestFormCopy();
	std::cout << std::endl;
	TestShrubberyCreationForm();
	std::cout << std::endl;
	TestRobotomyRequestForm();
	std::cout << std::endl;
	TestPresidentialPardonForm();
	return (EXIT_SUCCESS);
}