/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:57:06 by felicia           #+#    #+#             */
/*   Updated: 2023/07/30 16:01:10 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixed_point_number = 0;
}

Fixed::Fixed(const int int_number)
{
	std::cout << "Int constructor called\n";
	fixed_point_number = int_number << fractional_bits;
}

Fixed::Fixed(const float float_number)
{
	std::cout << "Float constructor called\n";
	fixed_point_number = roundf(float_number * (1 << fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called\n";
	if (this == &original)
		 return ;
	*this = original;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &original)
		 return *this;
	fixed_point_number = original.getRawBits();
	return (*this);
}
		
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (fixed_point_number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	fixed_point_number = raw;
}

float	Fixed::toFloat(void) const
{
	float	float_representation;

	float_representation = float(fixed_point_number);
	return (float_representation / (1 << fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (fixed_point_number >> fractional_bits);
}

std::ostream& operator<<(std::ostream &output_stream, Fixed const &to_print)
{
	output_stream << to_print.toFloat();
	return (output_stream);
}