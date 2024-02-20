/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:53:19 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/20 17:51:17 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void TestContainerFullWithManyNumbers(void)
{
	std::cout << YELLOW BOLD "Testing FullContainer exception with many numbers\n" OFF;
	try
	{
		Span span(10000);
		std::vector<int> numbers(10001);

		for (int i = 0; i < 10001; i++)
			numbers[i] = i;
		
		span.AddMultipleNumbers(numbers.begin(), numbers.end());
		
		std::cout << "Shortest span: " << span.ShortestSpan() << std::endl;
		std::cout << "Longest span: " << span.LongestSpan() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

void TestWithManyNumbers(void)
{
	std::cout << YELLOW BOLD "Testing member functions with many numbers\n" OFF;
	try
	{
		int container_size = 10000;
		Span span(container_size);
		std::vector<int> numbers(container_size);

		for (int i = 0; i < container_size; i++)
			numbers[i] = i;
		
		span.AddMultipleNumbers(numbers.begin(), numbers.end());
		
		std::cout << "Shortest span: " << span.ShortestSpan() << std::endl;
		std::cout << "Longest span: " << span.LongestSpan() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

void TestNoSpanException(void)
{
	std::cout << YELLOW BOLD "Testing NoSpan exception\n" OFF;
	try
	{
		Span span(5);
		span.AddNumber(1);
		span.ShortestSpan();
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

void TestFullContainerException(void)
{
	std::cout << YELLOW BOLD "Testing FullContainer exception\n" OFF;
	try
	{
		Span span(2);
		span.AddNumber(1);
		span.AddNumber(2);
		span.AddNumber(3);
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

void TestDeepCopy(void)
{
	std::cout << YELLOW BOLD "Testing deep copy\n" OFF;
	try
	{
		Span span1(3);
		span1.AddNumber(1);
		span1.AddNumber(2);
		
		Span span2(span1);
		span1.AddNumber(3);
		span2.AddNumber(10);

		std::cout << "1 Longest span: " << span1.LongestSpan() << std::endl;
		std::cout << "2 Longest span: " << span2.LongestSpan() << std::endl;
		
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

void TestMemberFunctions(void)
{
	std::cout << YELLOW BOLD "Testing member functions and copy\n" OFF;
	try
	{
		Span span(5);
		span.AddNumber(6);
		span.AddNumber(3);
		span.AddNumber(17);
		span.AddNumber(9);
		span.AddNumber(11);
		std::cout << "Shortest span: " << span.ShortestSpan() << std::endl;
		std::cout << "Longest span: " << span.LongestSpan() << std::endl;

		Span copy = span;
		std::cout << "Shortest span: " << copy.ShortestSpan() << std::endl;
		std::cout << "Longest span: " << copy.LongestSpan() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

int main(void)
{
	std::cout << std::endl;
	TestMemberFunctions();
	std::cout << std::endl;
	TestDeepCopy();
	std::cout << std::endl;
	TestFullContainerException();
	std::cout << std::endl;
	TestNoSpanException();
	std::cout << std::endl;
	TestWithManyNumbers();
	std::cout << std::endl;
	TestContainerFullWithManyNumbers();
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}