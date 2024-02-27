/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:27:10 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 15:30:02 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

typedef struct s_test_struct
{
	std::string first_name;
	std::string last_name;
} 	t_test_struct;

std::ostream& operator<<(std::ostream& stream, const t_test_struct instance)
{
	std::cout << instance.first_name << " " << instance.last_name;
	return (stream);
}

int main(void)
{
	std::cout << YELLOW BOLD "\nTesting with int array:\n" OFF;
	int int_array[] = {1, 2, 3, 4, 5};
	iter(int_array, 5, print_template);
	std::cout << std::endl;

	std::cout << YELLOW BOLD "\nTesting with char array:\n" OFF;
	char char_array[] = {'a', 'b', 'c', 'd', 'e'};
	iter(char_array, 5, print_template);
	std::cout << std::endl;
	
	std::cout << YELLOW BOLD "\nTesting with string array:\n" OFF;
	std::string string_array[] = {"Wow", "it's", "a", "string", "array!"};
	iter(string_array, 5, print_template);
	std::cout << std::endl;

	std::cout << YELLOW BOLD "\nTesting with struct array:\n" OFF;
	t_test_struct felicia = {"Felicia", "Koolhoven"};
	t_test_struct mara = {"Mara", "Koolhoven"};
	t_test_struct family[] = {felicia, mara};
	iter(family, 2, print_template);
	std::cout << std::endl << std::endl;

	return (EXIT_SUCCESS);
}
