/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:59:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 17:08:21 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << YELLOW BOLD "\nConstructors\n" OFF;
	Animal* animals[100];
	for (int i = 0; i < 100; i++)
		i % 2 == 0 ? animals[i] = new Dog() : animals[i] = new Cat();

	std::cout << YELLOW BOLD "\nMake sounds\n" OFF;
	for (int i = 0; i < 100; i++)
		animals[i]->MakeSound();

	// think of brain test

	std::cout << YELLOW BOLD "\nDestructors\n" OFF;
	for (int i = 0; i < 100; i++)
		delete animals[i];
	return (EXIT_SUCCESS);
}