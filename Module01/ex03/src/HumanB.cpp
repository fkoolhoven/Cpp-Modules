/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:31:55 by felicia           #+#    #+#             */
/*   Updated: 2023/07/12 18:08:34 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string newName) : weapon(nullptr)
{
	name = newName;
	weapon = nullptr;
	std::cout << GREEN"CONSTRUCTED " << name << OFF << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << RED"DESTRUCTED " << name << OFF << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
} 
