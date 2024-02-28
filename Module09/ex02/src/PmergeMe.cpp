/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:50:50 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/28 18:01:25 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

		void SortVector(void);
		void SortList(void);


PmergeMe::PmergeMe(std::string input)
{
	std::cout << GREEN "PmergeMe created\n" OFF;
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
	std::cout << GREEN "PmergeMe copy created\n" OFF;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	this->vector = src.vector;
	this->list = src.list;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << RED "PmergeMe destroyed\n" OFF;
}

void PmergeMe::SortVector(void)
{
	// use Ford-Johnson algorithm
}

void P

