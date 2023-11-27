/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:57:06 by felicia           #+#    #+#             */
/*   Updated: 2023/11/27 18:29:53 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTORS
Fixed::Fixed()
{
	fixed_point_number = 0;
}

Fixed::Fixed(const int int_number)
{
	fixed_point_number = int_number << fractional_bits;
}

Fixed::Fixed(const float float_number)
{
	fixed_point_number = roundf(float_number * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& original)
{
	if (this == &original)
		 return ;
	*this = original;
}

// COPY ASSIGNMENT OPERATOR
Fixed& Fixed::operator=(const Fixed& original)
{
	if (this == &original)
		 return *this;
	this->fixed_point_number = original.getRawBits();
	return (*this);
}

// DESTRUCTOR
Fixed::~Fixed() { }

// REGULAR PUBLIC MEMBER FUNCTIONS
int	Fixed::getRawBits(void) const
{
	return (this->fixed_point_number);
}

void	Fixed::setRawBits(int const raw)
{
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

// MIN MAX MEMBER FUNCTIONS
Fixed& Fixed::min(Fixed& number1, Fixed& number2)
{
	if (number1 < number2)
		return (number1);
	else
		return (number2);
}

const Fixed& Fixed::min(Fixed const& number1, Fixed const& number2)
{
	if (number1.toFloat() < number2.toFloat())
		return (number1);
	else
		return (number2);
}

Fixed& Fixed::max(Fixed& number1, Fixed& number2)
{
	if (number1 > number2)
		return (number1);
	else
		return (number2);
}

const Fixed& Fixed::max(Fixed const& number1, Fixed const& number2)
{
	if (number1.toFloat() > number2.toFloat())
		return (number1);
	else
		return (number2);
}

// ARITHMETIC OPERATOR OVERLOADING
float Fixed::operator+(Fixed const& instance)
{
	return (this->toFloat() + instance.toFloat());
}

float Fixed::operator-(Fixed const& instance)
{
	return (this->toFloat() - instance.toFloat());
}

float Fixed::operator*(Fixed const& instance)
{
	return (this->toFloat() * instance.toFloat());
}

float Fixed::operator/(Fixed const& instance)
{
	return (this->toFloat() / instance.toFloat());
}

// COMPARISON OPERATOR OVERLOADING
int	Fixed::operator>(Fixed const& instance)
{
	if (this->toFloat() > instance.toFloat())
		return (1);
	else
		return (0);
}

int	Fixed::operator<(Fixed const& instance)
{
	if (this->toFloat() < instance.toFloat())
		return (1);
	else
		return (0);	
}

int	Fixed::operator>=(Fixed const& instance)
{
	if (this->toFloat() >= instance.toFloat())
		return (1);
	else
		return (0);	
}

int	Fixed::operator<=(Fixed const& instance)
{
	if (this->toFloat() <= instance.toFloat())
		return (1);
	else
		return (0);	
}

int	Fixed::operator==(Fixed const& instance)
{
	if (this->toFloat() == instance.toFloat())
		return (1);
	else
		return (0);	
}

int	Fixed::operator!=(Fixed const& instance)
{
	if (this->toFloat() != instance.toFloat())
		return (1);
	else
		return (0);	
}

// INCREMENT/DECREMENT OPERATOR OVERLOADING (PRE)
Fixed& Fixed::operator++(void)
{
	this->fixed_point_number++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->fixed_point_number--;
	return (*this);
}

// INCREMENT/DECREMENT OPERATOR OVERLOADING (POST)
Fixed Fixed::operator++(int)
{
	Fixed old(*this);

	this->fixed_point_number++;
    return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);

	this->fixed_point_number--;
    return (old);
}

std::ostream&	operator<<(std::ostream& output_stream, Fixed const& to_print)
{
	output_stream << to_print.toFloat();
	return (output_stream);
}