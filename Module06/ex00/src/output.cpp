/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:57:49 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/14 16:58:03 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void OutputChar(char char_representation, int type)
{
	if (type == SPECIAL_DOUBLE || type == SPECIAL_FLOAT)
		std::cout << "char: impossible\n";
	else if (!isprint(char_representation))
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: " << char_representation << std::endl;
}

void OutputInt(int int_representation, int type)
{
	if (type == SPECIAL_DOUBLE || type == SPECIAL_FLOAT)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << int_representation << std::endl;	
}

void OutputFloat(float float_representation, int int_representation)
{
	if (float_representation - int_representation == 0)
		std::cout << "float: " << float_representation << ".0f\n";
	else
		std::cout << "float: " << float_representation << "f\n";	
}

void OutputDouble(double double_representation, int int_representation)
{
	if (double_representation - int_representation == 0)
		std::cout << "double: " << double_representation << ".0\n";
	else
		std::cout << "double: " << double_representation << std::endl;	
}