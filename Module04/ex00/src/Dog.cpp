/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:06:58 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 14:35:02 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << GREEN "Dog constructed\n" OFF;
	this->type = "dog";
}

Dog::Dog(const Dog& src)
{
	std::cout << GREEN "Dog copy-constructed\n" OFF;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << RED "Dog destructed\n" OFF;
}

void Dog::MakeSound(void) const
{
	std::cout << "Dog goes woof\n";
}