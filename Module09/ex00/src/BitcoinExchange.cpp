/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:25:42 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 17:38:14 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int GetDateAsInt(const std::string &line, int delimit)
{
	std::string date_string = line.substr(0, delimit);
	std::tm date_struct = {};
	std::istringstream date_stream(date_string);
	date_stream >> std::get_time(&date_struct, "%Y-%m-%d");
	int date_as_int = (date_struct.tm_year + 1900) * 10000 + (date_struct.tm_mon + 1) * 100 + date_struct.tm_mday;
	return (date_as_int);
}

BitcoinExchange::BitcoinExchange(std::ifstream& datafile)
{
	std::string line;
	std::getline(datafile, line);
	
	while (std::getline(datafile, line))
	{
		size_t comma_position = line.find(',');
		int date_as_int = GetDateAsInt(line, comma_position);
		std::string rate_string = line.substr(comma_position + 1);
		float rate = std::stof(rate_string);
		database.emplace(date_as_int, rate);
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

bool BitcoinExchange::FormattingIsCorrect(const std::string& line)
{
	if (line.compare("date | value") != 0 && !line.empty())
	{
		this->delimiter_position = line.find('|');
		if (this->delimiter_position == std::string::npos || this->delimiter_position != 11 || line.length() < 14)
			std::cerr << "Error: bad input => " << line << "\n";
		else
		{
			this->date_string = line.substr(0, this->delimiter_position - 1);
			this->amount_string = line.substr(this->delimiter_position + 2);

			if (!std::regex_match(date_string, std::regex("\\d{4}-\\d{2}-\\d{2}")) || !std::regex_match(amount_string, std::regex("^-?\\d+(\\.\\d+)?$")))
			{
				std::cerr << "Error: bad input => " << line << "\n";
				return (false);
			}
			return (true);
		}
	}
	return (false);
}

bool BitcoinExchange::InputIsValid(const std::string& line)
{
	if (this->FormattingIsCorrect(line))
	{
		this->date_as_int = GetDateAsInt(line, this->delimiter_position - 1);
		this->amount = std::stof(amount_string);
		
		if (this->amount < 0)
			std::cerr << "Error: not a positive number.\n";
		else if (this->amount > 1000)
			std::cerr << "Error: too large a number.\n";
		else
			return (true);
	}
	return (false);
}

void BitcoinExchange::CalculatePrice(const std::string& line)
{
	if (this->InputIsValid(line))
	{
		std::map<int, float>::const_iterator lower_bound = database.lower_bound(date_as_int);
		
		if (lower_bound == database.begin() && lower_bound->first != date_as_int)
			std::cerr << "Error: no data available for date " << this->date_string << "\n";
		else
		{
			if (lower_bound->first != date_as_int)
				lower_bound--;

			float rate = lower_bound->second;
			float result = rate * this->amount;
			std::cout << this->date_string << " => " << this->amount_string << " = " << result << std::endl;
		}
	}
}
