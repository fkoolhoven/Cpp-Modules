/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:10:46 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/14 17:20:34 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Serializer created" << OFF << std::endl;
}

Serializer::~Serializer()
{
	std::cout << RED << "Serializer destroyed" << OFF << std::endl;
}

Serializer::Serializer(const Serializer& src)
{
	*this = src;	
}	

Serializer& Serializer::operator=(const Serializer& src)
{
	(void)src;
	return (*this);	
}	

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *data = reinterpret_cast<Data *>(raw);
	return (data);
}
