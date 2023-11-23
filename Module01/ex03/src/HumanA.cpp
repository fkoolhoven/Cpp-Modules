/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:28:04 by felicia           #+#    #+#             */
/*   Updated: 2023/11/23 18:05:15 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
	
HumanA::HumanA(std::string new_name, Weapon &new_weapon)
	: weapon(new_weapon)
{
	name = new_name;
	std::cout << GREEN "CONSTRUCTED " << name << OFF << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << RED "DESTRUCTED " << name << OFF << std::endl;
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with " << weapon.getType() << std::endl;
} 
