/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:15:19 by felicia           #+#    #+#             */
/*   Updated: 2023/12/05 15:20:01 by fkoolhov         ###   ########.fr       */
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
	guarding_gate = original.guarding_gate;
	std::cout << GREEN "Copy of ScavTrap " << original.name << " was constructed\n" OFF;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &original)
{
	ClapTrap::operator=(original);
	guarding_gate = original.guarding_gate;
	std::cout << "ScavTrap copy assignment operator was called for " << this->name << std::endl;
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
	guarding_gate = !guarding_gate;
	std::string text = guarding_gate ? "starts" : "stops";
	std::cout << "ScavTrap " << name << " " << text << " guarding the gate\n";
}