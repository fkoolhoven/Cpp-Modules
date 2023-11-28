/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:51:46 by felicia           #+#    #+#             */
/*   Updated: 2023/11/28 17:05:48 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed c(10);
	Fixed d(30);
	Fixed e(5);
	Fixed f(10.51f);

	std::cout << BOLD GREEN "\nTESTING ARITHMETIC OPERATORS" OFF << std::endl;
	std::cout << (f + f) << " should be around 21.02" << std::endl;
	std::cout << (f - f) << " should be 0" << std::endl;
	std::cout << (f * f) << " should be around 110.46" << std::endl;
	std::cout << (f / f) << " should be 1" << std::endl << std::endl;

	f = 10;

	std::cout << BOLD GREEN "TESTING COMPARISON OPERATORS\n" OFF;
	if (c <= f)
		std::cout << c << " is smaller or equal to " << f << std::endl;
	if (e <= c)
		std::cout << e << " is smaller or equal to " << c << std::endl;
	if (c >= f)
		std::cout << c << " is bigger or equal to " << f << std::endl;
	if (c >= e)
		std::cout << c << " is bigger or equal to " << e << std::endl;
	if (d > f)
		std::cout << d << " is bigger than " << f << std::endl;
	if (e < d)
		std::cout << e << " is smaller than " << d << std::endl;
	if (f == c)
		std::cout << f << " is equal to " << c << std::endl;
	if (e != f)
		std::cout << e << " is not equal to " << f << std::endl << std::endl;

	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	
	std::cout << BOLD GREEN "TESTING INCREMENT/DECREMENT OPERATORS\n" OFF;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl << std::endl;

	std::cout << BOLD GREEN "TESTING MIN AND MAX\n" OFF ;
	std::cout << Fixed::max(a, b) << " because it's bigger than " << a << std::endl;
	std::cout << Fixed::max(c, e) << " because it's bigger than " << e << std::endl;
	std::cout << Fixed::min(a, b) << " because it's smaller than " << b << std::endl;
	std::cout << Fixed::min(c, e) << " because it's smaller than " << c << std::endl << std::endl;

	return (EXIT_SUCCESS);
}