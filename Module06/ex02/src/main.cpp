/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:51:40 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/15 13:04:19 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base base;
	
	Base *one = Generate();
	Base *two = Generate();
	Base *three = Generate();
	std::cout << std::endl;

	std::cout << YELLOW BOLD "Identify from pointer" OFF << std::endl;
	IdentifyFromPointer(one);
	IdentifyFromPointer(two);
	IdentifyFromPointer(three);
	std::cout << std::endl;

	std::cout << YELLOW BOLD "Identify from reference" OFF << std::endl;
	IdentifyFromReference(*one);
	IdentifyFromReference(*two);
	IdentifyFromReference(*three);
	std::cout << std::endl;

	delete one;
	delete two;
	delete three;

	return (0);
}
