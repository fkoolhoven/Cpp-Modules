/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:25:00 by felicia           #+#    #+#             */
/*   Updated: 2023/07/11 18:51:54 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << GREEN"CONSTRUCTED ZOMBIE " << OFF << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << RED"DESTRUCTED ZOMBIE " << OFF << std::endl;
}

void	Zombie::setName(std::string newName)
{
	name = newName;	
}

void	Zombie::announce(void)
{
	std::cout << BOLD YELLOW << name << OFF": BraiiiiiiinnnzzzZ...\n";
}
