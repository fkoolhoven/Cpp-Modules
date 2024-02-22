/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:10:54 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/22 18:39:24 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Data* InitializeData(void)
{
	Data *data = new Data;
	data->first_name = "Felicia";
	data->last_name = "Koolhoven";
	data->age = 26;
	return (data);
}

void TestUnintededUse(void)
{
	Data *data = InitializeData();
	
	std::cout << YELLOW BOLD "\nData before serialization\n" OFF;
	std::cout << "pointer: " << data << std::endl;
	std::cout << "first_name: " << data->first_name << std::endl;
	std::cout << "last_name: " << data->last_name << std::endl;
	std::cout << "age: " << data->age << std::endl << std::endl;

	// short raw = reinterpret_cast<short>(data); // this won't compile because of potential data loss
	short raw = reinterpret_cast<uintptr_t>(data);
	Data *data_ptr = Serializer::deserialize(raw);

	std::cout << YELLOW BOLD "Data after serialization and deserialization\n" OFF;
	std::cout << "pointer: " << data_ptr << std::endl;
	// std::cout << "first_name: " << data_ptr->first_name << std::endl; // this will segfault because of lost data
	delete data;
}

void TestIntendedUse(void)
{
	Data *data = InitializeData();
	
	std::cout << YELLOW BOLD "\nData before serialization\n" OFF;
	std::cout << "pointer: " << data << std::endl;
	std::cout << "first_name: " << data->first_name << std::endl;
	std::cout << "last_name: " << data->last_name << std::endl;
	std::cout << "age: " << data->age << std::endl << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	Data *data_ptr = Serializer::deserialize(raw);

	std::cout << YELLOW BOLD "Data after serialization and deserialization\n" OFF;
	std::cout << "pointer: " << data_ptr << std::endl;
	std::cout << "first_name: " << data_ptr->first_name << std::endl;
	std::cout << "last_name: " << data_ptr->last_name << std::endl;
	std::cout << "age: " << data_ptr->age << std::endl << std::endl;
	delete data;
}

int main(void)
{
	// Serializer serializer; // Won't compile because of private constructor
	
	std::cout << GREEN BOLD "\nProper use\n" OFF;
	TestIntendedUse();
	std::cout << RED BOLD "Wrong use\n" OFF;
	TestUnintededUse();
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}