/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:03:37 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/12 12:36:45 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

// Write a class ScalarConverter that will contain only one static methods "convert"
// that will takes as parameter a string representation of a C++ literal in its most common
// form and output its value in the following serie of scalar types :

class ScalarConverter
{
	private:

	public:
		static void Convert(std::string to_convert);
};

#endif