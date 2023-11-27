/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:35:52 by felicia           #+#    #+#             */
/*   Updated: 2023/11/27 18:36:42 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	PrintResultMessage(bool part_of_triangle)
{
	if (part_of_triangle)
		std::cout << GREEN "YES! Point is part of tiangle.\n" OFF;
	else
		std::cout << RED "NO! Point is not part of triangle.\n" OFF;
}

float CalculateTriangleSurface(Point const &point1, Point const &point2, Point const &point3)
{
	float	surface;
	
	surface = 0.5 * std::abs(
        point1.getX().toFloat() * (point2.getY().toFloat() - point3.getY().toFloat()) +
        point2.getX().toFloat() * (point3.getY().toFloat() - point1.getY().toFloat()) +
        point3.getX().toFloat() * (point1.getY().toFloat() - point2.getY().toFloat()));
	return (surface);
}

bool BSP(Point const a, Point const b, Point const c, Point const point)
{
	float	full_triangle;
	float	triangle1, triangle2, triangle3;

	full_triangle = CalculateTriangleSurface(a, b, c);
	triangle1 = CalculateTriangleSurface(point, b ,c);
	triangle2 = CalculateTriangleSurface(a, point, c);
	triangle3 = CalculateTriangleSurface(a, b, point);

	if (triangle1 == 0 || triangle2 == 0 || triangle3 == 0)
		return (false);
	else if (triangle1 + triangle2 + triangle3 == full_triangle)
		return (true);
	return (false);
}

int	main(void)
{
	Point	a(1, 1);
	Point	b(4, 1);
	Point	c(4, 5);

	std::cout << "Triangle corner 1: x" << a.getX() << ", y" << a.getY() << std::endl;
	std::cout << "Triangle corner 2: x" << b.getX() << ", y" << b.getY() << std::endl;
	std::cout << "Triangle corner 3: x" << c.getX() << ", y" << c.getY() << std::endl;

	Point	check(5, 2);
	bool 	part_of_triangle;

	std::cout << "\nChecking if x5, y2 is part of the triangle.\n";
	part_of_triangle = BSP(a, b, c, check);
	PrintResultMessage(part_of_triangle);
	check.setX(2); check.setY(2);
	std::cout << "Checking if x2, y2 is part of the triangle.\n";
	part_of_triangle = BSP(a, b, c, check);
	PrintResultMessage(part_of_triangle);
	check.setX(3); check.setY(1);
	std::cout << "Checking if x3, y1 is part of the triangle.\n";
	part_of_triangle = BSP(a, b, c, check);
	PrintResultMessage(part_of_triangle);
}
