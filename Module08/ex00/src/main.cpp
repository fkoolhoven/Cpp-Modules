/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:33:03 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/20 17:51:39 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void TestWithArray(void)
{
	std::cout << YELLOW BOLD "Testing succesful find with array\n" OFF;
	try
	{
		std::array<int, 3> array_test = {3, 4, 5};
		std::array<int, 3>::iterator found = easyfind(array_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}

	std::cout << YELLOW BOLD "\nTesting not found with array\n" OFF;
	try
	{
		std::array<int, 3> array_test = {1, 2, 3};
		std::array<int, 3>::iterator found = easyfind(array_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

void TestWithList(void)
{
	std::cout << YELLOW BOLD "Testing succesful find with list\n" OFF;
	try
	{
		std::list<int> list_test = {3, 4, 5};
		std::list<int>::iterator found = easyfind(list_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}

	std::cout << YELLOW BOLD "\nTesting not found with list\n" OFF;
	try
	{
		std::list<int> list_test = {1, 2, 3};
		std::list<int>::iterator found = easyfind(list_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

void TestWithVector(void)
{
	std::cout << YELLOW BOLD "\nTesting succesful find with vector\n" OFF;
	try
	{
		std::vector<int> vector_test = {3, 4, 5};
		std::vector<int>::iterator found = easyfind(vector_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}

	std::cout << YELLOW BOLD "\nTesting not found with vector\n" OFF;
	try
	{
		std::vector<int> vector_test = {1, 2, 3};
		std::vector<int>::iterator found = easyfind(vector_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

int main(void)
{
	TestWithVector();
	std::cout << std::endl;
	TestWithList();
	std::cout << std::endl;
	TestWithArray();
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}