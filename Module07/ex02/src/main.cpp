/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:04:19 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/19 17:08:56 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void TestAccessOutsideArray(void)
{
	std::cout << YELLOW BOLD "Testing access outside array\n" OFF;

	Array<int> int_array(2);
	int_array[0] = 1;
	int_array[1] = 2;
	std::cout << "int_array content: " << int_array << std::endl;
	
	try
	{
		std::cout << "Trying to access int_array[0]: " << int_array[0] << std::endl;
		std::cout << "Trying to access int_array[1]: " << int_array[1] << std::endl;
		std::cout << "Trying to access int_array[2]: " << int_array[2] << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << std::endl;
	}

	try
	{
		std::cout << "Trying to access int_array[-1]: " << int_array[-1] << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << std::endl;
	}
}

void TestCopyAssignment(void)
{
	std::cout << YELLOW BOLD "Testing copy assignment\n" OFF;

	Array<char> char_array(2);
	char_array[0] = 'A';
	char_array[1] = 'B';
	Array<char> char_array_assigned;
	char_array_assigned = char_array;
	
	std::cout << "char_array content: " << char_array << std::endl;
	std::cout << "char_array_assigned content: " << char_array_assigned << std::endl;

	std::cout << YELLOW BOLD "\nTesting deep copy\n" OFF;
	char_array_assigned[0] = 'C';
	char_array_assigned[1] = 'D';
	std::cout << "char_array content: " << char_array << std::endl;
	std::cout << "char_array_assigned content: " << char_array_assigned << std::endl;
}

void TestCopyConstruction(void)
{
	std::cout << YELLOW BOLD "Testing copy construction\n" OFF;

	Array<int> int_array(2);
	int_array[0] = 1;
	int_array[1] = 2;
	Array<int> int_array_copy(int_array);
	
	std::cout << "int_array content: " << int_array << std::endl;
	std::cout << "int_array_copy content: " << int_array_copy << std::endl;	

	std::cout << YELLOW BOLD "\nTesting deep copy\n" OFF;
	
	int_array_copy[0] = 3;
	int_array_copy[1] = 4;
	std::cout << "int_array content: " << int_array << std::endl;
	std::cout << "int_array_copy content: " << int_array_copy << std::endl;
}

void TestConstructionDestructionWithSize(void)
{
	std::cout << YELLOW BOLD "Testing construction/destruction with size\n" OFF;

	Array<int> int_array(2);
	int_array[0] = 1;
	int_array[1] = 2;
	std::cout << "int_array content: " << int_array << std::endl;

	Array<char> char_array(2);
	char_array[0] = 'a';
	char_array[1] = 'b';
	std::cout << "char_array content: " << char_array << std::endl;
	
	Array<std::string> string_array(2);
	string_array[0] = "one";
	string_array[1] = "two";
	std::cout << "string_array content: " << string_array << std::endl;

	try
	{
		Array<int> bad_size(0);
	}
	catch(const std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << std::endl;
	}
}

void TestGetArraySize(void)
{
	std::cout << YELLOW BOLD "Testing getArraySize\n" OFF;
	
	Array<int> int_array(15);
	std::cout << "Size of int_array: " << int_array.getArraySize() << std::endl;
	
	Array<char> char_array;
	std::cout << "Size of char_array: " << char_array.getArraySize() << std::endl;
}

void TestDefaultConstructionDestruction(void)
{
	std::cout << YELLOW BOLD "Testing default construction/destruction\n" OFF;
	
	Array<int> int_array;
	Array<char> char_array;
	Array<std::string> string_array;

	std::cout << "int_array content: " << int_array;
	std::cout << "char_array content: " << char_array;
	std::cout << "string_array content: " << string_array;
}

int main(void)
{
	std::cout << std::endl;
	TestDefaultConstructionDestruction();
	std::cout << std::endl;
	TestGetArraySize();
	std::cout << std::endl;
	TestConstructionDestructionWithSize();
	std::cout << std::endl;
	TestCopyConstruction();
	std::cout << std::endl;
	TestCopyAssignment();
	std::cout << std::endl;
	TestAccessOutsideArray();
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}