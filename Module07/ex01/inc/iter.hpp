/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:26:31 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:11 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

# include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*function)(T&))
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
};

template <typename T>
void print_template(T& t)
{
	std::cout << t << " ";
};

typedef struct s_test_struct
{
	std::string first_name;
	std::string last_name;
} 	t_test_struct;

std::ostream& operator<<(std::ostream& stream, const t_test_struct& instance)
{
	std::cout << instance.first_name << " " << instance.last_name;
	return (stream);
}

#endif