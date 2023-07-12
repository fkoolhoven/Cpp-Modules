/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:28:04 by felicia           #+#    #+#             */
/*   Updated: 2023/07/12 18:09:47 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
	
HumanA::HumanA(std::string newName, Weapon &newWeapon)
	: weapon(newWeapon)
{
	name = newName;
	std::cout << GREEN"CONSTRUCTED " << name << OFF << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << RED"DESTRUCTED " << name << OFF << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
} 
