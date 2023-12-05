/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:06:58 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 12:26:45 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "dog";
	std::cout << GREEN "Dog constructed\n" OFF;
}

Dog::Dog(const Dog& src)
{
	*this = src;
	std::cout << GREEN "Dog copy-constructed\n" OFF;
}

Dog::~Dog(void)
{
	std::cout << RED "Dog destructed\n" OFF;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog goes woof\n";
}