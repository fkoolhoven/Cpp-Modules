/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:09:01 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/22 18:39:02 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN "ScalarConverter created\n" OFF;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED "ScalarConverter destroyed\n" OFF;
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

int GetType(std::string to_convert)
{
	if (to_convert.compare("-inf") == 0 || to_convert.compare("+inf") == 0 || to_convert.compare("nan") == 0)
		return (SPECIAL_DOUBLE);
	else if (to_convert.compare("-inff") == 0 || to_convert.compare("+inff") == 0 || to_convert.compare("nanf") == 0)
		return (SPECIAL_FLOAT);
	else if (to_convert.length() == 1 && !isdigit(to_convert[0]) && isprint(to_convert[0]))
		return (CHAR);
	else if (std::regex_match(to_convert, std::regex("[-+]?[0-9]+")))
		return (INT);
	else if (std::regex_match(to_convert, std::regex("[-+]?[0-9]+.[0-9]+f")))
		return (FLOAT);
	else if (std::regex_match(to_convert, std::regex("[-+]?[0-9]+.[0-9]+")))
		return (DOUBLE);
	return (INVALID);
}

void ScalarConverter::Convert(std::string to_convert)
{
	int type = GetType(to_convert);
	char char_representation;
	int int_representation;
	float float_representation;
	double double_representation;
	bool succesful_conversion = true;

	if (type == INVALID)
	{
		std::cout << "Invalid input! Choose between:\n";
		std::cout << "* char literal (e.g. 'a')\n";
		std::cout << "* int literal (e.g. -42)\n";
		std::cout << "* float literal (e.g. 42.42f)\n";
		std::cout << "* double literal (e.g. -4.2)\n";
		return;
	}
	else
	{
		switch (type)
		{
			case CHAR:
				char_representation = to_convert[0];
				int_representation = static_cast<int>(char_representation);
				float_representation = static_cast<float>(char_representation);
				double_representation = static_cast<double>(char_representation);
				break;
			case INT:
				int_representation = ToInt(to_convert, succesful_conversion);
				char_representation = static_cast<char>(int_representation);
				float_representation = static_cast<float>(int_representation);
				double_representation = static_cast<double>(int_representation);
				break;
			case FLOAT:
				float_representation = ToFloat(to_convert, succesful_conversion);
				char_representation = static_cast<char>(float_representation);
				int_representation = static_cast<int>(float_representation);
				double_representation = static_cast<double>(float_representation);
				break;
			case DOUBLE:
				double_representation = ToDouble(to_convert, succesful_conversion);
				char_representation = static_cast<char>(double_representation);
				int_representation = static_cast<int>(double_representation);
				float_representation = static_cast<float>(double_representation);
				break;
			case SPECIAL_DOUBLE:
				double_representation = ToDouble(to_convert, succesful_conversion);
				float_representation = static_cast<float>(double_representation);
				break;
			case SPECIAL_FLOAT:
				float_representation = ToFloat(to_convert, succesful_conversion);
				double_representation = static_cast<double>(float_representation);
				break;
		}
	}
	
	if (succesful_conversion)
	{
		OutputChar(char_representation, type);
		OutputInt(int_representation, type);
		OutputFloat(float_representation, int_representation);
		OutputDouble(double_representation, int_representation);
	}
}