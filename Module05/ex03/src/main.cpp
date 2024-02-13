/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/13 14:48:00 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void TestIfFormStillWorks(void)
{
	std::cout << YELLOW BOLD "Testing if form still works\n" OFF;
	
	try
	{
		Bureaucrat 	Bureaucrat("Ziggy", 5);
		Intern		unpaid_intern;
		AForm*		form;
		
		form = unpaid_intern.MakeForm("presidential pardon", "Felicia");
		Bureaucrat.SignForm(*form);
		std::cout << std::endl << *form << std::endl;
		Bureaucrat.ExecuteForm(*form);
		delete form;
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
	}
}

void TestUnsuccesfulFormCreation(void)
{
	std::cout << YELLOW BOLD "Testing Intern unsuccesfully creating forms\n" OFF;
	Intern	unpaid_intern;
    AForm*	form;

	try
	{
		form = unpaid_intern.MakeForm("fake form", "Bender");
		std::cout << *form;
		form = unpaid_intern.MakeForm("not a form", "Bender");
		std::cout << *form;
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
	}
}

void TestSuccesfulFormCreation(void)
{
	std::cout << YELLOW BOLD "Testing Intern succesfully creating forms\n" OFF;
	Intern	unpaid_intern;
	AForm*	form;

	try
	{
		form = unpaid_intern.MakeForm("robotomy request", "Bender");
		std::cout << *form;
		delete form;
		std::cout << std::endl;
		form = unpaid_intern.MakeForm("shrubbery creation", "Bender");
		std::cout << *form;
		delete form;
		std::cout << std::endl;
		form = unpaid_intern.MakeForm("presidential pardon", "Bender");
		std::cout << *form;
		delete form;
	}
	catch (std::exception& exception)
	{
		std::cout << "This code won't be executed\n";
		std::cerr << "An exception was caught! " << exception.what() << std::endl;
	}
}

int main(void)
{
	TestSuccesfulFormCreation();
	std::cout << std::endl;
	TestUnsuccesfulFormCreation();
	std::cout << std::endl;
	TestIfFormStillWorks();
	return (EXIT_SUCCESS);
}