/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:01:31 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 14:19:54 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << GREEN "WrongCat constructed\n" OFF;
	this->type = "wrong cat";
}

WrongCat::WrongCat(const WrongCat& src)
{
	*this = src;
	std::cout << GREEN "WrongCat copy-constructed\n" OFF;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED "WrongCat destructed\n" OFF;
}

void WrongCat::MakeSound(void) const
{
	std::cout << "WrongCat goes meow\n";
}