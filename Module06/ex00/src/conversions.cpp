/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:19 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/21 18:31:23 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ToInt(std::string to_convert, bool& succesful_conversion)
{
	int int_representation = 0;

	try
	{
		int_representation = std::stoi(to_convert);
		succesful_conversion = true;
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << "int: Invalid argument: " << exception.what() << std::endl;
		succesful_conversion = false;
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << "int: Out of range: " << exception.what() << std::endl;
		succesful_conversion = false;
	}
	return (int_representation);
}

float ToFloat(std::string to_convert, bool& succesful_conversion)
{
	float float_representation = 0.0;

	try
	{
		float_representation = std::stof(to_convert);
		succesful_conversion = true;
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << "float: Invalid argument: " << exception.what() << std::endl;
		succesful_conversion = false;
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << "float: Out of range: " << exception.what() << std::endl;
		succesful_conversion = false;
	}
	return (float_representation);
}

double ToDouble(std::string to_convert, bool& succesful_conversion)
{
	double double_representation = 0.0;

	try
	{
		double_representation = std::stod(to_convert);
		succesful_conversion = true;
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << "double: Invalid argument: " << exception.what() << std::endl;
		succesful_conversion = false;
	}
	catch (const std::out_of_range& exception)
	{
		std::cout << "double: Out of range: " << exception.what() << std::endl;
		succesful_conversion = false;
	}
	return (double_representation);
}