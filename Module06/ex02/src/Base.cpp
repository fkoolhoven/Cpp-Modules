/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:39:37 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/15 13:46:02 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
	// std::cout << GREEN "Base created" OFF << std::endl;
}

Base::~Base()
{
	// std::cout << RED "Base destroyed" OFF << std::endl;
}

#include <random>

Base* Generate(void)
{
	std::random_device random_number_seed;
	std::mt19937 mersenne_twister(random_number_seed());
	std::uniform_int_distribution<> distribution(0, 2);

	int random = distribution(mersenne_twister);

	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void IdentifyFromPointer(Base* pointer)
{
	if (dynamic_cast<A*>(pointer))
		std::cout << "Actual type: A\n";
	else if (dynamic_cast<B*>(pointer))
		std::cout << "Actual type: B\n";
	else if (dynamic_cast<C*>(pointer))
		std::cout << "Actual type: C\n";
	else
		std::cout << "Actual type: unknown\n";
}

void IdentifyFromReference(Base& reference)
{
    try 
	{
        (void)dynamic_cast<A&>(reference);
        std::cout << "Actual type: A\n";
    } 
	catch (std::bad_cast& exception) 
	{
		try 
		{
			(void)dynamic_cast<B&>(reference);
			std::cout << "Actual type: B\n";
		}
		catch (std::bad_cast& exception) 
		{
			try
			{
				(void)dynamic_cast<C&>(reference);
				std::cout << "Actual type: C\n";
			}
			catch(const std::exception& e)
			{
				std::cout << "An exception was caught! " << exception.what() << std::endl;
			}
		}
	}
}
