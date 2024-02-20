/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:17 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/20 17:58:01 by fkoolhov         ###   ########.fr       */
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

// Now, time to move on more serious things. Let’s develop something weird.
// The std::stack container is very nice. Unfortunately, it is one of the only STL Con-
// tainers that is NOT iterable. That’s too bad.
// But why would we accept this? Especially if we can take the liberty of butchering the
// original stack to create missing features.
// To repair this injustice, you have to make the std::stack container iterable.
// Write a MutantStack class. It will be implemented in terms of a std::stack.
// It will offer all its member functions, plus an additional feature: iterators.
// Of course, you will write and turn in your own tests to ensure everything works as
// expected.

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	// Define stack and iterator type
	typedef std::stack<T> stack;
    typedef typename stack::container_type::iterator iterator;
	
    // Inherit constructors from std::stack
    MutantStack() : stack() {}
    MutantStack(MutantStack const &other) : stack(other) {}
    ~MutantStack() {this->c.clear();}
    
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