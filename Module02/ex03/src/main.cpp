/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:35:52 by felicia           #+#    #+#             */
/*   Updated: 2023/08/01 18:34:41 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

void	print_result_message(bool part_of_triangle)
{
	if (part_of_triangle)
		std::cout << GREEN"YES! Point is part of tiangle.\n" << OFF;
	else
		std::cout << RED"NO! Point is not part of triangle.\n" << OFF;
}

float calculate_triangle_surface(Point const &point1, Point const &point2, Point const &point3)
{
	float	surface;
	
	surface = 0.5 * std::abs(
        point1.getX().toFloat() * (point2.getY().toFloat() - point3.getY().toFloat()) +
        point2.getX().toFloat() * (point3.getY().toFloat() - point1.getY().toFloat()) +
        point3.getX().toFloat() * (point1.getY().toFloat() - point2.getY().toFloat()));
	return (surface);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	full_triangle;
	float	triangle1, triangle2, triangle3;

	full_triangle = calculate_triangle_surface(a, b, c);
	triangle1 = calculate_triangle_surface(point, b ,c);
	triangle2 = calculate_triangle_surface(a, point, c);
	triangle3 = calculate_triangle_surface(a, b, point);

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
	bool 	part_of_triangle;

	std::cout << a.getX() << " " << a.getY() << std::endl;
	std::cout << b.getX() << " " << b.getY() << std::endl;
	std::cout << c.getX() << " " << c.getY() << std::endl;

	Point	check(5, 2);
	part_of_triangle = bsp(a, b, c, check);
	print_result_message(part_of_triangle);
	check.setX(2); check.setY(2);
	part_of_triangle = bsp(a, b, c, check);
	print_result_message(part_of_triangle);
	check.setX(3); check.setY(1);
	part_of_triangle = bsp(a, b, c, check);
	print_result_message(part_of_triangle);
}
