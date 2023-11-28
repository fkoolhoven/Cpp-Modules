/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:35:52 by felicia           #+#    #+#             */
/*   Updated: 2023/11/28 22:37:46 by felicia          ###   ########.fr       */
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

float CalculateTriangleSurface(const Point& point1, const Point& point2, const Point& point3)
{
	float surface;
	
	surface = 0.5 * std::abs(
        point1.getX().toFloat() * (point2.getY().toFloat() - point3.getY().toFloat()) +
        point2.getX().toFloat() * (point3.getY().toFloat() - point1.getY().toFloat()) +
        point3.getX().toFloat() * (point1.getY().toFloat() - point2.getY().toFloat()));
	return (surface);
}

bool BSP(const Point a, const Point b, const Point c, const Point point)
{
	float full_triangle;
	float triangle1, triangle2, triangle3;

	full_triangle = CalculateTriangleSurface(a, b, c);
	triangle1 = CalculateTriangleSurface(point, b ,c);
	triangle2 = CalculateTriangleSurface(a, point, c);
	triangle3 = CalculateTriangleSurface(a, b, point);

	if (triangle1 == 0 || triangle2 == 0 || triangle3 == 0)
		return (false);
	return (triangle1 + triangle2 + triangle3 == full_triangle);
}

void RunTest(int x, int y, const Point& a, const Point& b, const Point& c)
{
	Point check(x, y);
	bool part_of_triangle;

	std::cout << "\nChecking if x" << check.getX() << ", y" << check.getY() << " is part of the triangle.\n";
	part_of_triangle = BSP(a, b, c, check);
	PrintResultMessage(part_of_triangle);
}

int	main(void)
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	std::cout << std::endl;
	std::cout << "Triangle corner 1: x" << a.getX() << ", y" << a.getY() << std::endl;
	std::cout << "Triangle corner 2: x" << b.getX() << ", y" << b.getY() << std::endl;
	std::cout << "Triangle corner 3: x" << c.getX() << ", y" << c.getY() << std::endl;
	
	RunTest(0, 0, a, b, c);
	RunTest(0, 3, a, b, c);
	RunTest(-1, 0, a, b, c);
	RunTest(2, 2, a, b, c);
	RunTest(1, 2, a, b, c);
	RunTest(3, 1, a, b, c);
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
