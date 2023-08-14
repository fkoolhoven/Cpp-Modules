/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:22:50 by felicia           #+#    #+#             */
/*   Updated: 2023/08/14 15:06:36 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <cmath>

# include "Fixed.hpp"

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

#endif