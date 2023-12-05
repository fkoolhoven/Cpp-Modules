/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:21:43 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 17:12:49 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "AAnimal.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "No idea yet!";
	std::cout << GREEN "Brain constucted\n" OFF;
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
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}