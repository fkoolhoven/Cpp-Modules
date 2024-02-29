/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:33:03 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/29 12:18:47 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

// Double-ended queues are sequence containers with dynamic sizes that can be
// expanded or contracted on both ends (either its front or its back).
void TestWithDeque(void)
{
	std::cout << YELLOW BOLD "Testing succesful find with deque\n" OFF;
	try
	{
		std::deque<int> deque_test = {3, 4, 5};
		std::deque<int>::iterator found = easyfind(deque_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}

	std::cout << YELLOW BOLD "\nTesting not found with deque\n" OFF;
	try
	{
		std::deque<int> deque_test = {1, 2, 3};
		std::deque<int>::iterator found = easyfind(deque_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

// Forward lists are sequence containers that allow constant time insert and
// erase operations anywhere within the sequence.
void TestWithForwardList(void)
{
	std::cout << YELLOW BOLD "Testing succesful find with forward list\n" OFF;
	try
	{
		std::forward_list<int> forward_list_test = {3, 4, 5};
		std::forward_list<int>::iterator found = easyfind(forward_list_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
	
	std::cout << YELLOW BOLD "\nTesting not found with forward list\n" OFF;
	try
	{
		std::forward_list<int> forward_list_test = {1, 2, 3};
		std::forward_list<int>::iterator found = easyfind(forward_list_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

// Lists are sequence containers that allow constant time insert and erase operations
// anywhere within the sequence, and iteration in both directions.
void TestWithList(void)
{
	std::cout << YELLOW BOLD "Testing succesful find with list\n" OFF;
	try
	{
		std::list<int> list_test = {3, 4, 5};
		std::list<int>::iterator found = easyfind(list_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch (const std::exception& exception)
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
	catch (const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

// Vectors are sequence containers representing arrays that can change in size.
void TestWithVector(void)
{
	std::cout << YELLOW BOLD "Testing succesful find with vector\n" OFF;
	try
	{
		std::vector<int> vector_test = {3, 4, 5};
		std::vector<int>::iterator found = easyfind(vector_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch (const std::exception& exception)
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
	catch (const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

void TestWithConstArray(void)
{
	std::cout << YELLOW BOLD "Testing succesful find with const array\n" OFF;
	try
	{
		const std::array<int, 3> array_test = {3, 4, 5};
		std::array<int, 3>::const_iterator found = easyfind(array_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}

	std::cout << YELLOW BOLD "\nTesting not found with const array\n" OFF;
	try
	{
		const std::array<int, 3> array_test = {1, 2, 3};
		std::array<int, 3>::const_iterator found = easyfind(array_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

// Arrays are fixed-size sequence containers: they hold a specific number of
// elements ordered in a strict linear sequence.
void TestWithArray(void)
{
	std::cout << YELLOW BOLD "Testing succesful find with array\n" OFF;
	try
	{
		std::array<int, 3> array_test = {3, 4, 5};
		std::array<int, 3>::iterator found = easyfind(array_test, 4);
		std::cout << "Found: " << *found << std::endl;
	}
	catch (const std::exception& exception)
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
	catch (const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << '\n';
	}
}

int main(void)
{
	std::cout << std::endl;
	TestWithArray();
	std::cout << std::endl;
	TestWithConstArray();
	std::cout << std::endl;
	TestWithVector();
	std::cout << std::endl;
	TestWithList();
	std::cout << std::endl;
	TestWithForwardList();
	std::cout << std::endl;
	TestWithDeque();
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}