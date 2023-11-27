/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:31:55 by felicia           #+#    #+#             */
/*   Updated: 2023/11/27 13:30:40 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string new_name)
{
	name = new_name;
	weapon = nullptr;
	std::cout << GREEN"CONSTRUCTED " << name << OFF << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << RED"DESTRUCTED " << name << OFF << std::endl;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}

void HumanB::attack(void)
{
	if (weapon == nullptr)
		std::cout << name << " attacks with his bare fists because he doesn't have a weapon yet" << std::endl;
	else
		std::cout << name << " attacks with " << weapon->getType() << std::endl;
} 
