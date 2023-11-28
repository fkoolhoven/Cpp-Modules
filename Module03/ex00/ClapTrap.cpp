/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:13:00 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/08/16 17:47:40 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
	std::cout << GREEN"Default constructor was called\n";
}

ClapTrap::ClapTrap(std::string init_name)
{
	Name = init_name;
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
	std::cout << GREEN"ClapTrap " << Name << " was constructed\n" << OFF;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	std::cout << GREEN"Copy of " << original.Name << " was constructed\n" << OFF;
	*this = original;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &original)
{
	this->Name = original.Name + "_copy";
	this->HitPoints = original.HitPoints;
	this->EnergyPoints = original.EnergyPoints;
	this->AttackDamage = original.AttackDamage;
	std::cout << GREEN"Copy assignment operator was called for " << this->Name << OFF << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << RED"ClapTrap " << Name << " was destructed\n" << OFF;
}

std::string	get_point_or_points(int amount)
{
	if (amount == 1)
		return ("point");
	else
		return("points");
}

void	ClapTrap::attack(const std::string& target)
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


void	ClapTrap::takeDamage(unsigned int amount)
{
	std::string	p;

	if (EnergyPoints == 0)
	{
		std::cout << "Claptrap " << Name << " is out of energy points and can't take any more damage!\n";
		return ;
	}
	else if (HitPoints < 1)
	{
		std::cout << "Claptrap " << Name << " is out of hit points and can't take any more damage!\n";
		return ;
	}
	p = get_point_or_points(amount);
	HitPoints -= amount;
	std::cout << "Claptrap " << Name << " takes " << amount << " " << p << " of damage!\n";
	p = get_point_or_points(HitPoints);
	std::cout << "Claptrap " << Name << " now has " << HitPoints << " hit " << p << " left!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::string	p;

	if (EnergyPoints == 0)
	{
		std::cout << "Claptrap " << Name << " is out of energy points and can't repair!\n";
		return ;
	}
	else if (HitPoints < 1)
	{
		std::cout << "Claptrap " << Name << " is out of hit points and can't repair!\n";
		return ;
	}
	HitPoints += amount;
	EnergyPoints--;
	p = get_point_or_points(amount);
	std::cout << "Claptrap " << Name << " repairs and gets back " << amount << " hit " << p << std::endl;
	p = get_point_or_points(HitPoints);
	std::cout << "Claptrap " << Name << " now has " << HitPoints << " hit " << p << std::endl;
	p = get_point_or_points(EnergyPoints);
	std::cout << "Claptrap " << Name << " now has " << EnergyPoints << " energy " << p << std::endl;
}
