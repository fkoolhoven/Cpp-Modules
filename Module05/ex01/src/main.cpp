/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/01/31 18:57:07 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void TestUnableToSign()
{
	std::cout << YELLOW BOLD "FORM Testing inability to sign" OFF << std::endl;
	Form form("Form", 30, 150);
	Bureaucrat signer("Signer", 31);
	std::cout << form << std::endl;
	std::cout << signer << std::endl;
	signer.SignForm(form);
	std::cout << std::endl << form << std::endl;
}

void TestSuccesfulSign()
{
	std::cout << YELLOW BOLD "FORM Testing succesful sign" OFF << std::endl;
	Form form("Form", 30, 150);
	Bureaucrat signer("Signer", 30);
	std::cout << form << std::endl;
	std::cout << signer << std::endl;
	signer.SignForm(form);
	std::cout << std::endl << form << std::endl;
}

void TestFormGradeTooLowAtConstruction(void)
{
	std::cout << YELLOW BOLD "FORM Testing GradeTooLowException at construction" OFF << std::endl;
	try
	{
		Form form("Form", 151, 40);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cout << "An exception was caught! ";
		std::cerr << exception.what() << std::endl;
	}
	try
	{
		Form form("Form", 20, 151);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! ";
		std::cerr << exception.what() << std::endl;
	}
}

void TestFormGradeTooHighAtConstruction(void)
{
	std::cout << YELLOW BOLD "FORM Testing GradeTooHighException at construction" OFF << std::endl;
	try
	{
		Form form("Form", 0, 150);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! ";
		std::cerr << exception.what() << std::endl;
	}
	try
	{
		Form form("Form", 20, 0);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! ";
		std::cerr << exception.what() << std::endl;
	}
}

void TestFormConstructionDestruction(void)
{
	std::cout << YELLOW BOLD "FORM Testing construction/destruction" OFF << std::endl;
	Form boring("Boring form", 150, 150);
	Form exciting("Exciting form", 1, 1);
	std::cout << boring << std::endl;
	std::cout << exciting << std::endl;
}
int main(void)
{
	// TestsFromPreviousExercise();
	// std::cout << std::endl;
	TestFormConstructionDestruction();
	std::cout << std::endl;
	TestFormGradeTooHighAtConstruction();
	std::cout << std::endl;
	TestFormGradeTooLowAtConstruction();
	std::cout << std::endl;
	TestSuccesfulSign();
	std::cout << std::endl;
	TestUnableToSign();
}