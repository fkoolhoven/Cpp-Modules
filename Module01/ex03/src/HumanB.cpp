/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:31:55 by felicia           #+#    #+#             */
/*   Updated: 2023/11/23 18:05:20 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) : weapon(nullptr)
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
	std::cout << name << " attacks with " << weapon->getType() << std::endl;
} 
