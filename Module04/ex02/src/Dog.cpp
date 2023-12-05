/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:06:58 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 17:23:48 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << GREEN "Dog constructed\n" OFF;
	this->type = "dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& src)
{
	*this = src;
	std::cout << GREEN "Dog copy-constructed\n" OFF;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << RED "Dog destructed\n" OFF;
}

void Dog::MakeSound(void) const
{
	std::cout << "Dog goes woof\n";
}

void Dog::PureVirtualFunction(void) const
{
	std::cout << "Overriden pure virtual function\n";
}