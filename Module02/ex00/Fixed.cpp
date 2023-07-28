/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:57:06 by felicia           #+#    #+#             */
/*   Updated: 2023/07/28 21:32:52 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	number_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed& original)
{
	std::cout << "Copy constructor called\n";
	if (this == &original)
		 return ;
	number_value = original.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &original)
		 return *this;
	number_value = original.getRawBits();
	return (*this);
}
		
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (number_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	number_value = raw;
}
