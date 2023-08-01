/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:51:46 by felicia           #+#    #+#             */
/*   Updated: 2023/08/01 14:15:08 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	Fixed		c(10);
	Fixed		d(30);
	Fixed		e(5);
	Fixed		f(10.51f);

	std::cout << std::endl << f << std::endl;
	std::cout << (f + f) << " should be around 21.02" << std::endl;
	std::cout << (f * f) << " should be around 110.46" << std::endl;
	std::cout << (f - f) << " should be 0" << std::endl;
	std::cout << (f / f) << " should be 1" << std::endl;

	std::cout << std::endl;
	f = 10;
	if (f > e)
		std::cout << "10 is bigger than 5\n";
	if (f < e || f == e)
		std::cout << "INCORRECT\n";
	if (c >= f && c == f)
		std::cout << "10 and 10 are as big\n";
	if (c < f || c > f)
		std::cout << "INCORRECT\n";
	if (d > f && d >= e)
		std::cout << "30 is bigger than 5 and 10\n";
	if (e < d && c < d)
		std::cout << e << " and " << c << " are smaller than " << d << std::endl;
	if (e > d || c > d)
		std::cout << "INCORRECT\n";
	if (e != f)
		std::cout << e << " is not equal to " << a << "\n\n";
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return (EXIT_SUCCESS);
}