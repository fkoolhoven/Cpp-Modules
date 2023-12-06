/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:04:32 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 14:35:19 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << GREEN "AAnimal constructed\n" OFF;
}

AAnimal::AAnimal(const AAnimal& src)
{
	std::cout << GREEN "AAnimal copy-constructed\n" OFF;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << RED "AAnimal destructed\n" OFF;
}

AAnimal& AAnimal::operator=(const AAnimal& original)
{
	this->type = original.getType();
	return (*this);
}

void AAnimal::MakeSound(void) const
{
	std::cout << "AAnimal doesn't know which sound to make yet!\n";
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}