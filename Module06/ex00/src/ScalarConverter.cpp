/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:09:01 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/13 18:40:59 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "ScalarConverter created\n" OFF;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destroyed\n" OFF;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
	return (*this);
}

void ToChar(std::string to_convert)
{
	char char_representation;

	try
	{
		size_t pos;
		char_representation = std::stoi(to_convert, &pos);
		if (!isprint(char_representation))
			std::cout << "char: Non displayable";
		else
			std::cout << "char: " << char_representation;
		if (pos < to_convert.size())
		{
			std::cout << " (conversion stopped at position " << pos << ")";
		}
		std::cout << std::endl;
		
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << "char: Invalid argument: " << exception.what() << std::endl;
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << "char: Out of range: " << exception.what() << std::endl;
	}
}

void ToInt(std::string to_convert)
{
	int int_representation;

	try
	{
		size_t pos;
		int_representation = std::stoi(to_convert, &pos);
		std::cout << "int: " << int_representation;
		if (pos < to_convert.size())
		{
			std::cout << " (conversion stopped at position " << pos << ")";
		}
		std::cout << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "int: Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "int: Out of range: " << e.what() << std::endl;
	}
}

void ToFloat(std::string to_convert)
{
	float float_representation;

	try
	{
		float_representation = std::stof(to_convert);
		std::cout << "float: " << float_representation << std::endl;
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << "float: Invalid argument: " << exception.what() << std::endl;
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << "float: Out of range: " << exception.what() << std::endl;
	}
}

void ToDouble(std::string to_convert)
{
	double double_representation;

	try
	{
		double_representation = std::stod(to_convert);
		std::cout << "double: " << double_representation << std::endl;
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << "double: Invalid argument: " << exception.what() << std::endl;
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << "double: Out of range: " << exception.what() << std::endl;
	}
}

void ScalarConverter::Convert(std::string to_convert)
{
	ToChar(to_convert);
	ToInt(to_convert);
	ToFloat(to_convert);
	ToDouble(to_convert);
}