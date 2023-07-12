/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:18:57 by felicia           #+#    #+#             */
/*   Updated: 2023/07/12 17:36:36 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string newType)
{
	weaponType = newType;
	std::cout << GREEN"CONSTRUCTED WEAPON\n" << OFF;
}

Weapon::~Weapon(void)
{
	std::cout << RED"DESTRUCTED WEAPON\n" << OFF;
}

std::string	&Weapon::getType(void)
{
	return (weaponType);
}

void	Weapon::setType(std::string newType)
{
	weaponType = newType;
}
