/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:12:57 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/04 16:54:34 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << YELLOW BOLD "\nScavTrap default constructor + destructor\n" OFF;
	{
		ScavTrap	scav;
	}
	
	std::cout << YELLOW BOLD "\nScavTrap name constructor + gate function\n" OFF;
	{
		ScavTrap	Princess("Princess");

		Princess.GuardGate();
		Princess.GuardGate();
		Princess.GuardGate();
	}

	std::cout << YELLOW BOLD "\nScavTrap copy constructor\n" OFF;
	{
		ScavTrap Lenny1("Lenny");
		Lenny1.setAttackDamage(15);
		Lenny1.GuardGate();
		ScavTrap Lenny2(Lenny1);
		std::cout << "Lenny1's attack damage is " << Lenny1.getAttackDamage() << std::endl;
		std::cout << "Lenny2's attack damage is " << Lenny2.getAttackDamage() << std::endl;
		Lenny1.GuardGate();
		Lenny2.GuardGate();
	}

	std::cout << YELLOW BOLD "\nScavTrap copy assignment operator\n" OFF;
	{
		ScavTrap Barry1("Barry1");
		Barry1.setAttackDamage(15);
		Barry1.GuardGate();
		ScavTrap Barry2 = Barry1;
		std::cout << "Barry1's attack damage is " << Barry1.getAttackDamage() << std::endl;
		std::cout << "Barry2's attack damage is " << Barry2.getAttackDamage() << std::endl;
		Barry1.GuardGate();
		Barry2.GuardGate();
	}

	std::cout << YELLOW BOLD "\nFight between ScavTrap and ClapTrap\n" OFF;
	{
		ScavTrap	scavtrap("Scav");
		ClapTrap	claptrap("Clap");

		scavtrap.setAttackDamage(5);
		claptrap.setAttackDamage(51);
		scavtrap.Attack("Clap");
		claptrap.TakeDamage(scavtrap.getAttackDamage());
		claptrap.Attack("Scav");
		scavtrap.TakeDamage(claptrap.getAttackDamage());
		scavtrap.BeRepaired(1);
		claptrap.Attack("Scav");
		scavtrap.TakeDamage(claptrap.getAttackDamage());
		scavtrap.BeRepaired(1);
	}
}