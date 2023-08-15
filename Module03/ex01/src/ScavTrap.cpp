/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:15:19 by felicia           #+#    #+#             */
/*   Updated: 2023/08/15 19:22:35 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string init_name) : ClapTrap::ClapTrap(init_name)
{
	std::cout << GREEN"ScavTrap " << Name << " was constructed\n" << OFF;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED"ScavTrap " << Name << " was destructed\n" << OFF;
}

void	ScavTrap::attack(const std::string& target)
{
	std::string	p;

	if (EnergyPoints == 0)
	{
		std::cout << "Claptrap " << Name << " is out of energy points and can't attack!\n";
		return ;
	}
	else if (HitPoints < 1)
	{
		std::cout << "Claptrap " << Name << " is out of hit points and can't attack!\n";
		return ;
	}
	EnergyPoints--;
	std::cout << "Claptrap " << Name << " attacks " << target << "!\n";
	p = get_point_or_points(EnergyPoints);
	std::cout << "Claptrap " << Name << " now has " << EnergyPoints << " energy " << p << " left\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in gate keeper mode\n";
}