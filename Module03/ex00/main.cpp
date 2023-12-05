/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:12:57 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 11:01:32 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << YELLOW BOLD "\nDefault constructor and destructor\n" OFF;
	{
		ClapTrap NoName;
	}
	
	std::cout << YELLOW BOLD "\nName constructor and destructor\n" OFF;
	{
		ClapTrap BoJack("BoJack");
	}

	std::cout << YELLOW BOLD "\nCopy constructor and copy assignment operator\n" OFF;
	{
		ClapTrap Todd1("Todd");
		Todd1.setAttackDamage(15);
		ClapTrap Todd2(Todd1);
		ClapTrap Todd3;
		Todd3 = Todd2;

		std::cout << "Todd1's attack damage is " << Todd1.getAttackDamage() << std::endl;
		std::cout << "Todd2's attack damage is " << Todd2.getAttackDamage() << std::endl;
		std::cout << "Todd3's attack damage is " << Todd3.getAttackDamage() << std::endl;
	}

	std::cout << YELLOW BOLD "\nFight between Claptraps where Margot dies\n" OFF;
	{
		ClapTrap Beatrice("Beatrice");
		ClapTrap Margot("Margot");
	
		Beatrice.setAttackDamage(5);
		Beatrice.Attack("Margot");
		Margot.TakeDamage(Beatrice.getAttackDamage());
		Beatrice.Attack("Margot");
		Margot.TakeDamage(Beatrice.getAttackDamage());
		Margot.Attack("Beatrice");
	}

	std::cout << YELLOW BOLD "\nFight between Claptraps where Beatrice runs out of energy points\n" OFF;
	{
		ClapTrap Beatrice("Beatrice");
		ClapTrap Margot("Margot");
	
		Margot.setAttackDamage(9);
		Margot.Attack("Beatrice");
		Beatrice.TakeDamage(Margot.getAttackDamage());
		for (int i = 0; i <= Margot.getAttackDamage(); i++)
			Beatrice.BeRepaired(1);
		Beatrice.Attack("Margot");
		Beatrice.BeRepaired(1);

		std::cout << YELLOW BOLD "and Margot finishes the job...\n" OFF;
		Margot.Attack("Beatrice");
		Beatrice.TakeDamage(Margot.getAttackDamage());
		Margot.Attack("Beatrice");
		Beatrice.TakeDamage(Margot.getAttackDamage());
		Beatrice.Attack("Margot");
	}
	return (EXIT_SUCCESS);
}