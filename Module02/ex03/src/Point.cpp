/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:22:48 by felicia           #+#    #+#             */
/*   Updated: 2023/11/28 22:41:08 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y (0) { }

Point::Point(const float number1, const float number2): x(number1), y(number2) { }

Point::Point(const Point& original)
{
	*this = original;
}

Point& Point::operator=(const Point& original)
{
	this->setX(original.getX());
	this->setY(original.getY());
	return (*this);
}

Point::~Point() { }

const Fixed& Point::getX() const
{
	return (this->x);
}

const Fixed& Point::getY() const
{
	return (this->y);
}

void Point::setX(const Fixed& original)
{
	Fixed& modifiableX = const_cast<Fixed &>(this->x);

	modifiableX.setRawBits(original.getRawBits());
}

void Point::setY(const Fixed& original)
{
	Fixed &modifiableY = const_cast<Fixed &>(this->y);

	modifiableY.setRawBits(original.getRawBits());
}