/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/20 11:55:33 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void TestSuccesfullDecrementing(void)
{
	std::cout << YELLOW BOLD "Testing successful decrementing" OFF << std::endl;
	Bureaucrat donna("Donna", 33);
	std::cout << donna;
	donna.DecrementGrade();
	std::cout << donna;
}

void TestGradeTooLowAfterDecrementing(void)
{
	std::cout << YELLOW BOLD "Testing GradeTooLowException after decrementing" OFF << std::endl;
	try
	{
		Bureaucrat donna("Donna", 150);
		std::cout << donna;
		donna.DecrementGrade();
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
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
		std::cerr << "An exception was caught! " << exception.what();
	}
}

void TestSuccesfullIncrementing(void)
{
	std::cout << YELLOW BOLD "Testing successful incrementing" OFF << std::endl;
	Bureaucrat alice("Alice", 33);
	std::cout << alice;
	alice.IncrementGrade();
	std::cout << alice;
}

void TestGradeTooHighAfterIncrementing(void)
{
	std::cout << YELLOW BOLD "Testing GradeTooHighException after incrementing" OFF << std::endl;
	try
	{
		Bureaucrat caroline("Caroline", 1);
		std::cout << caroline;
		caroline.IncrementGrade();
		std::cout << "This code won't be executed\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
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
		std::cerr << "An exception was caught! " << exception.what();
	}
}

void TestBasics(void)
{
	std::cout << YELLOW BOLD "Testing the basics" OFF << std::endl;
	Bureaucrat whitney("Whitney", 1);
	Bureaucrat whitney_copy("whitney_copy", 5);
	whitney_copy = whitney;
	Bureaucrat janet("Janet", 150);
	Bureaucrat janet_copy(janet);
	std::cout << whitney;
	std::cout << whitney_copy;
	std::cout << janet;
	std::cout << janet_copy;
}

int main(void)
{
	TestBasics();
	std::cout << std::endl;
	TestGradeTooHighAtConstruction();
	std::cout << std::endl;
	TestGradeTooHighAfterIncrementing();
	std::cout << std::endl;
	TestSuccesfullIncrementing();
	std::cout << std::endl;
	TestGradeTooLowAtConstruction();
	std::cout << std::endl;
	TestGradeTooLowAfterDecrementing();
	std::cout << std::endl;
	TestSuccesfullDecrementing();
	return (EXIT_SUCCESS);
}