/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:33:16 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/20 13:53:46 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <array>

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

class NotFound : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Not found";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end())
		return it;
	else
		throw NotFound();
}

#endif