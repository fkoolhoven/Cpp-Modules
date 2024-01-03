/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/01/03 19:30:36 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void TestGradeTooLowAfterDecrementing(void)
{
	std::cout << YELLOW BOLD "Testing GradeTooLowException after decrementing" OFF << std::endl;
	try
	{
		Bureaucrat donna("Donna", 150);
		std::cout << donna << std::endl;
		donna.DecrementGrade();
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cout << "An exception was caught!\n";
		std::cerr << exception.what() << std::endl;
	}
}

void TestGradeTooLowAtConstruction(void)
{
	std::cout << YELLOW BOLD "Testing GradeTooLowException at construction" OFF << std::endl;
	try
	{
		Bureaucrat lily("Lily", 151);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cout << "An exception was caught!\n";
		std::cerr << exception.what() << std::endl;
	}
}

void TestGradeTooHighAfterIncrementing(void)
{
	std::cout << YELLOW BOLD "Testing GradeTooHighException after incrementing" OFF << std::endl;
	try
	{
		Bureaucrat caroline("Caroline", 1);
		std::cout << caroline << std::endl;
		caroline.IncrementGrade();
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cout << "An exception was caught!\n";
		std::cerr << exception.what() << std::endl;
	}
}

void TestGradeTooHighAtConstruction(void)
{
	std::cout << YELLOW BOLD "Testing GradeTooHighException at construction" OFF << std::endl;
	try
	{
		Bureaucrat bonnie("Bonnie", 0);
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cout << "An exception was caught!\n";
		std::cerr << exception.what() << std::endl;
	}
}


void TestBasics(void)
{
	std::cout << YELLOW BOLD "Testing the basics" OFF << std::endl;
	Bureaucrat whitney("Whitney", 1);
	Bureaucrat kate("Kate", 50);
	Bureaucrat janet("Janet", 150);
	std::cout << whitney << std::endl;
	std::cout << kate << std::endl;
	std::cout << janet << std::endl;
}

int main(void)
{
	TestBasics();
	std::cout << std::endl;
	TestGradeTooHighAtConstruction();
	std::cout << std::endl;
	TestGradeTooHighAfterIncrementing();
	std::cout << std::endl;
	TestGradeTooLowAtConstruction();
	std::cout << std::endl;
	TestGradeTooLowAfterDecrementing();
}