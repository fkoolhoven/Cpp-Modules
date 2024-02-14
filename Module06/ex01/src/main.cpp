/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:10:54 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/14 17:32:11 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Data* InitializeData()
{
	Data *data = new Data;
	data->first_name = "Felicia";
	data->last_name = "Koolhoven";
	data->age = 26;
	return (data);
}

int main(void)
{
	Data *data = InitializeData();
	
	std::cout << YELLOW BOLD "\nData before serialization\n" OFF;
	std::cout << "first_name: " << data->first_name << std::endl;
	std::cout << "last_name: " << data->last_name << std::endl;
	std::cout << "age: " << data->age << std::endl << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	Data *data_ptr = Serializer::deserialize(raw);

	std::cout << YELLOW BOLD "Data after serialization and deserialization\n" OFF;
	std::cout << "first_name: " << data_ptr->first_name << std::endl;
	std::cout << "last_name: " << data_ptr->last_name << std::endl;
	std::cout << "age: " << data_ptr->age << std::endl << std::endl;
	delete data;
}