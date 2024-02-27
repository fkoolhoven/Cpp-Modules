/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:11:24 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 13:59:49 by fkoolhov         ###   ########.fr       */
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
				std::cerr << "Error: bad input => " << line << "\n";
			}
			else
			{
				std::string date_string = line.substr(0, delimiter - 1);
				std::tm date_struct = {};
				std::istringstream date_stream(date_string);
				date_stream >> std::get_time(&date_struct, "%Y-%m-%d");
			
				std::string amount_string = line.substr(delimiter + 2);
				float amount = std::stof(amount_string);

				if (amount < 0)
					std::cerr << "Error: not a positive number.\n";
				else if (amount > 1000)
					std::cerr << "Error: too large a number.\n";
				else
				{
					std::time_t date = std::mktime(&date_struct);
					try 
					{
						std::map<std::time_t, float>::iterator it_lower;

						it_lower = exchange.getDatabase().lower_bound(date);
						if (it_lower != exchange.getDatabase().begin())
							--it_lower;


						if (it_lower == exchange.getDatabase().end())
						{
							std::cerr << "Error: no data for date " << std::put_time(&date_struct, "%Y-%d-%m") << "\n";
						}
						else
						{
							std::time_t found_date = it_lower->first;
							std::tm* found_date_struct = std::localtime(&found_date);
							char buffer[80];
							std::strftime(buffer, sizeof(buffer), "%Y-%d-%m", found_date_struct);
							printf("found date = %s\n", buffer);


							float rate = exchange.getDatabase()[it_lower->first];
							float result = rate * amount;
							std::cout << std::put_time(&date_struct, "%Y-%d-%m") << " => " << amount_string << " = " << result << std::endl;
						}
					}
					catch (const std::out_of_range& e)
					{
						std::cerr << "Error: no data for date " << std::put_time(&date_struct, "%Y-%d-%m") << "\n";
					}
				}
			}
		}
	}
	return (EXIT_SUCCESS);
}