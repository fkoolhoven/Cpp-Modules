/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:11:24 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 16:42:30 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./bitcoin_exchange <inputfile>\n";
		return (EXIT_FAILURE);
	}
	
	std::ifstream input(argv[1]);
	std::ifstream datafile("data.csv");

	if (!input.is_open())
	{
		std::cerr << "Failed to open input file\n";
		return (EXIT_FAILURE);
	}

	if (!datafile.is_open())
	{
		std::cerr << "Failed to open database file\n";
		return (EXIT_FAILURE);
	}
	BitcoinExchange exchange(datafile);

	std::string line;
	while (std::getline(input, line))
		exchange.CalculatePrice(line);
	return (EXIT_SUCCESS);
}