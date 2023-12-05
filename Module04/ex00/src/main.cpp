/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:59:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 12:41:28 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout << YELLOW BOLD "\nConstructors\n" OFF;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	Cat refCat;
	Animal& cat2 = refCat;

	std::cout << YELLOW BOLD "\nPolymorphism\n" OFF;
	std::cout << "Type of dog should be " << dog->getType() << std::endl;
	std::cout << "Type of cat should be " << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	cat2.makeSound();

	std::cout << YELLOW BOLD "\nDestructors\n" OFF;
	delete meta;
	delete dog;
	delete cat;
	return (EXIT_SUCCESS);
}