/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:21:43 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 16:17:48 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain(void)
{
	std::cout << GREEN "Brain constructed\n" OFF;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Out of ideas!";
}

Brain::Brain(const Brain& src)
{
	std::cout << GREEN "Brain copy-constructed\n" OFF;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << RED "Brain destructed\n" OFF;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Brain copy assignment operator called\n";
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	this->ideas[i] = idea;
}