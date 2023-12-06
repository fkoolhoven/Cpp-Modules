/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:59:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/06 14:37:06 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void TestFailedPolymorphism(void)
{
	std::cout << YELLOW BOLD "\nExample of failed polymorphism\n" OFF;
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "WrongCat is type " << wrong_cat->getType() << std::endl;
	wrong_cat->MakeSound();
	delete wrong_cat;
}

void TestSuccessfulPolymorphism(void)
{
	std::cout << YELLOW BOLD "\nExample of successful polymorphism\n" OFF;
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	Cat cat2;
	Animal& stack_cat = cat2;

	std::cout << "Animal is type " << animal->getType() << std::endl;
	std::cout << "Dog is type " << dog->getType() << std::endl;
	std::cout << "Cat is type " << cat->getType() << std::endl;

	animal->MakeSound();
	cat->MakeSound();
	dog->MakeSound();
	stack_cat.MakeSound();

	delete animal;
	delete dog;
	delete cat;
}

void TestCopyConstructors(void)
{
	std::cout << YELLOW BOLD "\nCopy constructors\n" OFF;
	Animal animal;
	Cat cat;
	Dog dog;
	
	Animal animal2(animal);
	Cat cat2(cat);
	Dog dog2(dog);

	std::cout << "Animal is type " << animal.getType() << std::endl;
	std::cout << "Animal2 is type " << animal2.getType() << std::endl;
	std::cout << "Cat is type " << cat.getType() << std::endl;
	std::cout << "Cat2 is type " << cat2.getType() << std::endl;
	std::cout << "Dog is type " << dog.getType() << std::endl;
	std::cout << "Dog2 is type " << dog2.getType() << std::endl;
}

void TestDefaultConstructors(void)
{
	std::cout << YELLOW BOLD "\nDefault constructors\n" OFF;
	Animal animal;
	Cat cat;
	Dog dog;
}

int main(void)
{
	TestDefaultConstructors();
	TestCopyConstructors();
	TestSuccessfulPolymorphism();
	TestFailedPolymorphism();
	return (EXIT_SUCCESS);
}