/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/13 14:05:01 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void TestUnableToSign()
{
	std::cout << YELLOW BOLD "Testing inability to sign" OFF << std::endl;
	Form form("Form", 30, 150);
	Bureaucrat signer("Signer", 31);
	std::cout << form << std::endl;
	std::cout << signer << std::endl;
	signer.SignForm(form);
	std::cout << std::endl << form << std::endl;
}

void TestSuccesfulSign()
{
	std::cout << YELLOW BOLD "Testing succesful sign" OFF << std::endl;
	Form form("Form", 30, 150);
	Bureaucrat signer("Signer", 30);
	std::cout << form << std::endl;
	std::cout << signer << std::endl;
	signer.SignForm(form);
	std::cout << std::endl << form << std::endl;
}

void TestFormGradeTooLowAtConstruction(void)
{
	std::cout << YELLOW BOLD "Testing sign grade GradeTooLowException at construction" OFF << std::endl;
	try
	{
		Form form("Form", 151, 40);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
	}

	std::cout << YELLOW BOLD "\nTesting exec grade GradeTooLowException at construction" OFF << std::endl;
	try
	{
		Form form("Form", 20, 151);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
	}
}

void TestFormGradeTooHighAtConstruction(void)
{
	std::cout << YELLOW BOLD "Testing sign grade GradeTooHighException at construction" OFF << std::endl;
	try
	{
		Form form("Form", 0, 40);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
	}
	
	std::cout << YELLOW BOLD "\nTesting exec grade GradeTooHighException at construction" OFF << std::endl;
	try
	{
		Form form("Form", 20, 0);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
	}
}

void TestFormConstructionDestruction(void)
{
	std::cout << YELLOW BOLD "Testing construction/destruction" OFF << std::endl;
	Form boring("Boring form", 150, 150);
	Form exciting("Exciting form", 1, 1);
	std::cout << boring << std::endl;
	std::cout << exciting << std::endl;

	Form copy(exciting);
	std::cout << copy << std::endl;

	Form copy2 = exciting;
	std::cout << copy2 << std::endl;
}

int main(void)
{
	TestFormConstructionDestruction();
	std::cout << std::endl;
	TestFormGradeTooHighAtConstruction();
	std::cout << std::endl;
	TestFormGradeTooLowAtConstruction();
	std::cout << std::endl;
	TestSuccesfulSign();
	std::cout << std::endl;
	TestUnableToSign();
	return (EXIT_SUCCESS);
}