/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:11:24 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 12:30:52 by fkoolhov         ###   ########.fr       */
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
	{
		if (line.compare("date | value") != 0 && !line.empty())
		{
			size_t delimiter = line.find('|');
			if (delimiter == std::string::npos || delimiter != 11 || line.length() < 14)
			{
				std::cerr << "Invalid input format\n";
			}
			else
			{
				std::string date_string = line.substr(0, delimiter - 1);
				std::tm date_struct = {};
				std::istringstream date_stream(date_string);
				date_stream >> std::get_time(&date_struct, "%Y-%m-%d");
			
				std::string rate_string = line.substr(delimiter + 2);
				float rate = std::stof(rate_string);

				if (rate < 0)
				{
					std::cerr << "Error: not a positive number.\n";
				}
				else if (rate > 1000)
				{
					std::cerr << "Error: too large a number.\n";
				}
				else
				{
					// std::time_t date = std::mktime(&date_struct);
					std::cout << std::put_time(&date_struct, "%Y-%d-%m") << " => " << rate_string << std::endl;
				}
			}
		}
	}
	return (EXIT_SUCCESS);
}