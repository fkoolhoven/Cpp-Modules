/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:17 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/29 12:25:50 by fkoolhov         ###   ########.fr       */
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

template <typename T, class deque = std::deque<T>>
class MutantStack : public std::stack<T, deque>
{
	private:
		typedef std::stack<T, deque> stack;
	
	public:
		typedef typename deque::iterator iterator;
		typedef typename deque::const_iterator const_iterator;
		
		MutantStack() : stack() 
		{ 
			std::cout << GREEN "MutantStack created\n" OFF; 
		}
		MutantStack(MutantStack const& source) : stack(source) 
		{ 
			std::cout << GREEN "MutantStack copy created\n" OFF; 
		}
		~MutantStack() 
		{ 
			std::cout << RED "MutantStack destroyed\n" OFF; 
		}
		MutantStack& operator=(MutantStack &source)
		{
			stack::operator=(source);
			return (*this);
		}
		iterator begin() 
		{ 
			return (this->c.begin()); 
		}
		iterator end() 
		{ 
			return (this->c.end()); 
		}
		const_iterator begin() const
		{ 
			return (this->c.begin()); 
		}
		const_iterator end() const
		{ 
			return (this->c.end()); 
		}
};

#endif