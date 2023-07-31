/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:51:46 by felicia           #+#    #+#             */
/*   Updated: 2023/07/31 21:39:32 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed	a(10);
	Fixed	b(5);
	Fixed	c(10);
	Fixed	d(30);
	// Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << (a + a) << " should be 20" << std::endl;
	std::cout << (a * a) << " should be 100" << std::endl;
	std::cout << (a - a) << " should be 0" << std::endl;
	std::cout << (a / a) << " should be 1" << std::endl;
	
	if (a > b)
		std::cout << "10 is bigger than 5\n";
	if (a < b || a == b)
		std::cout << "INCORRECT\n";
	if (c >= a && c == a)
		std::cout << "10 and 10 are as big\n";
	if (c < a || c > a)
		std::cout << "INCORRECT\n";
	if (d > a && d >= b)
		std::cout << "30 is bigger than 5 and 10\n";
	if (b < d && c < d)
		std::cout << b << " and " << c << " are smaller than " << d << std::endl;
	if (b > d || c > d)
		std::cout << "INCORRECT\n";
	if (b != a)
		std::cout << b << " is not equal to " << a << std::endl;
	
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
	return (EXIT_SUCCESS);
}