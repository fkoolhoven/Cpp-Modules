/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/12 15:11:35 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Incorrect argument count! Usage ./converter [string to convert]\n";
		return (EXIT_SUCCESS);
	}
		
	// ScalarConverter converter; // Won't compile because of private constructor
	ScalarConverter::Convert(argv[1]);
	return (EXIT_SUCCESS);
}