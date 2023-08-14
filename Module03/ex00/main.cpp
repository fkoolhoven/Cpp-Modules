/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:12:57 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/08/14 17:22:27 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << YELLOW"\nTEST default constructor and destructor\n" << OFF;
	{
		ClapTrap	NoName;
	}
	
	std::cout << YELLOW"\nTEST name constructor and destructor\n" << OFF;
	{
		ClapTrap	BoJack("BoJack");
	}

	std::cout << YELLOW"\nTEST copy constructor and copy assignment operator\n" << OFF;
	{
		
		ClapTrap	Todd1("Todd");
		ClapTrap	Todd2(Todd1);
		ClapTrap	Todd3 = Todd2;
	}

	std::cout << YELLOW"\nTEST fight between Claptraps where Beatrice runs out of hit points\n" << OFF;
	{
		ClapTrap	Beatrice("Beatrice");
		ClapTrap	Margot("Margot");
	
		Beatrice.attack("Margot");
		Margot.takeDamage(1);
		Beatrice.attack("Margot");
		Margot.takeDamage(8);
		Beatrice.attack("Margot");
		Margot.takeDamage(1);
		Margot.beRepaired(1);
		Margot.beRepaired(3);
		Margot.attack("Beatrice");
		Beatrice.takeDamage(10);
		Beatrice.attack("Margot");
	}

	std::cout << YELLOW"\nTEST fight between Claptraps where Beatrice runs out of energy points\n" << OFF;
	{
		ClapTrap	Beatrice("Beatrice");
		ClapTrap	Margot("Margot");
	
		Beatrice.attack("Margot");
		Margot.takeDamage(1);
		Beatrice.attack("Margot");
		Margot.takeDamage(1);
		Beatrice.attack("Margot");
		Margot.takeDamage(1);
		Beatrice.attack("Margot");
		Margot.takeDamage(1);
		Beatrice.attack("Margot");
		Margot.takeDamage(1);
		Margot.attack("Beatrice");
		Beatrice.takeDamage(1);
		Margot.attack("Beatrice");
		Beatrice.takeDamage(1);
		Margot.attack("Beatrice");
		Beatrice.takeDamage(1);
		Margot.attack("Beatrice");
		Beatrice.takeDamage(1);
		Beatrice.beRepaired(1);
		Beatrice.beRepaired(1);
		Beatrice.beRepaired(1);
		Beatrice.beRepaired(1);
		Beatrice.beRepaired(1);
		Beatrice.attack("Margot");
	}
}
