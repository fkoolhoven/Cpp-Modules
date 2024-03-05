/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:25:42 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/05 15:03:05 by fkoolhov         ###   ########.fr       */
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
		int date_as_int = (date_struct.tm_year + 1900) * 10000 + (date_struct.tm_mon + 1) * 100 + date_struct.tm_mday;
		std::string rate_string = line.substr(comma_position + 1);
		double rate = std::stof(rate_string);
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
	this->date_as_int = src.date_as_int;
	this->amount = src.amount;
	this->date_string = src.date_string;
	this->amount_string = src.amount_string;
	this->delimiter_position = src.delimiter_position;
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

int GetDaysInMonth(int month)
{
	static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return (days_in_month[month - 1]);
}

bool VerifyDate(const std::tm& date_struct, const std::string& line)
{
	if (date_struct.tm_mon < 0 || date_struct.tm_mon > 11)
	{
		std::cerr << "Error: bad input => " << line << "\n";
		return (false);
	}
	int days_in_month = GetDaysInMonth(date_struct.tm_mon + 1);
	if (date_struct.tm_mday < 1 || date_struct.tm_mday > days_in_month)
	{
		std::cerr << "Error: bad input => " << line << "\n";
		return (false);
	}
	return (true);
}

bool BitcoinExchange::InputIsValid(const std::string& line)
{
	if (this->FormattingIsCorrect(line))
	{
		std::string date_string = line.substr(0, this->delimiter_position - 1);
		std::tm date_struct = {};
		std::istringstream date_stream(date_string);
		date_stream >> std::get_time(&date_struct, "%Y-%m-%d");
		
		if (VerifyDate(date_struct, line))
		{
			this->date_as_int = (date_struct.tm_year + 1900) * 10000 + (date_struct.tm_mon + 1) * 100 + date_struct.tm_mday;
			this->amount = std::stof(amount_string);
			
			if (this->amount < 0)
				std::cerr << "Error: not a positive number.\n";
			else if (this->amount > 1000)
				std::cerr << "Error: too large a number.\n";
			else
				return (true);
		}
	}
	return (false);
}

void BitcoinExchange::CalculatePrice(const std::string& line)
{
	if (this->InputIsValid(line))
	{
		std::map<int, double>::const_iterator lower_bound = database.lower_bound(date_as_int);
		
		if (lower_bound == database.begin() && lower_bound->first != date_as_int)
			std::cerr << "Error: no data available for date " << this->date_string << "\n";
		else
		{
			if (lower_bound->first != date_as_int)
				lower_bound--;

			double rate = lower_bound->second;
			double result = rate * this->amount;
			std::cout << this->date_string << " => " << this->amount_string << " = " << result << std::endl;
		}
	}
}
