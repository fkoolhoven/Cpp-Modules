/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:57:06 by felicia           #+#    #+#             */
/*   Updated: 2023/11/28 21:52:36 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GREEN "Default constructor called\n" OFF;
	fixed_point_number = 0;
}

Fixed::Fixed(const int int_number)
{
	std::cout << GREEN "Int constructor called\n" OFF;
	fixed_point_number = int_number << fractional_bits;
}

Fixed::Fixed(const float float_number)
{
	std::cout << GREEN "Float constructor called\n" OFF;
	fixed_point_number = roundf(float_number * (1 << fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called\n" OFF;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << YELLOW "Copy constructor called\n" OFF;
	if (this == &original)
		 return;
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

float Fixed::toFloat(void) const
{
	float float_representation = static_cast<float>(fixed_point_number);
	return (float_representation / (1 << fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (fixed_point_number >> fractional_bits);
}

std::ostream& operator<<(std::ostream& output_stream, Fixed const& to_print)
{
	output_stream << to_print.toFloat();
	return (output_stream);
}