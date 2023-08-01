/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:22:50 by felicia           #+#    #+#             */
/*   Updated: 2023/08/01 16:34:50 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <cmath>

#include "Fixed.hpp"

# define RED	"\033[31m"
# define GREEN 	"\033[32m"
# define OFF	"\033[0m"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;
	public:	
		Point();
		Point(float const number1, float const number2);
		Point(const Point &original);
		Point&	operator=(const Point &original);
		~Point();

		Fixed const	&getX() const;
		Fixed const	&getY() const;
		void		setX(Fixed const &original);
		void		setY(Fixed const &original);
};


// • Public members:
// 		◦ A copy constructor.
// 		◦ A copy assignment operator overload.
// 		◦ A destructor.
// 		◦ Anything else useful.

#endif