/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:22:48 by felicia           #+#    #+#             */
/*   Updated: 2023/11/27 18:29:06 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y (0) { }

Point::Point(float const number1, float const number2): x(number1), y(number2) { }

Point::Point(Point const &original)
{
	*this = original;
}

Point& Point::operator=(Point const &original)
{
	this->setX(original.getX());
	this->setY(original.getY());
	return (*this);
}

Point::~Point() { }

Fixed const& Point::getX() const
{
	return (this->x);
}

Fixed const& Point::getY() const
{
	return (this->y);
}

void Point::setX(Fixed const& original)
{
	Fixed& modifiableX = const_cast<Fixed &>(this->x);

	modifiableX.setRawBits(original.getRawBits());
}

void Point::setY(Fixed const& original)
{
	Fixed &modifiableY = const_cast<Fixed &>(this->y);

	modifiableY.setRawBits(original.getRawBits());
}


