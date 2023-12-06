/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:06:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 16:15:24 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << GREEN "Cat constructed\n" OFF;
	this->type = "cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& src)
{
	std::cout << GREEN "Cat copy-constructed\n" OFF;
	*this = src;
	this->brain = new Brain(*src.getBrain());
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << RED "Cat destructed\n" OFF;
}

Brain* Cat::getBrain(void) const
{
	return (this->brain);
}

void Cat::MakeSound(void) const
{
	std::cout << "Cat goes meow\n";
}

void Cat::PureVirtualFunction(void) const
{
	std::cout << "Cat has overridden pure virtual function ";
	std::cout << "because cat doesn't want to be abstract\n";
}