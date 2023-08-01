/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:51:46 by felicia           #+#    #+#             */
/*   Updated: 2023/08/01 12:59:18 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed		g(10.5123f);
	Fixed		c(10);
	Fixed		d(30);
	Fixed		e(0);
	Fixed		f(5);
	Fixed		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << std::endl << g << std::endl;
	std::cout << (g + g) << " should be 21 or 22" << std::endl;
	std::cout << (g * g) << " should be 110" << std::endl;
	std::cout << (g - g) << " should be 0" << std::endl;
	std::cout << (g / g) << " should be 1" << std::endl;

	std::cout << std::endl;
	g = 10;
	if (g > f)
		std::cout << "10 is bigger than 5\n";
	if (g < f || g == f)
		std::cout << "INCORRECT\n";
	if (c >= g && c == g)
		std::cout << "10 and 10 are as big\n";
	if (c < g || c > g)
		std::cout << "INCORRECT\n";
	if (d > g && d >= f)
		std::cout << "30 is bigger than 5 and 10\n";
	if (f < d && c < d)
		std::cout << f << " and " << c << " are smaller than " << d << std::endl;
	if (f > d || c > d)
		std::cout << "INCORRECT\n";
	if (f != g)
		std::cout << f << " is not equal to " << a << "\n\n";
	
	std::cout << e << " should be 0" << std::endl;
	std::cout << ++e << " should be 0.00390625" << std::endl;
	std::cout << e << " should be 0.00390625" << std::endl;
	std::cout << e++ << " should be 0.00390625" << std::endl;
	std::cout << e << " should be 0.0078125" << "\n\n";

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl; // outputting wrong

	return (EXIT_SUCCESS);
}