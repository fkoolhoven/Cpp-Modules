/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:12:57 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 10:58:25 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << YELLOW BOLD "\nFragTrap default constructor + destructor\n" OFF;
	{
		FragTrap frag;
	}
	
	std::cout << YELLOW BOLD "\nFragTrap name constructor + high five function\n" OFF;
	{
		FragTrap Stan("Stan");

		Stan.HighFivesGuys();
	}

	std::cout << YELLOW BOLD "\nFragTrap copy constructor\n" OFF;
	{
		FragTrap Kyle1("Kyle");
		Kyle1.setAttackDamage(15);
		FragTrap Kyle2(Kyle1);
		
		std::cout << "Kyle1's attack damage is " << Kyle1.getAttackDamage() << std::endl;
		std::cout << "Kyle2's attack damage is " << Kyle2.getAttackDamage() << std::endl;
	}

	std::cout << YELLOW BOLD "\nFragTrap copy assignment operator (same as ClapTrap)\n" OFF;
	{
		FragTrap Ziggy1("Ziggy1");
		Ziggy1.setAttackDamage(15);
		FragTrap Ziggy2;
		Ziggy2 = Ziggy1;
		
		std::cout << "Ziggy1's attack damage is " << Ziggy1.getAttackDamage() << std::endl;
		std::cout << "Ziggy2's attack damage is " << Ziggy2.getAttackDamage() << std::endl;
	}

	std::cout << YELLOW BOLD "\nFight between ScavTrap and FragTrap\n" OFF;
	{
		ScavTrap	scavtrap("Scav");
		FragTrap	fragtrap("Frag");

		scavtrap.setAttackDamage(50);
		fragtrap.setAttackDamage(50);
		scavtrap.Attack("Frag");
		fragtrap.TakeDamage(scavtrap.getAttackDamage());
		fragtrap.BeRepaired(10);
		scavtrap.Attack("Frag");
		fragtrap.TakeDamage(scavtrap.getAttackDamage());
		scavtrap.Attack("Frag");
		fragtrap.TakeDamage(scavtrap.getAttackDamage());
	}
	return (EXIT_SUCCESS);
}