/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:17 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/28 13:36:40 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <array>
# include <stack>

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Define stack and iterator type
		typedef std::stack<T> stack;
		typedef typename stack::container_type::iterator iterator;
		
		// Inherit constructors from std::stack
		MutantStack() : stack() { std::cout << GREEN "MutantStack created\n" OFF;}
		MutantStack(MutantStack const &other) : stack(other) { std::cout << GREEN "MutantStack copy created\n" OFF;}
		~MutantStack() { this->c.clear(); std::cout << RED "MutantStack destroyed\n" OFF;}
		
		// Overloaded opperator
		MutantStack &operator=(MutantStack &other)
		{
			stack::operator=(other);
			return *this;
		}

		// Add begin() and end() member functions to return iterators
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

#endif