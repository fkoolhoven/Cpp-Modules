/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:57:14 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/15 14:22:07 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;

	std::cout << YELLOW BOLD "\nTesting with int\n" OFF;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << YELLOW BOLD "\nTesting with string\n" OFF;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	char c1 = 'a';
	char c2 = 'b';

	std::cout << YELLOW BOLD "\nTesting with char\n" OFF;
	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	::swap(c1, c2);
	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
	std::cout << "max(c1, c2) = " << ::max(c1, c2) << std::endl << std::endl;

	// ::swap(a, c); // This won't compile because the types don't match
	
	// std::function<void()> f1 = [](){};
    // std::function<void()> f2 = [](){};
	// ::min(f1, f2); // This won't compile because std::function doesn't support the < operator
	
	return (EXIT_SUCCESS);
}