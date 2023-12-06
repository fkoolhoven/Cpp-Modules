/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:01:29 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 14:20:55 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << GREEN "WrongAnimal constructed\n" OFF;
	this->type = "no type";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	*this = src;
	std::cout << GREEN "WrongAnimal copy-constructed\n" OFF;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED "WrongAnimal destructed\n" OFF;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original)
{
	this->type = original.getType();
	return (*this);
}

void WrongAnimal::MakeSound(void) const
{
	std::cout << "WrongAnimal doesn't know which sound to make yet!\n";
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}