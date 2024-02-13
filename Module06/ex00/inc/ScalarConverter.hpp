/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:03:37 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/12 14:56:52 by felicia          ###   ########.fr       */
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
# include <string>
# include <cctype>

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

#endif