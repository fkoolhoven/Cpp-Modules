/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:09:01 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/12 18:07:57 by felicia          ###   ########.fr       */
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
		char_representation = stoi(to_convert);
		if (!isprint(char_representation))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << char_representation << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "char: " << exception.what();
	}
}

void ToInt(std::string to_convert)
{
	int int_representation;

	try
	{
		int_representation = stoi(to_convert);
		std::cout << "int: " << int_representation << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "int: " << exception.what();
	}
}

void ToFloat(std::string to_convert)
{
	float float_representation;

	float_representation = stof(to_convert);
	std::cout << "float: " << float_representation << std::endl;
}

void ToDouble(std::string to_convert)
{
	double double_representation;

	double_representation = stod(to_convert);
	std::cout << "double: " << double_representation << std::endl;
}

void ScalarConverter::Convert(std::string to_convert)
{
	ToChar(to_convert);
	ToInt(to_convert);
	ToFloat(to_convert);
	ToDouble(to_convert);
}