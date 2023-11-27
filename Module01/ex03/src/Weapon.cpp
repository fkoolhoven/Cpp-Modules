/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:18:57 by felicia           #+#    #+#             */
/*   Updated: 2023/11/27 13:17:05 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string new_weapon_type)
{
	weapon_type = new_weapon_type;
	std::cout << GREEN"CONSTRUCTED WEAPON\n" << OFF;
}

Weapon::~Weapon(void)
{
	std::cout << RED"DESTRUCTED WEAPON\n" << OFF;
}

const std::string	&Weapon::getType(void)
{
	return (weapon_type);
}

void Weapon::setType(std::string newType)
{
	weapon_type = newType;
}
