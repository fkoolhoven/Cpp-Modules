/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:57:06 by felicia           #+#    #+#             */
/*   Updated: 2023/11/28 21:52:27 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GREEN "Default constructor called\n" OFF;
	fixed_point_number = 0;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called\n" OFF;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << YELLOW "Copy constructor called\n" OFF;
	if (this == &original)
		 return ;
	*this = original;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << BLUE "Copy assignment operator called\n" OFF;
	if (this == &original)
		 return (*this);
	fixed_point_number = original.getRawBits();
	return (*this);
}
		
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (fixed_point_number);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	fixed_point_number = raw;
}
