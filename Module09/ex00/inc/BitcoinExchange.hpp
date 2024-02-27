/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:25:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 12:14:15 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <map>
# include <ctime>
# include <string>
# include <sstream>
# include <iomanip>

class BitcoinExchange
{
	private:
		std::map<std::time_t, float> database;
		
	public:
		BitcoinExchange(std::ifstream& database);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		std::map<std::time_t, float> getDatabase() const;
};

#endif