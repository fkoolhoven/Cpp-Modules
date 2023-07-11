/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:17:10 by felicia           #+#    #+#             */
/*   Updated: 2023/07/11 18:06:43 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string new_name)
{
	name = new_name;
	std::cout << GREEN"CONSTRUCTED ZOMBIE " << name << OFF << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << RED"DESTRUCTED ZOMBIE " << name << OFF << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << BOLD YELLOW << name << OFF": BraiiiiiiinnnzzzZ...\n";
}