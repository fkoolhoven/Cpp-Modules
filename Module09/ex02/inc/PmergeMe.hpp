/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:49:53 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/29 18:03:42 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <chrono>
# include <deque>
# include <set>

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define PURPLE	"\033[35m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

# define SORTING_THRESHOLD 5

class PmergeMe
{
	private:
		std::vector<int> vector;
		std::deque<int> deque; 
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		void SortVector(std::vector<int>& vector);
		void SortDeque(std::deque<int>& deque);
};

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& vector);
std::ostream& operator<<(std::ostream& stream, const std::deque<int>& deque);

#endif