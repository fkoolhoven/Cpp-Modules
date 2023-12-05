/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:13:00 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 10:33:16 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "nameless";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << GREEN "Default ClapTrap constructor was called\n" OFF;
}

ClapTrap::ClapTrap(std::string init_name)
{
	name = init_name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << GREEN "ClapTrap " << name << " was constructed\n" OFF;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	std::cout << GREEN "Copy of ClapTrap " << original.name << " was constructed\n" OFF;
	*this = original;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &original)
{
	this->name = original.name + "_copy";
	this->hit_points = original.hit_points;
	this->energy_points = original.energy_points;
	this->attack_damage = original.attack_damage;
	std::cout << "ClapTrap copy assignment operator was called for " << this->name << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << RED "ClapTrap " << name << " was destructed\n" OFF;
}

void ClapTrap::setAttackDamage(int amount)
{
	attack_damage = amount < 0 ? 0 : amount;
}

int ClapTrap::getAttackDamage()
{
	return (attack_damage);
}

std::string	ClapTrap::GetPointOrPoints(int amount)
{
	return (amount == 1 ? "point" : "points");
}

bool ClapTrap::CheckIfResourcesAvailable(std::string message)
{
	if (this->hit_points < 1)
	{
		std::cout << "Claptrap " << name << " is out of hit points (DIED) and can't " << message << "!\n";
		return (false);
	}
	else if (this->energy_points < 1)
	{
		std::cout << "Claptrap " << name << " is out of energy points and can't " << message << "!\n";
		return (false);
	}
	return (true);
}

void ClapTrap::Attack(const std::string& target)
{
	if (!this->CheckIfResourcesAvailable("attack"))
		return;
	energy_points--;
	std::cout << "Claptrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage!\n";
	std::cout << "Claptrap " << name << " now has " << energy_points << " energy " << GetPointOrPoints(energy_points) << " left\n";
}

void ClapTrap::TakeDamage(unsigned int amount)
{
	if (hit_points < 1)
	{
		std::cout << "Claptrap " << name << " is already dead!\n";
		return;
	}
	hit_points -= amount;
	if (hit_points < 0)
		hit_points = 0;
	std::cout << "Claptrap " << name << " takes " << amount << " points of damage!\n";
	if (hit_points <= 0)
		std::cout << "Claptrap " << name << " DIED!\n";
	else
		std::cout << "Claptrap " << name << " now has " << hit_points << " hit " << GetPointOrPoints(hit_points) << " left!\n";
}

void ClapTrap::BeRepaired(unsigned int amount)
{
	if (!this->CheckIfResourcesAvailable("be repaired"))
		return;
	hit_points += amount;
	energy_points--;
	std::cout << "Claptrap " << name << " repairs and gets back " << amount << " hit " << GetPointOrPoints(amount) << std::endl;
	std::cout << "Claptrap " << name << " now has " << hit_points << " hit " << GetPointOrPoints(hit_points) << std::endl;
	std::cout << "Claptrap " << name << " now has " << energy_points << " energy " << GetPointOrPoints(energy_points) << std::endl;
}