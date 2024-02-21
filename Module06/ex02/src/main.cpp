/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:51:40 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/21 18:30:33 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base *base = new Base();
	Base *one = Generate();
	Base *two = Generate();
	Base *three = Generate();
	std::cout << std::endl;

	std::cout << YELLOW BOLD "Identify from pointer" OFF << std::endl;
	IdentifyFromPointer(nullptr);
	IdentifyFromPointer(base);
	IdentifyFromPointer(one);
	IdentifyFromPointer(two);
	IdentifyFromPointer(three);
	std::cout << std::endl;

	std::cout << YELLOW BOLD "Identify from reference" OFF << std::endl;
	IdentifyFromPointer(nullptr);
	IdentifyFromReference(*base);
	IdentifyFromReference(*one);
	IdentifyFromReference(*two);
	IdentifyFromReference(*three);
	std::cout << std::endl;

	delete base;
	delete one;
	delete two;
	delete three;

	return (EXIT_SUCCESS);
}
