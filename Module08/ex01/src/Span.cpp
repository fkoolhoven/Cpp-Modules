/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:53:13 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/20 17:23:49 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int max_size)
{
	this->max_size = max_size;
	std::cout << GREEN "Span created" OFF << std::endl;
}

Span::Span(const Span& instance)
{
	*this = instance;
	std::cout << GREEN "Span copy created" OFF << std::endl;
}

Span& Span::operator=(const Span& instance)
{
	this->max_size = instance.max_size;
	this->vector_container = instance.vector_container;
	return *this;
}

Span::~Span()
{
	std::cout << RED "Span destroyed" OFF << std::endl;
}

void Span::AddNumber(int number)
{
	if (this->vector_container.size() == this->max_size)
		throw FullContainer();
	this->vector_container.push_back(number);
}

void Span::AddMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->vector_container.size() + std::distance(begin, end) > this->max_size)
		throw FullContainer();
	this->vector_container.insert(this->vector_container.end(), begin, end);
}

int Span::LongestSpan(void)
{
	if (this->vector_container.size() < 2)
		throw NoSpan();
	int max = *std::max_element(this->vector_container.begin(), this->vector_container.end());
	int min = *std::min_element(this->vector_container.begin(), this->vector_container.end());
	return (max - min);
}

int Span::ShortestSpan(void)
{
	if (this->vector_container.size() < 2)
		throw NoSpan();
	std::vector<int> copy = this->vector_container;
	std::sort(copy.begin(), copy.end());
	int shortest = copy[1] - copy[0];
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
	{
		if (it + 1 != copy.end())
		{
			if (*(it + 1) - *it < shortest)
				shortest = *(it + 1) - *it;
		}
	}
	return shortest;
}

const char* Span::FullContainer::what() const throw()
{
	return ("The container is full");
}

const char* Span::NoSpan::what() const throw()
{
	return ("No span to find");
}