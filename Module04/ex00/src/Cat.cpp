/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:06:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 12:26:41 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "cat";
	std::cout << GREEN "Cat constructed\n" OFF;
}

Cat::Cat(const Cat& src)
{
	*this = src;
	std::cout << GREEN "Cat copy-constructed\n" OFF;
}

Cat::~Cat(void)
{
	std::cout << RED "Cat destructed\n" OFF;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat goes meow\n";
}