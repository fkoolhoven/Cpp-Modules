/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:52:51 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/29 12:21:29 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <vector>

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

class Span
{
	private:
		std::vector<int> vector_container;
		unsigned int max_size;
	
	public:
		Span(unsigned int max_size);
		Span(const Span& source);
		Span& operator=(const Span& source);
		~Span();

		void AddNumber(int number);
		void AddMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int ShortestSpan(void) const;
		int LongestSpan(void) const;

		class FullContainer : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NoSpan : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif