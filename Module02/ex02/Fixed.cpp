/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:57:06 by felicia           #+#    #+#             */
/*   Updated: 2023/11/28 21:52:48 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
		 return;
	*this = original;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	if (this == &original)
		 return (*this);
	this->fixed_point_number = original.getRawBits();
	return (*this);
}

Fixed::~Fixed() { }

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point_number);
}

void Fixed::setRawBits(const int raw)
{
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

float Fixed::operator+(const Fixed& instance) const
{
	return (this->toFloat() + instance.toFloat());
}

float Fixed::operator-(const Fixed& instance) const
{
	return (this->toFloat() - instance.toFloat());
}

float Fixed::operator*(const Fixed& instance) const
{
	return (this->toFloat() * instance.toFloat());
}

float Fixed::operator/(const Fixed& instance) const
{
	return (this->toFloat() / instance.toFloat());
}

bool Fixed::operator>(const Fixed& instance) const
{
	return (this->getRawBits() > instance.getRawBits());
}

bool Fixed::operator<(const Fixed& instance) const
{
	return (this->getRawBits() < instance.getRawBits());
}

bool Fixed::operator>=(const Fixed& instance) const
{
	return (this->getRawBits() >= instance.getRawBits());
}

bool Fixed::operator<=(const Fixed& instance) const
{
	return (this->getRawBits() <= instance.getRawBits());
}

bool Fixed::operator==(const Fixed& instance) const
{
	return (this->getRawBits() == instance.getRawBits());
}

bool Fixed::operator!=(const Fixed& instance) const
{
	return (this->getRawBits() != instance.getRawBits());
}

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

Fixed& Fixed::min(Fixed& number1, Fixed& number2)
{
	return ((number1 < number2) ? number1 : number2);
}

const Fixed& Fixed::min(const Fixed& number1, const Fixed& number2)
{
	return ((number1 < number2) ? number1 : number2);
}

Fixed& Fixed::max(Fixed& number1, Fixed& number2)
{
	return ((number1 > number2) ? number1 : number2);
}

const Fixed& Fixed::max(const Fixed& number1, const Fixed& number2)
{
	return ((number1 > number2) ? number1 : number2);
}

std::ostream& operator<<(std::ostream& output_stream, const Fixed& to_print)
{
	output_stream << to_print.toFloat();
	return (output_stream);
}