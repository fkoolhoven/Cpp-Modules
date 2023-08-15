/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:12:57 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/08/15 19:22:25 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

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

	std::cout << YELLOW"\nTEST ScavTrap basic test\n" << OFF;
	{
		ScavTrap	Princess("Princess");

		Princess.guardGate();
	}

	std::cout << YELLOW"\nTEST fight between ScavTrap and ClapTrap\n" << OFF;
	{
		ScavTrap	scavtrap("Scav");
		ClapTrap	claptrap("Clap");

		scavtrap.attack("Clap");
		claptrap.takeDamage(scavtrap.getAttackDamage());
		claptrap.attack("Scav");
		scavtrap.takeDamage(claptrap.getAttackDamage());
		scavtrap.beRepaired(10);
	}
}
