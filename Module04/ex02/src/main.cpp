/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:59:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 17:18:36 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << YELLOW BOLD "\nConstructors\n" OFF;
	AAnimal* dog = new Dog();
	// AAnimal example;

	std::cout << YELLOW BOLD "\nMake sounds\n" OFF;
	dog->MakeSound();

	std::cout << YELLOW BOLD "\nDestructors\n" OFF;
	delete dog;
	return (EXIT_SUCCESS);
}