/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:06:58 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/11 15:57:06 by fkoolhov         ###   ########.fr       */
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
	std::cout << GREEN "Dog copy-constructed\n" OFF;
	this->type = src.getType();
	this->brain = new Brain(*src.getBrain());
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << RED "Dog destructed\n" OFF;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog copy assignment operator called\n";
	this->type = src.getType();
	*(this->brain) = *(src.brain); 
	return (*this);
}

Brain* Dog::getBrain(void) const
{
	return (this->brain);
}

void Dog::MakeSound(void) const
{
	std::cout << "Dog goes woof\n";
}

void Dog::PureVirtualFunction(void) const
{
	std::cout << "Dog has overridden pure virtual function ";
	std::cout << "because dog doesn't want to be abstract\n";
}