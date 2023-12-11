/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:06:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/11 15:54:23 by fkoolhov         ###   ########.fr       */
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

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat copy assignment operator called\n";
	this->type = src.getType();
	*(this->brain) = *(src.brain); 
	return (*this);
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