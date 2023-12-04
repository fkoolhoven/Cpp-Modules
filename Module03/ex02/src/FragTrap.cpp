/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:02:19 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/04 17:20:26 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap::ClapTrap()
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << GREEN "Default FragTrap constructor was called\n" OFF;
}

FragTrap::FragTrap(std::string init_name) : ClapTrap::ClapTrap(init_name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << GREEN "FragTrap " << name << " was constructed\n" OFF;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap::ClapTrap(original)
{
	std::cout << GREEN "Copy of FragTrap " << original.name << " was constructed\n" OFF;
}

FragTrap& FragTrap::operator=(const FragTrap &original)
{
	std::cout << "FragTrap copy assignment operator called for " << this->name << std::endl;
	ClapTrap::operator=(original);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << RED "FragTrap " << name << " was destructed\n" OFF;
}

void FragTrap::HighFivesGuys(void)
{
	std::cout << "FragTrap " << name << " is asking for high fives\n";
}