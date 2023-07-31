/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:57:06 by felicia           #+#    #+#             */
/*   Updated: 2023/07/31 21:41:00 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTORS
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

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called\n";
	if (this == &original)
		 return ;
	*this = original;
}

// COPY ASSIGNMENT OPERATOR
Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &original)
		 return *this;
	fixed_point_number = original.getRawBits();
	return (*this);
}

// DESTRUCTOR
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

// REGULAR PUBLIC MEMBER FUNCTIONS
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

// ARITHMETIC OPERATOR OVERFLOWERS
int	Fixed::operator+(Fixed const &instance)
{
	return (toInt() + instance.toInt());
}

int	Fixed::operator-(Fixed const &instance)
{
	return (toInt() - instance.toInt());
}

int	Fixed::operator*(Fixed const &instance)
{
	return (toInt() * instance.toInt());
}

int	Fixed::operator/(Fixed const &instance)
{
	return (toInt() / instance.toInt());
}

// COMPARISON OPERATOR OVERFLOWERS

int	Fixed::operator>(Fixed const &instance)
{
	if (toInt() > instance.toInt())
		return (1);
	else
		return (0);
}

int	Fixed::operator<(Fixed const &instance)
{
	if (toInt() < instance.toInt())
		return (1);
	else
		return (0);	
}

int	Fixed::operator>=(Fixed const &instance)
{
	if (toInt() >= instance.toInt())
		return (1);
	else
		return (0);	
}

int	Fixed::operator<=(Fixed const &instance)
{
	if (toInt() <= instance.toInt())
		return (1);
	else
		return (0);	
}

int	Fixed::operator==(Fixed const &instance)
{
	if (toInt() == instance.toInt())
		return (1);
	else
		return (0);	
}

int	Fixed::operator!=(Fixed const &instance)
{
	if (toInt() != instance.toInt())
		return (1);
	else
		return (0);	
}

std::ostream& operator<<(std::ostream &output_stream, Fixed const &to_print)
{
	output_stream << to_print.toFloat();
	return (output_stream);
}
