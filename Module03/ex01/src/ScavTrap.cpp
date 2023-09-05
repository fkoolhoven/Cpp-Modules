/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:15:19 by felicia           #+#    #+#             */
/*   Updated: 2023/08/16 17:54:38 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap::ClapTrap()
{
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << GREEN"Default ScavTrap constructor was called\n" << OFF;
}

ScavTrap::ScavTrap(std::string init_name) : ClapTrap::ClapTrap(init_name)
{
	std::cout << GREEN"ScavTrap " << Name << " was constructed\n" << OFF;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap::ClapTrap(original)
{
	std::cout << GREEN"ScavTrap copy constructor called for " << original.Name << OFF << std::endl;
	*this = original;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &original)
{
	std::cout << GREEN"ScavTrap copy assignment operator called for " << this->Name << OFF << std::endl;
	ClapTrap::operator=(original);
	return (*this);
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
	std::cout << "Claptrap " << Name << " attacks " << target << "! GO SCAV!\n";
	p = get_point_or_points(EnergyPoints);
	std::cout << "Claptrap " << Name << " now has " << EnergyPoints << " energy " << p << " left\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in gate keeper mode\n";
}