/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:22:48 by felicia           #+#    #+#             */
/*   Updated: 2023/08/01 18:28:26 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point(): x(0), y (0)
{
	// std::cout << "Default constructor called\n";
}

Point::Point(float const number1, float const number2): x(number1), y(number2)
{
	// std::cout << "Float constructor called\n";
}

Point::Point(Point const &original)
{
	*this = original;
}

Point	&Point::operator=(Point const &original)
{
	this->setX(original.getX());
	this->setY(original.getY());
	return (*this);
}

Point::~Point()
{
	// std::cout << "Default destructor called for " << x << " " << y << std::endl;
}

Fixed const	&Point::getX() const
{
	return (this->x);
}

Fixed const	&Point::getY() const
{
	return (this->y);
}

void	Point::setX(Fixed const &original)
{
	Fixed &modifiableX = const_cast<Fixed &>(this->x);

	modifiableX.setRawBits(original.getRawBits());
}

void	Point::setY(Fixed const &original)
{
	Fixed &modifiableY = const_cast<Fixed &>(this->y);

	modifiableY.setRawBits(original.getRawBits());
}


