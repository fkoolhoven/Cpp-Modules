/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:03:37 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/21 18:30:48 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

# include <iostream>
# include <cstdlib>
# include <string>
# include <cctype>
# include <limits>
# include <stdexcept>
# include <regex>

enum TYPE
{
	INVALID,
	SPECIAL_DOUBLE,
	SPECIAL_FLOAT,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& src);	
		ScalarConverter& operator=(const ScalarConverter& src);	

	public:
		static void Convert(std::string to_convert);
};

int ToInt(std::string to_convert, bool& succesful_conversion);
float ToFloat(std::string to_convert, bool& succesful_conversion);
double ToDouble(std::string to_convert, bool& succesful_conversion);
void OutputChar(char char_representation, int type);
void OutputInt(int int_representation, int type);
void OutputFloat(float float_representation, int int_representation);
void OutputDouble(double double_representation, int int_representation);

#endif