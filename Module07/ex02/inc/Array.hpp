/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:57:12 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/19 16:47:16 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

# include <iostream>
# include <climits> 

template <typename T>
class Array
{
	private:
		T* array;
		unsigned int array_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& instance);
		Array& operator=(const Array& instance);
		~Array(void);
		T& operator[](unsigned int index) const;

		unsigned int getArraySize(void) const;
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& instance);

# include "../src/Array.tpp"

#endif