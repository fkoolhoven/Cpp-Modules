/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/08 17:34:07 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void TestPresidentialPardonForm()
{
	std::cout << YELLOW BOLD "Testing PresidentialPardonForm: grade too low\n" OFF;
	PresidentialPardonForm shrubbery("Felicia");
	Bureaucrat bureaucrat("Bureaucrat", 6);
	shrubbery.BeSigned(bureaucrat);
	shrubbery.Execute(bureaucrat);

	std::cout << YELLOW BOLD "\nTesting PresidentialPardonForm: form not signed\n" OFF;
	{
		PresidentialPardonForm unsigned_form("Target");
		bureaucrat.IncrementGrade();
		unsigned_form.Execute(bureaucrat);
	}
	
	std::cout << YELLOW BOLD "\nTesting PresidentialPardonForm: succesful execute\n" OFF;
	shrubbery.BeSigned(bureaucrat);
	shrubbery.Execute(bureaucrat);
}

void TestRobotomyRequestForm()
{
	std::cout << YELLOW BOLD "Testing RobotomyRequestForm: grade too low\n" OFF;
	RobotomyRequestForm shrubbery("Yoda");
	Bureaucrat bureaucrat("Bureaucrat", 46);
	shrubbery.BeSigned(bureaucrat);
	shrubbery.Execute(bureaucrat);

	std::cout << YELLOW BOLD "\nTesting RobotomyRequestForm: form not signed\n" OFF;
	{
		RobotomyRequestForm unsigned_form("Target");
		bureaucrat.IncrementGrade();
		unsigned_form.Execute(bureaucrat);
	}
	
	std::cout << YELLOW BOLD "\nTesting RobotomyRequestForm: succesful execute\n" OFF;
	shrubbery.BeSigned(bureaucrat);
	shrubbery.Execute(bureaucrat);
}

void TestShrubberyCreationForm()
{
	std::cout << YELLOW BOLD "Testing ShrubberyCreationForm: grade too low\n" OFF;
	ShrubberyCreationForm shrubbery("Tree");
	Bureaucrat bureaucrat("Bureaucrat", 138);
	shrubbery.BeSigned(bureaucrat);
	shrubbery.Execute(bureaucrat);

	std::cout << YELLOW BOLD "\nTesting ShrubberyCreationForm: form not signed\n" OFF;
	{
		ShrubberyCreationForm unsigned_form("Target");
		bureaucrat.IncrementGrade();
		unsigned_form.Execute(bureaucrat);
	}
	
	std::cout << YELLOW BOLD "\nTesting ShrubberyCreationForm: succesful execute\n" OFF;
	shrubbery.BeSigned(bureaucrat);
	shrubbery.Execute(bureaucrat);
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
	ShrubberyCreationForm	shrubbery("Target");
	RobotomyRequestForm		robotomy("Target");
	PresidentialPardonForm	presidential_pardon("Target");
	
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
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