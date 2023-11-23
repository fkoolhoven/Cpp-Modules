/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:25:00 by felicia           #+#    #+#             */
/*   Updated: 2023/11/23 18:05:35 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << GREEN "CONSTRUCTED ZOMBIE" OFF << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << RED "DESTRUCTED ZOMBIE" OFF << std::endl;
}

void Zombie::setName(std::string new_name)
{
	name = new_name;	
}

void Zombie::announce(void)
{
	std::cout << BOLD YELLOW << name << OFF ": BraiiiiiiinnnzzzZ...\n";
}
