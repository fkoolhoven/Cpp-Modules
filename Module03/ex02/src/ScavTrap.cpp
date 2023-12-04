/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:15:19 by felicia           #+#    #+#             */
/*   Updated: 2023/12/04 17:20:44 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap::ClapTrap()
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	guarding_gate = false;
	std::cout << GREEN "Default ScavTrap constructor was called\n" OFF;
}

ScavTrap::ScavTrap(std::string init_name) : ClapTrap::ClapTrap(init_name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	guarding_gate = false;
	std::cout << GREEN "ScavTrap " << name << " was constructed\n" OFF;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap::ClapTrap(original)
{
	std::cout << GREEN "ScavTrap copy constructor called for " << original.name << OFF << std::endl;
	*this = original;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &original)
{
	std::cout << "ScavTrap copy assignment operator called for " << this->name << std::endl;
	ClapTrap::operator=(original);
	guarding_gate = original.guarding_gate;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << RED "ScavTrap " << name << " was destructed\n" OFF;
}

void ScavTrap::Attack(const std::string& target)
{
	if (!this->CheckIfResourcesAvailable("attack"))
		return;
	energy_points--;
	std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage!\n";
	std::cout << "ScavTrap " << name << " now has " << energy_points << " energy " << GetPointOrPoints(energy_points) << " left\n";
}

void ScavTrap::GuardGate()
{
	if (guarding_gate)
	{
		std::cout << "ScavTrap " << name << " stops guarding the guarding_gate\n";
		guarding_gate = false;
	}
	else
	{
		std::cout << "ScavTrap " << name << " starts to guard the guarding_gate\n";
		guarding_gate = true;
	}
}