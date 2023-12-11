/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:59:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/11 15:53:32 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void TestDeepCopy(void)
{
	std::cout << YELLOW BOLD "\nTest deep copy\n" OFF;
	Cat cat;
	cat.getBrain()->setIdea(0, "I wish I shared a brain with someone else!");
	Cat cat2(cat);
	cat2.getBrain()->setIdea(0, "I'm so happy I have my own brain!");
	Cat cat3;
	cat3 = cat2;
	cat3.getBrain()->setIdea(0, "Brain? What brain?");

	std::cout << "Cat thinks: " << cat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 thinks: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat3 thinks: " << cat3.getBrain()->getIdea(0) << std::endl;
}

void TestCopyConstructor(void)
{
	std::cout << YELLOW BOLD "\nTest copy constructor\n" OFF;
	Dog dog;
	dog.getBrain()->setIdea(0, "I wonder if this copies!");
	Dog dog2(dog);
	
	std::cout << "Dog thinks: " << dog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 thinks: " << dog2.getBrain()->getIdea(0) << std::endl;
}

void TestBrain(void)
{
	std::cout << YELLOW BOLD "\nTest brain\n" OFF;
	Dog dog;
	Cat cat;

	dog.getBrain()->setIdea(0, "I'm a dog!");
	cat.getBrain()->setIdea(0, "I'm a cat!");
	std::cout << "Dog thinks: " << dog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog thinks: " << dog.getBrain()->getIdea(1) << std::endl;
	std::cout << "Cat thinks: " << cat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat thinks: " << cat.getBrain()->getIdea(1) << std::endl;
}

void TestConstructorDestructor(void)
{
	std::cout << YELLOW BOLD "\nTest constructors and destructors\n" OFF;
	int amount_of_animals = 4;
	Animal* animals[amount_of_animals];
	for (int i = 0; i < amount_of_animals; i++)
		i % 2 == 0 ? animals[i] = new Dog() : animals[i] = new Cat();
	for (int i = 0; i < amount_of_animals; i++)
		delete animals[i];
}

int main(void)
{
	TestConstructorDestructor();
	TestBrain();
	TestCopyConstructor();
	TestDeepCopy();
	return (EXIT_SUCCESS);
}