/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/20 12:11:17 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void TestPresidentialPardonForm()
{
	std::cout << YELLOW BOLD "Testing PresidentialPardonForm: grade too low to execute\n" OFF;
	PresidentialPardonForm presidential("Felicia");
	Bureaucrat bureaucrat("Bureaucrat", 6);
	bureaucrat.SignForm(presidential);
	std::cout << std::endl << presidential << std::endl;
	std::cout << bureaucrat << std::endl;
	bureaucrat.ExecuteForm(presidential);

	std::cout << YELLOW BOLD "\nTesting PresidentialPardonForm: can't execute because form not signed\n" OFF;
	{
		PresidentialPardonForm unsigned_form("Target");
		std::cout << std::endl << unsigned_form << std::endl;
		bureaucrat.IncrementGrade();
		bureaucrat.ExecuteForm(unsigned_form);
	}
	
	std::cout << YELLOW BOLD "\nTesting PresidentialPardonForm: succesful execute\n" OFF;
	bureaucrat.ExecuteForm(presidential);
}

void TestRobotomyRequestForm()
{
	std::cout << YELLOW BOLD "Testing RobotomyRequestForm: grade too low to execute\n" OFF;
	RobotomyRequestForm robotomy("Yoda");
	Bureaucrat bureaucrat("Bureaucrat", 46);
	bureaucrat.SignForm(robotomy);
	std::cout << std::endl << robotomy << std::endl;
	std::cout << bureaucrat << std::endl;
	bureaucrat.ExecuteForm(robotomy);

	std::cout << YELLOW BOLD "\nTesting RobotomyRequestForm: can't execute because form not signed\n" OFF;
	{
		RobotomyRequestForm unsigned_form("Target");
		std::cout << std::endl << unsigned_form << std::endl;
		bureaucrat.IncrementGrade();
		bureaucrat.ExecuteForm(unsigned_form);
	}
	
	std::cout << YELLOW BOLD "\nTesting RobotomyRequestForm: succesful execute\n" OFF;
	bureaucrat.ExecuteForm(robotomy);
}

void TestShrubberyCreationForm()
{
	std::cout << YELLOW BOLD "Testing ShrubberyCreationForm: grade too low to execute\n" OFF;
	ShrubberyCreationForm shrubbery("Tree");
	Bureaucrat bureaucrat("Bureaucrat", 138);
	bureaucrat.SignForm(shrubbery);
	std::cout << std::endl << shrubbery << std::endl;
	std::cout << bureaucrat << std::endl;
	bureaucrat.ExecuteForm(shrubbery);

	std::cout << YELLOW BOLD "\nTesting ShrubberyCreationForm: can't execute because form not signed\n" OFF;
	{
		ShrubberyCreationForm unsigned_form("Target");
		std::cout << std::endl << unsigned_form << std::endl;
		bureaucrat.IncrementGrade();
		bureaucrat.ExecuteForm(unsigned_form);
	}
	
	std::cout << YELLOW BOLD "\nTesting ShrubberyCreationForm: succesful execute\n" OFF;
	bureaucrat.ExecuteForm(shrubbery);
}

void TestFormCopy()
{
	std::cout << YELLOW BOLD "Testing copy constructor" OFF << std::endl;
	
	ShrubberyCreationForm	shrubbery("Target");
	ShrubberyCreationForm	shrubbery_copy(shrubbery);
	
	std::cout << shrubbery << std::endl;
	std::cout << shrubbery_copy << std::endl;
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