/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:06:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 14:34:57 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << GREEN "Cat constructed\n" OFF;
	this->type = "cat";
}

Cat::Cat(const Cat& src)
{
	std::cout << GREEN "Cat copy-constructed\n" OFF;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << RED "Cat destructed\n" OFF;
}

void Cat::MakeSound(void) const
{
	std::cout << "Cat goes meow\n";
}