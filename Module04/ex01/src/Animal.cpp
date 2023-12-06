/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:04:32 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 15:29:53 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << GREEN "Animal constructed\n" OFF;
}

Animal::Animal(const Animal& src)
{
	std::cout << GREEN "Animal copy-constructed\n" OFF;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << RED "Animal destructed\n" OFF;
}

Animal& Animal::operator=(const Animal& src)
{
	this->type = src.getType();
	return (*this);
}

void Animal::MakeSound(void) const
{
	std::cout << "Animal doesn't know which sound to make yet!\n";
}

std::string	Animal::getType(void) const
{
	return (this->type);
}