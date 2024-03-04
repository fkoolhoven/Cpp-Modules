/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:25:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/04 14:46:06 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define GREEN		"\033[32m"
# define RED 		"\033[31m"
# define OFF		"\033[0m"

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <map>
# include <ctime>
# include <string>
# include <sstream>
# include <iomanip>
# include <regex>

class BitcoinExchange
{
	private:
		std::map<int, float> database;
		int date_as_int;
		float amount;
		std::string date_string;
		std::string amount_string;
		size_t delimiter_position;
		
	public:
		BitcoinExchange(std::ifstream& database);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void CalculatePrice(const std::string& line);
		bool InputIsValid(const std::string& line);
		bool FormattingIsCorrect(const std::string& line);
};

#endif