/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:12:57 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/04 17:28:17 by fkoolhov         ###   ########.fr       */
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

	std::cout << YELLOW BOLD "\nFragTrap copy assignment operator\n" OFF;
	{
		FragTrap Kenny1("Kenny1");
		Kenny1.setAttackDamage(15);
		FragTrap Kenny2;
		Kenny2 = Kenny1;
		
		std::cout << "Kenny1's attack damage is " << Kenny1.getAttackDamage() << std::endl;
		std::cout << "Kenny2's attack damage is " << Kenny2.getAttackDamage() << std::endl;
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