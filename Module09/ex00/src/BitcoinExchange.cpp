/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:25:42 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/22 18:35:30 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// class BitcoinExchange
// {
// 	private:
// 		std::map<std::tm, float> database;
		
// 	public:
// 		BitcoinExchange(std::ifstream& database);
// 		BitcoinExchange(const BitcoinExchange& src);
// 		BitcoinExchange& operator=(const BitcoinExchange& src);
// 		~BitcoinExchange();
// };


BitcoinExchange::BitcoinExchange(std::ifstream& datafile)
{
	std::string line;
	while (std::getline(datafile, line))
	{
		database.insert(std::pair<int, float>(5, 0.0f));
		// Process line from database file
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

