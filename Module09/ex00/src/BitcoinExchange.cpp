/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:25:42 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 12:20:15 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream& datafile)
{
	std::string line;
	std::getline(datafile, line);
	
	while (std::getline(datafile, line))
	{
		size_t comma_position = line.find(',');
		
		std::string date_string = line.substr(0, comma_position);
		std::tm date_struct = {};
		std::istringstream date_stream(date_string);
		date_stream >> std::get_time(&date_struct, "%Y-%m-%d");
	
		std::string rate_string = line.substr(comma_position + 1);
		float rate = std::stof(rate_string);
		
		std::time_t date = std::mktime(&date_struct);
		database.emplace(date, rate);
	}
	
	std::cout << GREEN "BitcoinExchange created\n" OFF;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
	std::cout << GREEN "BitcoinExchange copy created\n" OFF;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	this->database = src.database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << GREEN "BitcoinExchange destroyed\n" OFF;
}

std::map<std::time_t, float> BitcoinExchange::getDatabase() const
{
	return (database);
}
