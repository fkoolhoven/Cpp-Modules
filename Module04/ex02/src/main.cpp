/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:59:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/11 10:46:44 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << YELLOW BOLD "\nConstructors\n" OFF;
	Dog dog;
	Cat cat;
	// AAnimal abstract_animal;

	std::cout << YELLOW BOLD "\nMake sounds\n" OFF;
	dog.PureVirtualFunction();
	cat.PureVirtualFunction();
	dog.MakeSound();
	cat.MakeSound();

	std::cout << YELLOW BOLD "\nDestructors\n" OFF;
	return (EXIT_SUCCESS);
}